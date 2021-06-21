#include "SerialLogger.h"
#include "sensor/DS18B20.h"


SerialLogger logger;
DS18B20 temp1;

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
}

void loop() {
  temp1.loop();
  delay(1000);
}
