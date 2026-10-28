# MECAVISION – Vision-Based Autonomous Mecanum Robot

**Team:** Tech Minions

**Team Members:** Bhawna Singh, Aditya Singh, Harshit Vats

## Project Overview

MECAVISION is a proposed autonomous robot designed to detect obstacles and navigate toward a selected target. It uses four mecanum wheels for forward, backward, sideways, diagonal, and turning movements.

The project includes browser-based simulations and a Wokwi circuit design to test parts of the system before building the physical robot.

**Current Status:** The simulation files and circuit design are available in the repository. The physical robot has not yet been fully assembled and tested.

## 1. Hardware Components

The following components are planned for the physical prototype. Specifications should be verified against the exact components before assembly.

| S. No. | Component                     | Specifications                     | Purpose                                             |
| -----: | ----------------------------- | ---------------------------------- | --------------------------------------------------- |
|      1 | Arduino Mega 2560 Rev3        | 5V logic, ATmega2560, 16 MHz       | Main controller for sensors and motor control       |
|      2 | ESP32-WROOM-32D               | Wi-Fi, Bluetooth, UART             | Communication with the host computer                |
|      3 | RPLIDAR A1M8                  | 360° 2D scanning, UART             | Measures distances around the robot                 |
|      4 | HC-SR04 Ultrasonic Sensors ×3 | 5V, approximately 2–400 cm range   | Detects obstacles on the left, front, and right     |
|      5 | BTS7960 Motor Drivers ×4      | Motor supply typically 6–27V       | Controls the four drive motors                      |
|      6 | 12V Geared DC Motors ×4       | Planned nominal speed: 300 RPM     | Drives the wheels                                   |
|      7 | Mecanum Wheels ×4             | Planned diameter: 97 mm            | Enables sideways and diagonal movement              |
|      8 | MPU6050 IMU                   | Accelerometer and gyroscope, I²C   | Measures motion and orientation                     |
|      9 | 20×4 I²C LCD                  | 5V, planned address `0x27`         | Displays system status                              |
|     10 | Active Piezo Buzzer           | 5V                                 | Provides audible alerts                             |
|     11 | Emergency-Stop Button         | Normally closed contact planned    | Allows emergency stopping                           |
|     12 | 3S Li-ion Battery Pack        | 11.1V nominal, 12.6V fully charged | Main power source                                   |
|     13 | DC-DC Buck Converters ×2      | Regulated outputs planned          | Supplies suitable voltage to electronics and motors |

## 2. Circuit Connections and System Architecture

The Arduino Mega is intended to receive sensor readings, process obstacle information, and control the motors through the motor drivers. The ESP32 is intended to provide communication with a host computer.

### System Architecture

```text
        Ultrasonic Sensors
                |
             RPLIDAR
                |
                v
         Arduino Mega
                |
         Motor Drivers
                |
        Four DC Motors
                |
          Mecanum Wheels

      Host Computer
             ↕
            ESP32
             ↕
        Arduino Mega
```

### Arduino Mega Pin Connections

| Component                                 | Arduino Mega Connection                 |
| ----------------------------------------- | --------------------------------------- |
| Left, front, and right ultrasonic sensors | Digital pins 22–27                      |
| ESP32 serial communication                | UART1: TX1 pin 18, RX1 pin 19           |
| RPLIDAR serial communication              | UART2: TX2 pin 16, RX2 pin 17           |
| MPU6050 and I²C LCD                       | SDA pin 20, SCL pin 21                  |
| Front-left motor driver                   | PWM pin 2, direction pin 30             |
| Front-right motor driver                  | PWM pin 3, direction pin 31             |
| Rear-left motor driver                    | PWM pin 4, direction pin 32             |
| Rear-right motor driver                   | PWM pin 5, direction pin 33             |
| Buzzer                                    | Digital pin 8                           |
| Emergency-stop logic input                | Digital pin 48                          |
| Battery voltage monitoring                | Analog pin A0 through a voltage divider |

