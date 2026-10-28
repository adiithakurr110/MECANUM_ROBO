## Team

* **Team Name:** Tech Minions
* **Event:** Hack in Hills 2026
* **Problem Statement:** Problem Statement 01 — Vision-Based Autonomous Robot

### Team Members

* **Bhawna Singh** — Perception & Computer Vision
* **Aditya Singh** — Embedded Systems & Hardware Integration
* **Harshit Vats** — Kinematics, Trajectory & Control

---

## Circuit Diagrams, Connections and System Architecture

### 1. System Architecture

The proposed MECAVISION robot combines perception, embedded control, obstacle detection, and mecanum-wheel movement. The Arduino Mega acts as the main controller, while the ESP32 is intended to provide communication with the host computer.

```text
                 ┌────────────────────────┐
                 │     Host Computer      │
                 │ Vision / Communication│
                 └───────────┬────────────┘
                             │
                 ┌───────────▼────────────┐
                 │         ESP32          │
                 │ Communication Interface│
                 └───────────┬────────────┘
                             │ UART
                 ┌───────────▼────────────┐
                 │      Arduino Mega      │
                 │   Main Control Unit    │
                 └───────────┬────────────┘
                             │
          ┌──────────────────┼───────────────────┐
          │                  │                   │
   ┌──────▼──────┐   ┌───────▼────────┐   ┌──────▼──────┐
   │ Ultrasonic  │   │    RPLIDAR     │   │   MPU6050   │
   │ Sensors ×3  │   │  360° Scanning │   │     IMU     │
   └─────────────┘   └────────────────┘   └─────────────┘
                             │
                 ┌───────────▼────────────┐
                 │   4 × BTS7960 Drivers  │
                 └───────────┬────────────┘
                             │
                 ┌───────────▼────────────┐
                 │   4 × DC Gear Motors   │
                 │    Mecanum Wheels      │
                 └────────────────────────┘
```

**System workflow:**

1. Ultrasonic sensors detect nearby obstacles.
2. RPLIDAR provides surrounding distance measurements.
3. The Arduino Mega processes sensor information and manages motor commands.
4. The ESP32 provides the planned communication link with the host computer.
5. Motor drivers control the four DC motors.
6. The mecanum wheels enable forward, backward, sideways, diagonal, and rotational movement.

*Note: This diagram represents the proposed architecture. Actual functionality depends on the implemented code and verified hardware connections.*

### 2. Circuit Connections

The following table lists the planned connections between the Arduino Mega and the main components.

| Component                | Arduino Mega Pin      | Connection / Function                          |
| ------------------------ | --------------------- | ---------------------------------------------- |
| Left ultrasonic sensor   | Pins 22–23            | Trigger and Echo                               |
| Front ultrasonic sensor  | Pins 24–25            | Trigger and Echo                               |
| Right ultrasonic sensor  | Pins 26–27            | Trigger and Echo                               |
| ESP32                    | TX1: 18, RX1: 19      | UART communication                             |
| RPLIDAR                  | TX2: 16, RX2: 17      | UART communication                             |
| MPU6050                  | SDA: 20, SCL: 21      | I²C communication                              |
| 20×4 I²C LCD             | SDA: 20, SCL: 21      | I²C display                                    |
| Front-left motor driver  | PWM: 2, Direction: 30 | Motor control                                  |
| Front-right motor driver | PWM: 3, Direction: 31 | Motor control                                  |
| Rear-left motor driver   | PWM: 4, Direction: 32 | Motor control                                  |
| Rear-right motor driver  | PWM: 5, Direction: 33 | Motor control                                  |
| Buzzer                   | Digital pin 8         | Audible warning                                |
| Emergency-stop input     | Digital pin 48        | Stop-control input                             |
| Battery voltage sensing  | Analog pin A0         | Voltage measurement through a suitable divider |

**Connection notes:**

* The three ultrasonic sensors use six signal pins in total: three Trigger pins and three Echo pins.
* The MPU6050 and I²C LCD share the I²C bus, subject to compatible addresses and wiring.
* The ESP32 and RPLIDAR use separate hardware serial interfaces on the Arduino Mega.
* Each motor is controlled through its own motor driver.
* The battery supplies the motor power system, while suitable DC-DC converters provide regulated voltages for the electronics.
* All required grounds must be connected appropriately.
* Check voltage levels before connecting the ESP32, RPLIDAR, or other serial devices. Use suitable level shifting where required.

**Important:** These are planned pin assignments. Confirm the exact pins and driver wiring against `sketch.ino` and `diagram.json` before physical assembly.

### 3. Circuit Diagram Files

The repository contains the circuit and simulation resources:

| File / Folder                          | Purpose                                    |
| -------------------------------------- | ------------------------------------------ |
| `circuit diagram/`                     | Circuit diagrams and connection references |
| `wokiwi design(hardware)/diagram.json` | Wokwi circuit layout                       |
| `wokiwi design(hardware)/sketch.ino`   | Arduino simulation code                    |

To inspect the Wokwi circuit, open the project on [Wokwi](https://wokwi.com/) and check the component placement, wiring, and pin assignments against the Arduino code.

### 4. Power System

The proposed power system consists of a 3S Li-ion battery pack and two DC-DC buck converters.

```text
       ┌───────────────────┐
       │ 3S Li-ion Battery │
       │ 11.1V Nominal     │
       └─────────┬─────────┘
                 │
        ┌────────▼────────┐
        │ Power Distribution│
        └───────┬────────┘
                │
       ┌────────┴───────────┐
       │                    │
┌──────▼────────┐  ┌────────▼────────┐
│ Motor Drivers │  │ DC-DC Converters│
│ 4 × BTS7960   │  │ Regulated Supply│
└──────┬────────┘  └────────┬────────┘
       │                    │
┌──────▼────────┐  ┌────────▼────────┐
│ 4 DC Motors   │  │ Control & Sensor│
│               │  │ Electronics     │
└───────────────┘  └─────────────────┘
```

The final power distribution must be designed around the actual component voltage and current requirements. Include appropriate fusing, secure battery mounting, and an effective emergency-stop arrangement before testing the physical robot.
