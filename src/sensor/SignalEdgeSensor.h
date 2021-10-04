#pragma once

#include "AbstractSensor.h"

namespace SignalEdgeSensorImpl {

volatile int signalEdgeCount;

volatile unsigned long timeOfLastSignalEdge_ms = 0;

volatile unsigned long debouncePeriod_ms = 0;

void IRAM_ATTR onSignalEdge() {
  if (millis() > timeOfLastSignalEdge_ms + debouncePeriod_ms) {
    signalEdgeCount++;
    timeOfLastSignalEdge_ms = millis();
  }
}

}

class SignalEdgeSensor : public AbstractSensor<float> {
 public:
  explicit SignalEdgeSensor(int dataPin, float measurementPeriod = 1.0, float debouncePeriod = 0.001) : AbstractSensor(), dataPin(dataPin), measurementPeriod_ms(static_cast<int>(1000.0f * measurementPeriod)) {
    SignalEdgeSensorImpl::debouncePeriod_ms = static_cast<unsigned long>(1000.0f * debouncePeriod);
  }

  void startNewMeasurmentPeriod() {
    measurementStartTime_ms = millis();
    SignalEdgeSensorImpl::signalEdgeCount = 0;
  }

  virtual void setup() {
    pinMode(dataPin, INPUT);
    digitalWrite(dataPin, HIGH);
    attachInterrupt(dataPin, SignalEdgeSensorImpl::onSignalEdge, RISING);
    sei();
    startNewMeasurmentPeriod();
  }

  virtual void loop() {
    if (millis() > measurementStartTime_ms + measurementPeriod_ms) {
      unsigned long duration_ms = millis() - measurementStartTime_ms;
      int signalEdgeCount = SignalEdgeSensorImpl::signalEdgeCount;
      data = signalEdgeCount / (duration_ms / 1000.0f);
      setNewDataFlag();
      startNewMeasurmentPeriod();
      LOG("SignalEdgeSensor: %d signal edges in %lu ms, i.e. %.3f 1/s", signalEdgeCount, duration_ms, data);
    }
  }

 private:
  static volatile int signalEdgeCount;
  const int dataPin;
  const unsigned long measurementPeriod_ms;
  unsigned long measurementStartTime_ms = 0;
};
