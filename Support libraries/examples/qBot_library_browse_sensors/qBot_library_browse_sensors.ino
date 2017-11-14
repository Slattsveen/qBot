#include "qbot.h"

QBot bot;
volatile bool buttonval = false;

void setup() {
  Serial.begin(9600);
  bot.start();
//  attachInterrupt(0, IRS, RISING);
}

void loop() {
  bot.updateSensors();
  bot.printSensors();
  delay(100);
  if(bot.buttonVals[1]){
    bot.clearOled();
    bot.oledWrite(0, 0, String(millis()));
  }
  delay(100);
}

