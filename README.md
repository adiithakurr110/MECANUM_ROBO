# MECAVISION – Autonomous Mecanum Robot

## About the Project

MECAVISION is an autonomous robot project focused on obstacle detection and navigation. It uses sensors to detect nearby obstacles and a mecanum-wheel drive system for movement in different directions. The project is being developed through circuit design and simulation before physical implementation.

## 1. Hardware Components

| Component                  | Purpose                                 |
| -------------------------- | --------------------------------------- |
| Arduino Mega 2560          | Main controller for sensors and motors  |
| ESP32                      | Additional processing and communication |
| RPLIDAR A1M8               | Scans the surroundings for navigation   |
| HC-SR04 Ultrasonic Sensors | Measures nearby obstacles               |
| BTS7960 Motor Drivers      | Controls the DC motors                  |
| Mecanum Wheels             | Allow movement in multiple directions   |
| MPU6050                    | Measures motion and orientation         |
| I2C LCD                    | Displays system information             |
| Buzzer and Emergency Stop  | Provides alerts and a safety stop       |

The planned power system uses a battery and voltage converters. Component voltage ratings and wiring should be checked before connecting the physical hardware.

## 2. Circuit and System Architecture

The circuit design connects the sensors, controllers, motor drivers and other components. The ultrasonic sensors detect nearby obstacles, while the RPLIDAR is intended to provide information about the surrounding area. The controller processes sensor readings and sends commands to the motor drivers.

**System flow:**

Sensors → Controller → Motor Drivers → Mecanum Wheel Movement

Circuit diagrams and connection details are included in the project files.

## 3. Simulation and Testing

The repository contains simulation and circuit design resources, including the Wokwi hardware design.

To get started:

1. Open the `wokiwi design(hardware)/` folder.
2. Review `diagram.json` and `sketch.ino`.
3. Open the circuit in Wokwi and check the available connections.
4. Run the simulation and test the functions supported by the current setup.

Simulation support depends on the components and code implemented in the selected environment. Not every hardware component may be fully simulated.

## 4. Proposed Physical Implementation

The planned robot will use a chassis fitted with four mecanum wheels and DC motors. The Arduino Mega will handle the main control tasks, while the motor drivers will control wheel movement. The ultrasonic sensors and RPLIDAR will provide obstacle and surroundings data. The MPU6050 will help monitor the robot's motion.

The battery and voltage converters will supply the required power to the system. All wiring, voltage levels and motor connections will need to be verified before powering the assembled robot.

## 5. Limitations and Future Work

The simulation helps test the circuit layout and the functions supported by the software, but it cannot fully reproduce real-world sensor behaviour, motor response, wheel traction or battery performance.

The next steps are to complete the hardware assembly, verify all connections, test each sensor and motor separately, and then test obstacle avoidance with the complete robot. Physical performance will need to be confirmed through actual testing.

## Project Files

* `Documentation/` – Project documentation
* `Simulations/` – Simulation resources
* `circuit diagram/` – Circuit diagrams
* `presentation/` – Presentation files
* `wokiwi design(hardware)/` – Wokwi design and code

---

**Project:** MECAVISION
**Repository:** MECANUM_ROBO
