# Hardware architecture based on supplied circuit image

- Arduino Mega 2560: intended main real-time controller.
- 3 × HC-SR04: left, front and right proximity sensing.
- RPLIDAR A1/A2: planned 2D scanning; not included in the current simulation.
- ESP32: intended Wi-Fi / UART communication; not integrated in the current Wokwi subset.
- 4 × BTS7960-class driver modules and 4 motors: proposed mecanum drive; LEDs in Wokwi only indicate commands.
- Touch display: proposed UI; not simulated.
- 3S Li-ion battery and buck converters: planned power distribution; not electrically simulated.

Proposed flow: sensors -> Mega safety/decision logic -> wheel command outputs -> motor drivers -> four mecanum wheels. ESP32 provides communications; the PC vision/voice layer may supply a target command. Verify exact wiring, driver count, current ratings, voltage levels and pin mappings against the final bill of materials and datasheets.
