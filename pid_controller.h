#pragma once
#include <algorithm>

class PIDController {
 private:
  double Kp, Ki, Kd;
  double dt;
  double integral;
  double prev_error;
  double max_integral;

 public:
  PIDController(double kp, double ki, double kd, double timestep,
                double i_limit = 100.0);
  double compute(double setpoint, double measured);
  void reset();
};
