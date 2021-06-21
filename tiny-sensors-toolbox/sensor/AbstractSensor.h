#pragma once

#include "../AbstractLogger.h"

class AbstractSensor {
 public:
  virtual void loop() = 0;
};
