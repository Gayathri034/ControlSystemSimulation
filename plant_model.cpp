#include "plant_model.h"

ThermalSystem::ThermalSystem(double initial, double ambient_temp)
    : temperature(initial), ambient(ambient_temp),
      heat_transfer(0.1), thermal_mass(1.0), max_power(100.0) {}

double ThermalSystem::update(double control_signal, double dt) {
  double heat_in = (control_signal / 100.0) * max_power;
  double heat_loss = heat_transfer * (temperature - ambient);
  temperature += (heat_in - heat_loss) * dt / thermal_mass;
  return temperature;
}

double ThermalSystem::getTemperature() const { return temperature; }
void ThermalSystem::setAmbient(double ambient_temp) { ambient = ambient_temp; }
