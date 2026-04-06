#include "pid_controller.h"

PIDController::PIDController(double kp, double ki, double kd,
                             double timestep, double i_limit)
    : Kp(kp), Ki(ki), Kd(kd), dt(timestep),
      integral(0.0), prev_error(0.0), max_integral(i_limit) {}

double PIDController::compute(double setpoint, double measured) {
  double error = setpoint - measured;

  // Proportional term
  double p = Kp * error;

  // Integral term with anti-windup
  integral += error * dt;
  integral = std::clamp(integral, -max_integral, max_integral);
  double i = Ki * integral;

  // Derivative term
  double derivative = (error - prev_error) / dt;
  double d = Kd * derivative;

  prev_error = error;
  return std::clamp(p + i + d, 0.0, 100.0);
}

void PIDController::reset() {
  integral = 0.0;
  prev_error = 0.0;
}
