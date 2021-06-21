#pragma once

#include "AbstractSensor.h"

class VoltageSensor : public AbstractSensor {
 public:
  explicit VoltageSensor(int pin) : AbstractSensor(), pin(pin) {
  }

  void setup() {

  }

  virtual void loop() {
    int voltage = analogRead(pin);
    LOG("Voltage [digital value]: %d", voltage);
  }

 private:
  const int pin;
};
