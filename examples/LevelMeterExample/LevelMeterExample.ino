#include "tiny-sensor-toolbox.h"

SerialLogger logger;
LevelSensor levelSensor(14);

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
  levelSensor.setup();
  levelSensor.addLevel(33);
  levelSensor.addLevel(32);
  levelSensor.addLevel(35);
}

void loop() {
  levelSensor.loop();
  if (levelSensor.hasNewData()) {
    int l = levelSensor.getData();
    Serial.printf("The level is %d.\n", l);
    delay(1000);
  }
}
