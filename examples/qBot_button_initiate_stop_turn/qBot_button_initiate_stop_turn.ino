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

int modes = 0; // state variable used in the switch-state loop
/*
   mode 0 = stationary
   mode 1 = running forward
   mode 2 = turning backwards some random time between 300 and 1500 ms
*/

void setup() {
  //Initialize the qBot object, this wil take care of all Arduino pin definitions
  bot.start();
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
  bot.updateSensors();
  switch (modes) {
    case 0:
      while (bot.buttonVals[0] != 1) {
        bot.updateSensors();
      }
      modes = 1;
      break;
    case 1:
      if (bot.reflVals[0] == 0 || bot.reflVals[1] == 0) {
        bot.motorStop();
        modes = 2;
        delay(200);
      } else {
        //forward
        bot.motor1(-80); // left motor
        bot.motor2(-190); // right motor
      }
      break;
    case 2:
      int delayTime = random(300, 1500);
      bot.motor2(150); // right motor
      delay(delayTime);
      bot.motorStop();
      modes = 1;
      break;

  }

}


