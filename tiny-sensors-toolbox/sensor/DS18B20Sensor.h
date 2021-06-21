#pragma once

#include <OneWire.h> 
#include <DallasTemperature.h>

#include "AbstractSensor.h"

class DS18B20Sensor : public AbstractSensor {
 public:
  explicit DS18B20Sensor(int pin) : AbstractSensor(), dataPin(pin), oneWire(pin), dallasTemperature(&oneWire) {
  }

  void setup() {
    dallasTemperature.begin();
  }

  virtual void loop() {
    dallasTemperature.requestTemperatures(); 
    float temperature = dallasTemperature.getTempCByIndex(0);
    LOG("DS18B20: %f", temperature);
  }

 private:
  const int dataPin;
  OneWire oneWire; 
  DallasTemperature dallasTemperature;
};
