# Simulation limitations

1. Wokwi code reads three HC-SR04 inputs and emits decision messages plus LED command patterns. LEDs do not simulate motor drivers or motor motion.
2. Current Wokwi subset does not include the ESP32 UART/Wi-Fi bridge, RPLIDAR, touchscreen, BTS7960 driver modules, motors, battery/buck converters, camera, YOLO, Whisper, IMU or encoders.
3. The Three.js scene is a 3D behavioral visualization with virtual rays and simplified obstacle collision checks; it is not physics-accurate and does not run the hardware firmware.
4. Mecanum wheel rollers are visual; true omni-directional kinematics, slip, encoders and motor currents are not modelled.
5. No physical prototype has been built or validated as part of these files. Record only tests actually run.
