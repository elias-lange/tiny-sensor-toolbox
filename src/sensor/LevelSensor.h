#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>

#include "AbstractSensor.h"

class LevelSensor : public AbstractSensor<int> {
 public:
  explicit LevelSensor(int outputPin) : AbstractSensor(), outputPin(outputPin) {
  }

  void addLevel(int pin) {
    if (levels < MAX_LEVELS) {
      inputPins[levels] = pin;
      pinMode(pin, INPUT);
      ++levels;
    }
  }

  virtual void setup() {
    pinMode(outputPin, OUTPUT);
  }

  virtual void loop() {
    digitalWrite(outputPin, HIGH);
    int level = 0;
    while (level < levels) {
      int pin = inputPins[level];
      int voltage = analogRead(pin);
      if (voltage < 100) {
        break;
      }
      ++level;
    }
    digitalWrite(outputPin, LOW);
    data = level;
    setNewDataFlag();
    LOG("Level: %d", data);
  }

 private:
  const int outputPin;
  static const int MAX_LEVELS = 10;
  int levels = 0;
  int inputPins[MAX_LEVELS] = { -1 };
};