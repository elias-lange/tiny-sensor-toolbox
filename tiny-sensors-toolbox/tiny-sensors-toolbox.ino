#include "SerialLogger.h"
// #include "sensor/DS18B20Sensor.h"
// #include "sensor/VoltageSensor.h"
#include "sensor/FlowSensor.h"


SerialLogger logger;
FlowSensor temp1(4);

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
  temp1.setup();
}

void loop() {
  temp1.loop();
  if (temp1.hasNewData()) {
    float c = temp1.getData();
    Serial.printf("The temperature is %.2f°C.\n", c);
    delay(1000);
  }
}
