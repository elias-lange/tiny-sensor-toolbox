#pragma once

#include "AbstractSensor.h"

class DS18B20 : public AbstractSensor {
 public:
  explicit DS18B20(AbstractLogger *logger) : AbstractSensor(logger) {

  }

  virtual void loop() {
    logger_->log("Nachricht vom DS18B20.");
  }
};