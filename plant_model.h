#pragma once

class ThermalSystem {
 private:
  double temperature;
  double ambient;
  double heat_transfer;
  double thermal_mass;
  double max_power;

 public:
  ThermalSystem(double initial, double ambient_temp);
  double update(double control_signal, double dt);
  double getTemperature() const;
  void setAmbient(double ambient_temp);
};
