#pragma once

class AbstractLogger {
 public:
  virtual void log(String msg) = 0;
};


AbstractLogger* globalLogger = nullptr;

void SET_GLOBAL_LOGGER(AbstractLogger* logger) {  
  globalLogger = logger;
}

AbstractLogger* GET_GLOBAL_LOGGER() {  
  return globalLogger;
}

#define LOG(...) { char buffer[1024]; sprintf(buffer, __VA_ARGS__); if (globalLogger != nullptr) { globalLogger->log(buffer); } }
