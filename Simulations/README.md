# 🧊 MECAVISION Simulation Environments

This folder contains two standalone simulation environments designed to demonstrate the complete behavioral and physical functionality of the autonomous mecanum robot.

---

## 📁 Files Included
- `simulation-3d.html` / `simulation-2d.html`**: Production-grade 3D WebGL Digital Twin built with Three.js. Operates 100% offline with zero external network requests.
- `simulation-2d.html`**: Interactive 2D Canvas Physics Sandbox featuring real-time **click-and-drag dynamic obstacles**.

---

## 🌟 3D Digital Twin Features ([`simulation-3d.html`](simulation-3d.html))
- Accurate CAD Representation**: Matches the Fusion 360 design from Slide 1 with black aluminum 2020 extrusions, gold corner brackets, and 4 mecanum wheels with active 45° rollers.
- **Real-Time Sensor Overlays**:
  - 360° RPLiDAR scan points rendered in high-visibility neon green/red.
  - 3x Ultrasonic rangefinder rays with color-coded warning distances (Green > 42 cm, Amber 25–42 cm, Red < 25 cm).
  - Simulated 70° ESP32-CAM vision cone projecting forward.
- **HUD Overlays**:
  - **360° Circular Radar Scope** in bottom-left corner with real-time sweep beam and range rings.
  - **Simulated ESP32-CAM YOLO Viewfinder** in bottom-right corner displaying target tracking bounding box and confidence score (`[CHAIR: 0.94]`).
  - **Individual Motor Power Bars** showing live PWM % and FWD/REV status for all 4 BTS7960 drivers.
- **4 Camera Perspectives**: 3D Orbit, Chase Cam (third-person trailing), 2D Top-Down, and Robot FPV.
- **Interactive Controls**:
  - Click anywhere on the arena floor to dynamically move the target waypoint.
  - Keyboard teleoperation: `W`/`A`/`S`/`D` to drive & strafe, `Q`/`E` to rotate, `Space` for E-STOP.
  - Web Audio procedural sound synthesizer (motor hum, proximity beeps, arrival chime).

---

## 🗺️ 2D Interactive Sandbox Features ([`simulation-2d.html`](simulation-2d.html))
- **Live Drag-and-Drop**: Click and drag any crate or barrel in real time while the robot is navigating to verify dynamic obstacle avoidance and path recalculation.
- **High-DPI Display**: Clean rendering optimized for presentations and low-power hardware.

---

## 🚀 How to Run
Simply double-click `simulation-3d.html` or `simulation-2d.html` in your browser.  
No web server, node.js, or internet connection is required.
