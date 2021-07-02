#pragma once

#include "AbstractSensor.h"

namespace FlowSensorImpl {

int volatile ticks;

void IRAM_ATTR countTick() {
  ticks++;
}

}

class FlowSensor : public AbstractSensor<float> {
 public:
  explicit FlowSensor(int dataPin, float measurementPeriod = 1.0) : AbstractSensor(), dataPin(dataPin), measurementPeriod(static_cast<int>(1000.0f * measurementPeriod)) {
  }

  void startNewMeasurmentPeriod() {
    measurementStartTime = millis();
    FlowSensorImpl::ticks = 0;
  }

  void setup() {
    pinMode(dataPin, INPUT);
    digitalWrite(dataPin, HIGH);
    attachInterrupt(dataPin, FlowSensorImpl::countTick, RISING);
    sei();
    startNewMeasurmentPeriod();
  }

  virtual void loop() {
    if (millis() > measurementStartTime + measurementPeriod) {
      unsigned long duration = millis() - measurementStartTime;
      int ticks = FlowSensorImpl::ticks;
      data = ticks / (duration / 1000.0f);
      setNewDataFlag();
      startNewMeasurmentPeriod();
      LOG("FlowSensor: %d ticks in %lu ms, i.e. %.3f rps", ticks, duration, data);
    }
  }

 private:
  static volatile int ticks;
  const int dataPin;
  const unsigned long measurementPeriod;
  unsigned long measurementStartTime = 0;
};
