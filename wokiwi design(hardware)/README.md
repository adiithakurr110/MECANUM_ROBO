# 🔌 Wokwi Hardware-in-the-Loop (HIL) Simulation Guide

This folder contains the complete microcontroller firmware and circuit schematic for **MECAVISION**, mapped 1-to-1 to the hardware architecture presented in Slide 4 of the PPT.

---

## 📁 Files Included
- **`sketch.ino`**: Clean, deterministic Arduino Mega 2560 firmware implementing 4-wheel mecanum inverse kinematics, 3x HC-SR04 ultrasonic rangefinding, 20x4 I2C LCD telemetry, warning buzzer, and hardware emergency stop (E-STOP).
- **`diagram.json`**: Wokwi circuit layout with all modules, sensors, indicators, and power rails wired.

---

## ⚡ Hardware Pin Mapping

| Subsystem | Component | Mega Pin | Function |
|---|---|:---:|---|
| **Ultrasonic Left** | HC-SR04 | `TRIG: 22`, `ECHO: 23` | Left blind-spot obstacle detection |
| **Ultrasonic Front** | HC-SR04 | `TRIG: 24`, `ECHO: 25` | Forward corridor safety reflex |
| **Ultrasonic Right** | HC-SR04 | `TRIG: 26`, `ECHO: 27` | Right blind-spot obstacle detection |
| **Motor 1 (Front Left)** | BTS7960 Driver | `PWM: 2`, `DIR: 30` | FL speed & direction (Blue + Green LEDs) |
| **Motor 2 (Front Right)** | BTS7960 Driver | `PWM: 3`, `DIR: 31` | FR speed & direction (Blue + Green LEDs) |
| **Motor 3 (Rear Left)** | BTS7960 Driver | `PWM: 4`, `DIR: 32` | RL speed & direction (Blue + Green LEDs) |
| **Motor 4 (Rear Right)** | BTS7960 Driver | `PWM: 5`, `DIR: 33` | RR speed & direction (Blue + Green LEDs) |
| **I2C Bus** | 20x4 LCD & MPU6050 | `SDA: 20`, `SCL: 21` | Telemetry display (`0x27`) and IMU (`0x68`) |
| **Safety Alarm** | Active Piezo Buzzer | `Pin 8` | Audible obstacle / reflex alarm |
| **Hardware E-STOP** | Pushbutton (Red) | `Pin 48` | Low-level hardware kill switch |
| **Battery Sensing** | Voltage Divider | `Pin A0` | 3S Li-ion battery voltage measurement |

---

## 🚀 How to Run on Wokwi
1. Open [https://wokwi.com](https://wokwi.com) in your browser.
2. Click **"New Project"** → Select **"Arduino Mega 2560"**.
3. In the code tab, replace all code with [`sketch.ino`](sketch.ino).
4. In the `diagram.json` tab, replace all text with [`diagram.json`](diagram.json).
5. Click the green **Play (▶)** button.
6. Open the **Serial Monitor** at **9600 baud**.

---

## 🧪 Interactive Test Matrix

1. **Forward Cruising**: Set all three sensor distance sliders to 100 cm.  
   *Expected Output*: LCD shows `State: FORWARD`, all 4 motor blue LEDs light up with PWM forward.
2. **Obstacle Avoidance (Slide Left)**: Set Front sensor to 35 cm, Left to 100 cm, Right to 30 cm.  
   *Expected Output*: Buzzer beeps (50 ms), LCD shows `State: TURN LEFT`, robot commands mecanum left bias.
3. **Emergency Braking (<25 cm)**: Push the Front slider below 25 cm (e.g., 18 cm).  
   *Expected Output*: Buzzer sounds, LCD shows `State: STOP TOO CLOSE`, all motor PWM LEDs immediately turn OFF.
4. **Hardware E-STOP**: Click the red E-STOP button.  
   *Expected Output*: Instant motor shutdown, LCD shows `State: E-STOP`.
