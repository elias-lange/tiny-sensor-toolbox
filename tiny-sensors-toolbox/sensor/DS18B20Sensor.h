#pragma once

#include <OneWire.h> 
#include <DallasTemperature.h>

#include "AbstractSensor.h"

class DS18B20Sensor : public AbstractSensor<float> {
 public:
  explicit DS18B20Sensor(int dataPin) : AbstractSensor(), dataPin(dataPin), oneWire(dataPin), sensor(&oneWire) {
  }

  void setup() {
    sensor.begin();
  }

  virtual void loop() {
    sensor.requestTemperatures(); 
    data = sensor.getTempCByIndex(0);
    LOG("DS18B20: %.2f°C", data);
    setNewDataFlag();
  }

 private:
  const int dataPin;
  OneWire oneWire; 
  DallasTemperature sensor;
};
