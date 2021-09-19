#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>

#include "AbstractSensor.h"

class DS18B20Sensor : public AbstractSensor<float> {
 public:
  explicit DS18B20Sensor(int dataPin) : AbstractSensor(), dataPin(dataPin), oneWire(dataPin), sensor(&oneWire) {
  }

  virtual void setup() {
    sensor.begin();
  }

  virtual void loop() {
    sensor.requestTemperatures();
    data = sensor.getTempCByIndex(0);
    setNewDataFlag();
    LOG("DS18B20: %.2f°C", data);
  }

 private:
  const int dataPin;
  OneWire oneWire;
  DallasTemperature sensor;
};
