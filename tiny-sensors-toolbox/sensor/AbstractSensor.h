#pragma once

#include "../AbstractLogger.h"

template<typename T>
class AbstractSensor {
 public:
  virtual void loop() = 0;

  boolean hasNewData() const {
    return newDataFlag;
  }

  void resetNewDataFlag() {
    newDataFlag = false;
  }

  const T& getData(bool resetNewDataFlag = true) {
      if (resetNewDataFlag) {
        newDataFlag = false;
      }
      return data;
    }

 protected:
   T data = T();

  void setNewDataFlag() {
    newDataFlag = true;
  }

 private:
  bool newDataFlag = false;
};
