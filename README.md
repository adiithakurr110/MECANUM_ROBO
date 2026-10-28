MECAVISION – Vision-Based Autonomous Mecanum Robot

Team: Tech Minions
Team members: Bhawna Singh, Aditya Singh, Harshit Vats

Project Overview

MECAVISION is a proposed mobile robot designed to detect obstacles and navigate toward a selected target. Four mecanum wheels are planned to support forward, backward, sideways and turning movement. Browser simulations and a Wokwi circuit are used to test parts of the design before building the physical robot.

Current status: The simulations and circuit design are available in the repository. The physical robot has not yet been fully assembled and tested, so real-world performance is not confirmed.

1. Hardware Components

The following parts are planned for the physical prototype. Check the exact ratings and datasheets of the parts available before wiring them.

Component

Main specification

Purpose

Arduino Mega 2560 Rev3

5 V, ATmega2560, 16 MHz

Main motion and safety controller

ESP32-WROOM-32D

Wi-Fi/Bluetooth, UART communication

Passes commands and status data

Slamtec RPLiDAR A1M8

360° 2D scanning, UART

Measures distances around the robot

3 × HC-SR04

5 V, approx. 2–400 cm range

Close-range obstacle detection

4 × BTS7960 motor drivers

6–27 V motor supply, 5 V logic

Controls the four drive motors

4 × 12 V geared DC motors with encoders

300 RPM nominal (planned)

Drives the wheels

4 × 97 mm mecanum wheels

Two left-hand and two right-hand wheels

Allows sideways and diagonal movement

MPU6050

3-axis gyro and accelerometer, I²C

Measures motion and orientation

20×4 I²C LCD

5 V, address planned as 0x27

Displays system status

Active piezo buzzer

5 V

Gives obstacle alerts

Emergency-stop button

Normally closed contact planned

Provides a manual stop

3S Li-ion battery and DC-DC converters

11.1 V nominal battery; regulated logic supply planned

Powers motors and electronics

2. Circuit Connections and System Architecture

The planned system sends sensor readings to the Arduino Mega. The controller uses the readings to decide whether to move, turn or stop, then sends control signals to the motor drivers. The ESP32 is intended to provide communication with a host computer. The RPLiDAR and computer-vision functions depend on their actual integration and are not all represented by the Wokwi circuit.

System flow:
Sensors → Arduino Mega → Motor drivers → Four mecanum motors
Host computer ↔ ESP32 ↔ Arduino Mega

Main Arduino Mega pin map

Signal / component

Mega connection

Left, front and right HC-SR04 sensors

Digital pins 22–27 (trigger/echo pairs)

ESP32 serial connection

UART1: pins 18 (TX1) and 19 (RX1)

RPLiDAR serial connection

UART2: pins 16 (TX2) and 17 (RX2)

MPU6050 and I²C LCD

SDA pin 20, SCL pin 21

Front-left motor driver

PWM pin 2, direction pin 30

Front-right motor driver

PWM pin 3, direction pin 31

Rear-left motor driver

PWM pin 4, direction pin 32

Rear-right motor driver

PWM pin 5, direction pin 33

Buzzer

Pin 8

Emergency-stop logic input

Pin 48

Battery voltage sense

A0 through a voltage divider

These are the planned connections from the project design. Verify them against sketch.ino and diagram.json before assembling the hardware. Use a suitable regulated supply and a common ground where required. Do not connect the battery directly to 5 V logic pins.

Circuit and architecture files

circuit diagram/ — circuit images and connection references, if present.

wokiwi design(hardware)/diagram.json — Wokwi circuit layout.

wokiwi design(hardware)/sketch.ino — Arduino code for the Wokwi design.

3. How to Run and Test the Simulations

A. 3D browser simulation

File: Simulations/simulation-3d.html (or Simulations/index.html)

Open the HTML file in Chrome, Edge, Firefox or another modern browser.

If it does not load correctly, open a terminal in the Simulations folder and run:

python -m http.server 8000

Visit http://localhost:8000/ in your browser.

Try the target movement, manual drive controls (W, A, S, D) and obstacle-avoidance scenarios provided by the simulation.

B. 2D browser simulation

File: Simulations/simulation-2d.html

Open the file in a browser.

Run the simulation and move the available obstacles to observe how the simulated robot responds.

C. Wokwi circuit

Files: wokiwi design(hardware)/sketch.ino and wokiwi design(hardware)/diagram.json

Open Wokwi and create an Arduino Mega 2560 project.

Copy the contents of sketch.ino into the code editor.

Replace the circuit diagram with the contents of diagram.json.

Start the simulation and open the Serial Monitor at the baud rate set in the sketch.

Test the three ultrasonic sensor inputs at clear distances, near an obstacle, and at the stop threshold. Also test the emergency-stop input if it is implemented in the current diagram.

Use the outputs actually shown by the current simulation as the test result; expected behaviour can vary with the code and components supported by Wokwi.

4. Proposed Physical Implementation

The planned build uses a rectangular chassis with four geared DC motors and mecanum wheels. The battery is intended to sit low on the chassis, with motor drivers near the motors. The Arduino Mega, ESP32, IMU and LCD will be mounted separately from high-current motor wiring where practical. The RPLiDAR should be mounted high enough to get a clear view around the robot, and the ultrasonic sensors should face left, front and right.

The Arduino is intended to manage wheel control and basic obstacle-stop behaviour. The ESP32 is intended to handle communication with the host computer. Before a full test, assemble and check the power system, test each sensor and motor separately, verify the emergency stop, and then test movement at low speed.

5. Limitations and Next Steps

The browser simulations demonstrate only the behaviours implemented in their code. Wokwi may not reproduce every physical component or its real electrical behaviour. Simulations cannot fully account for wheel traction, motor load, battery voltage drop, sensor noise, wiring errors or calibration.

Next steps:

Verify component ratings, pin assignments and wiring.

Test the power supply and emergency stop before running the motors.

Test each sensor and motor individually.

Calibrate the sensors and motor directions.

Test obstacle detection and movement with the complete physical robot.

Repository Structure

MECANUM_ROBO/
├── README.md
├── Documentation/
├── Simulations/
│   ├── simulation-3d.html
│   └── simulation-2d.html
├── circuit diagram/
├── presentation/
└── wokiwi design(hardware)/
    ├── sketch.ino
    └── diagram.json
