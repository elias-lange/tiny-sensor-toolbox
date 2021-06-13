#include "SerialLogger.h"
#include "sensor/DS18B20.h"


SerialLogger logger;
DS18B20 temp1(&logger);

void setup() {
  logger.init(9600);
}

void loop() {
  temp1.loop();
  delay(1000);
}
