#pragma once

#include "AbstractSensor.h"

class VoltageSensor : public AbstractSensor<float> {
 public:
  explicit VoltageSensor(int pin, float maxVoltage = 3.3f, int zeroVoltageAsInt = 0, int maxVoltageAsInt = 4095) : AbstractSensor(), pin(pin), maxVoltage(maxVoltage), zeroVoltageAsInt(zeroVoltageAsInt), maxVoltageAsInt(maxVoltageAsInt) {
  }

  virtual void setup() {
    pinMode(pin, INPUT);
  }

  virtual void loop() {
    int voltageAsInt = analogRead(pin);
    data = static_cast<float>(voltageAsInt - zeroVoltageAsInt) / static_cast<float>(maxVoltageAsInt - zeroVoltageAsInt) * maxVoltage;
    setNewDataFlag();
    LOG("Voltage: %f V (digital value %d)", data, voltageAsInt);
  }

 private:
  const int pin;
  const float maxVoltage;
  const int zeroVoltageAsInt;
  const int maxVoltageAsInt;
};
