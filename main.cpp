#include <fstream>
#include <iostream>
#include "pid_controller.h"
#include "plant_model.h"

int main() {
  double setpoint = 50.0;
  double dt = 0.1;
  double sim_time = 60.0;

  PIDController pid(2.0, 0.5, 1.0, dt);
  ThermalSystem plant(25.0, 20.0);

  std::ofstream log("pid_log.csv");
  log << "time,setpoint,temperature,control\n";

  for (double t = 0; t < sim_time; t += dt) {
    double temp = plant.getTemperature();
    double control = pid.compute(setpoint, temp);
    plant.update(control, dt);
    log << t << "," << setpoint << "," << temp << "," << control << "\n";

    // simulate ambient disturbance
    if (t > 30.0 && t < 30.1) plant.setAmbient(10.0);
  }

  log.close();
  std::cout << "Simulation complete. Data logged to pid_log.csv\n";
  return 0;
}
