#include "SerialLogger.h"
// #include "sensor/DS18B20Sensor.h"
#include "sensor/VoltageSensor.h"


SerialLogger logger;
VoltageSensor temp1(4);

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
//  temp1.setup();
}

void loop() {
  temp1.loop();
  delay(1000);
}
