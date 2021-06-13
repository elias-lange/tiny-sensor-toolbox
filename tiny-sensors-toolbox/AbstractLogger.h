#pragma once

class AbstractLogger {
 public:
  virtual void log(String msg) = 0;
};
