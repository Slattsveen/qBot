#include "qbot.h"

QBot bot;

volatile bool button2val = false;
int counter1 = 0;

void setup() {
  Serial.begin(9600);
  bot.start();
  attachInterrupt(2, IRS1, RISING);
  attachInterrupt(3, IRS2, RISING);
}

void loop() {
  bot.updateSensors();
  // bot.printSensors();

  switch (counter) {
    case 0:
      bot.clearOled();
      bot.oledWrite(0, 10, "Press a button to change mode");
      break;
    case 1:
      bot.clearOled();
      bot.oledWrite(10, 10, "Light");
      bot.oledWrite(10, 20, String(bot.lightVal));
      break;
    case 2:
      bot.clearOled();
      bot.oledWrite(10, 10, "Distance");
      bot.oledWrite(10, 20, String(bot.distVal));
      break;
    case 3:
      bot.clearOled();
      bot.oledWrite(10, 10, "Forward");
      bot.forward(128);
      break;
  }

}
void IRS1() {
  counter += 1;
  if (counter > 4) {
    counter = 0;
  }
}
void IRS2() {
  button2val = true;
}

