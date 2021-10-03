#include "tiny-sensor-toolbox.h"


SerialLogger logger;
// SignalEdgeSensor s1(4);
// VoltageSensor s1(4);
LevelSensor s1(14);

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
  s1.setup();
  s1.addLevel(33);
  s1.addLevel(32);
  s1.addLevel(35);
}

void loop() {
  s1.loop();
  if (s1.hasNewData()) {
    int l = s1.getData();
    Serial.printf("The level is %d.\n", l);
    delay(1000);
  }
}
