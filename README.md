# My EEE + Embedded Systems Projects

Hi , I'm **Jahnavi Gayathri Lakshmisetti** — an Electrical and Electronics Engineering graduate and current **MS Computer Science** student interested in embedded and real‑time software for vehicle control systems.

This repository showcases two C++ projects that connect control‑system fundamentals with software engineering practice:

---

##  1. Control System Simulation and Implementation

**Goal:**  
Model a closed‑loop feedback controller (PID) in C++, simulating how an automotive ECU stabilizes a physical variable such as temperature or speed.

**Highlights:**
- PID controller class implementing proportional, integral, and derivative terms.
- Anti‑windup protection for integral term.
- Thermal plant model that emulates heating/cooling dynamics.
- CSV logging for step and disturbance response visualization.
- Demonstration of stability, overshoot, and steady‑state tuning in software.

**To run:**
```bash
cd ControlSystemSimulation
g++ -std=c++17 pid_controller.cpp plant_model.cpp main.cpp -o pid_sim
./pid_sim
