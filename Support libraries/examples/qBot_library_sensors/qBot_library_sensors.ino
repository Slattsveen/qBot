#include "qbot.h"

QBot bot;

void setup() {
  Serial.begin(9600);
  bot.start();
}

void loop() {
  bot.updateSensors();
  bot.printSensors();
  delay(100);
}
