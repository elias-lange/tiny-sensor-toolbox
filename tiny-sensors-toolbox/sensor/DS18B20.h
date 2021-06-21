#pragma once

#include "AbstractSensor.h"

class DS18B20 : public AbstractSensor {
 public:
  explicit DS18B20() : AbstractSensor() {

  }

  virtual void loop() {
    LOG("Nachricht vom %s.", "DS18B20");
  }
};
