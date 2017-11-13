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
  if(bot.buttonVals[0]){
    bot.clearOled();
    bot.oledWrite(0, 0, String(millis()));
  }
  delay(100);
}
