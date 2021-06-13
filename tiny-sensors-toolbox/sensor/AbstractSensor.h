#pragma once

class AbstractLogger;

class AbstractSensor {
 public:
  explicit AbstractSensor(AbstractLogger *logger)
  : logger_(logger) {
    // Nothing to do.
  }

  virtual void loop() = 0;

 protected:
  AbstractLogger *logger_;
};