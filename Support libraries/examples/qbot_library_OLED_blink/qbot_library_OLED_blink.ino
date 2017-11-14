#include "qbot.h"

QBot bot;

void setup() {
  // put your setup code here, to run once:
  bot.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  bot.clearOled();
  bot.oledWrite(50, 10, "ON");
  delay(1000);
  bot.clearOled();
  bot.oledWrite(50, 10, "OFF");
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1000);
}
