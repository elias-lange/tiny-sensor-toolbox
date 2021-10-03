#include "tiny-sensor-toolbox.h"

SerialLogger logger;
LevelSensor levelSensor(14);
PeriodicTimer timer(20.0f);
ThingSpeakSender sender("MySSID", "MyWiFiPassword", "MyWriteAPIKey");

void setup() {
  logger.init(9600);
  SET_GLOBAL_LOGGER(&logger);
  levelSensor.setup();
  levelSensor.addLevel(33);
  levelSensor.addLevel(32);
  levelSensor.addLevel(35);
}

void loop() {
  if (timer.hasFired()) {
    levelSensor.loop();
    int l = levelSensor.getData();
    Serial.printf("The level is %d.\n", l);
    sender.sendMeasurement(String(l));
  }
}
