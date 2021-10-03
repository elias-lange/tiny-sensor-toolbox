#pragma once

#include "AbstractLogger.h"

class SerialLogger : public AbstractLogger {
 public:
  void init(int rate) {
    Serial.begin(rate);
  }
  
  virtual void log(String msg) { 
    Serial.print("["); Serial.print(millis()); Serial.print("] "); Serial.print(msg); Serial.println(); 
  }
};
