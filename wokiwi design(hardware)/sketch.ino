#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int trigL = 22, echoL = 23;
const int trigF = 24, echoF = 25;
const int trigR = 26, echoR = 27;

const int pwmFL = 2, pwmFR = 3, pwmRL = 4, pwmRR = 5;
const int dirFL = 30, dirFR = 31, dirRL = 32, dirRR = 33;

const int buzzer = 8;
const int eStop = 48;
const int stopDistance = 25;
const int avoidDistance = 42;

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long time = pulseIn(echoPin, HIGH, 30000UL);
  if (time == 0) return 400;
  return time / 58;
}

void stopRobot() {
  analogWrite(pwmFL, 0);
  analogWrite(pwmFR, 0);
  analogWrite(pwmRL, 0);
  analogWrite(pwmRR, 0);
}

void setWheels(float forward, float sideways, float turn) {
  float wheel[4] = {
    forward - sideways + turn,
    forward + sideways - turn,
    forward + sideways + turn,
    forward - sideways - turn
  };

  int pwmPins[4] = {pwmFL, pwmFR, pwmRL, pwmRR};
  int dirPins[4] = {dirFL, dirFR, dirRL, dirRR};
  float maxValue = 1.0;

  for (int i = 0; i < 4; i++) {
    if (abs(wheel[i]) > maxValue) maxValue = abs(wheel[i]);
  }

  for (int i = 0; i < 4; i++) {
    wheel[i] = wheel[i] / maxValue;
    digitalWrite(dirPins[i], wheel[i] >= 0 ? HIGH : LOW);
    analogWrite(pwmPins[i], abs(wheel[i]) * 255);
  }
}

void showStatus(const char *state, long left, long front, long right) {
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" cm | Front: ");
  Serial.print(front);
  Serial.print(" cm | Right: ");
  Serial.print(right);
  Serial.print(" cm | State: ");
  Serial.println(state);

  lcd.setCursor(0, 0);
  lcd.print("MECAVISION ROBOT   ");

  lcd.setCursor(0, 1);
  lcd.print("State:             ");
  lcd.setCursor(7, 1);
  lcd.print(state);

  lcd.setCursor(0, 2);
  lcd.print("L:"); lcd.print(left);
  lcd.print(" F:"); lcd.print(front);
  lcd.print(" R:"); lcd.print(right);
  lcd.print("   ");

  lcd.setCursor(0, 3);
  lcd.print("STOP<25cm | AUTO   ");
}

void setup() {
  Serial.begin(9600);

  pinMode(trigL, OUTPUT); pinMode(echoL, INPUT);
  pinMode(trigF, OUTPUT); pinMode(echoF, INPUT);
  pinMode(trigR, OUTPUT); pinMode(echoR, INPUT);

  pinMode(pwmFL, OUTPUT); pinMode(pwmFR, OUTPUT);
  pinMode(pwmRL, OUTPUT); pinMode(pwmRR, OUTPUT);
  pinMode(dirFL, OUTPUT); pinMode(dirFR, OUTPUT);
  pinMode(dirRL, OUTPUT); pinMode(dirRR, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(eStop, INPUT_PULLUP);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("MECAVISION ROBOT");
  lcd.setCursor(0, 1);
  lcd.print("System Starting...");
  lcd.setCursor(0, 2);
  lcd.print("Sensors: 3");
  lcd.setCursor(0, 3);
  lcd.print("Please Wait");

  stopRobot();
  digitalWrite(buzzer, LOW);
  delay(1000);

  Serial.println("MECAVISION ready!");
  Serial.println("Clear path = FORWARD");
  Serial.println("Obstacle = TURN");
  Serial.println("Front under 25 cm = STOP");
}

void loop() {
  if (digitalRead(eStop) == LOW) {
    stopRobot();
    showStatus("E-STOP", 0, 0, 0);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(200);
    return;
  }

  long left = getDistance(trigL, echoL);
  long front = getDistance(trigF, echoF);
  long right = getDistance(trigR, echoR);

  if (front < stopDistance) {
    stopRobot();
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    showStatus("STOP TOO CLOSE", left, front, right);
  } else if (front < avoidDistance) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);

    if (left < stopDistance && right < stopDistance) {
      stopRobot();
      showStatus("BLOCKED - STOP", left, front, right);
    } else if (left > right) {
      setWheels(0.1, 0.65, 0);
      showStatus("TURN LEFT", left, front, right);
    } else {
      setWheels(0.1, -0.65, 0);
      showStatus("TURN RIGHT", left, front, right);
    }
  } else if (left < stopDistance) {
    setWheels(0.5, -0.25, 0);
    showStatus("AVOID LEFT WALL", left, front, right);
  } else if (right < stopDistance) {
    setWheels(0.5, 0.25, 0);
    showStatus("AVOID RIGHT WALL", left, front, right);
  } else {
    setWheels(0.65, 0, 0);
    showStatus("FORWARD", left, front, right);
  }

  delay(250);
}