**Important:** These are the planned connections. Verify them against `sketch.ino` and `diagram.json` before assembling the circuit. Use suitable regulated power supplies and common ground connections where required. Never connect the battery directly to a 5V logic pin.

### Circuit Files

* `circuit diagram/` — Circuit diagrams and connection references.
* `wokiwi design(hardware)/diagram.json` — Wokwi circuit layout.
* `wokiwi design(hardware)/sketch.ino` — Arduino code for the Wokwi design.

## 3. Simulation Setup and Testing

### A. 3D Browser Simulation

**File:** `Simulations/simulation-3d.html` or `Simulations/index.html`

1. Open the HTML file in Chrome, Edge, Firefox, or another modern browser.

2. If the simulation does not load correctly, open a terminal in the `Simulations` folder.

3. Run:

   ```bash
   python -m http.server 8000
   ```

4. Open `http://localhost:8000/` in your browser.

5. Test the available movement controls, target movement, and obstacle-avoidance scenarios.

If the files use different names, open the actual HTML file present in your repository.

### B. 2D Browser Simulation

**File:** `Simulations/simulation-2d.html`

1. Open the HTML file in a browser.
2. Start the simulation.
3. Move the available obstacles.
4. Observe how the simulated robot responds to the obstacles.

### C. Wokwi Hardware Simulation

**Files:**

* `wokiwi design(hardware)/sketch.ino`
* `wokiwi design(hardware)/diagram.json`

**Steps:**

1. Open [Wokwi](https://wokwi.com/).
2. Create an Arduino Mega 2560 project.
3. Copy the contents of `sketch.ino` into the code editor.
4. Configure the circuit using `diagram.json`.
5. Start the simulation.
6. Open the Serial Monitor using the baud rate specified in the code.
7. Test the ultrasonic sensors at different distances.
8. Check the obstacle-detection response and emergency-stop input if these features are implemented in the current circuit.

Record the results that the simulation actually produces. The available features depend on the current code and the components supported by Wokwi.

## 4. Proposed Physical Implementation

The planned robot will use a rectangular chassis with four geared DC motors and mecanum wheels.

* **Chassis:** Supports the motors, wheels, battery, and electronic components.
* **Arduino Mega:** Processes sensor readings and manages basic movement control.
* **ESP32:** Provides communication with the host computer.
* **Ultrasonic sensors:** Detect nearby obstacles from different directions.
* **RPLIDAR:** Provides 360-degree distance measurements.
* **Motor drivers:** Control the four DC motors.
* **MPU6050:** Measures motion and orientation.
* **Battery and buck converters:** Supply suitable power to the system.
* **LCD and buzzer:** Display status and provide alerts.
* **Emergency stop:** Provides a way to stop the system.

The battery should be mounted securely, preferably low on the chassis. High-current motor wiring should be routed carefully, away from sensitive signal wiring where practical. The RPLIDAR should have a clear view around the robot.

Before testing the complete robot, verify the power system, test each motor and sensor individually, and confirm that the emergency stop works. Initial movement tests should be performed at low speed in a clear area.

## 5. Simulation Limitations and Future Work

The simulations represent only the behaviour implemented in their code. They do not fully reproduce real-world electrical and mechanical conditions.

**Current limitations:**

* Physical robot assembly and performance have not been fully verified.
* Wokwi may not support every component or reproduce its real electrical behaviour.
* Browser simulations cannot fully represent motor load, wheel traction, battery voltage drop, or sensor noise.
* Real-world obstacle avoidance depends on correct sensor integration, calibration, and control logic.
* RPLIDAR and computer-vision integration must be verified separately if they are not implemented in the current simulation.

**Next steps:**

1. Verify all component ratings and wiring connections.
2. Check power regulation and emergency-stop operation.
3. Test each motor and sensor separately.
4. Calibrate sensor readings and motor directions.
5. Integrate the components and test obstacle avoidance at low speed.
6. Compare physical robot behaviour with the simulation results.

## Repository Structure

```text
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
```

*Note: Folder and file names may differ slightly. Use the actual names shown in the repository.*
