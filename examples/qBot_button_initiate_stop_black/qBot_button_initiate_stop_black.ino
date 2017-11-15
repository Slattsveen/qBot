/*
   This is an example sketch for the qBot robot.
   Using the qBot PCB entails using a fixed Arduino pinout. The qBot library takes care of this pinout,
   and also offers some functions in order to interface the various input and output capabilities it has.

   ESSENTIAL:
   Refer to the README.txt document for information on the various functions and variable names where sensor values are stored.

   written by Kristoffer Slåttsveen
   2017 @NTNU - Norway
   Published under the GNU General Public License v3 of June 29 2007.
*/

#import <qbot.h>

// Create an instance of the qBot class, name it whatever you like. I call it "bot".
QBot bot;

void setup() {
  //Initialize the qBot object, this wil take care of all Arduino pin definitions
  bot.start();
  bot.updateSensors();
  delay(1000);
  while (bot.buttonVals[0] != 1) {
    bot.updateSensors();
  }
  bot.clearOled();
  bot.oledWrite(2, 2, "Running");
  delay(800);
}

void loop() {
  //This is the loop, where most of the interesting stuff happens!

  //bot.updateSensors();
  for (int i = 0; i < 2; i++) {
    unsigned short val = analogRead(bot.reflSens[i]);
    if (val < 800) { // threshold value of the reflection sensor is set at 800, white paper gives ~1000
      bot.reflVals[i] = 0;
    } else {
      bot.reflVals[i] = 1;
    }
  }
  bot.clearOled();
  bot.oledWrite(10, 5, String(bot.reflVals[1]));
  bot.oledWrite(80, 5, String(bot.reflVals[0]));
  // motor control loop
  if (bot.reflVals[0] == 0 || bot.reflVals[1] == 0) {
    bot.motorStop();
    delay(200);
  } else {
    //forward
    bot.motor1(-80); // left motor
    bot.motor2(-190); // right motor
    // backwards
    //bot.motor1(-200); // left motor
    //bot.motor2(200); // right motor
  }

}


