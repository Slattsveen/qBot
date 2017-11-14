/*
 * This is an example sketch for the qBot robot. 
 * Using the qBot PCB entails using a fixed Arduino pinout. The qBot library takes care of this pinout,
 * and also offers some functions in order to interface the various input and output capabilities it has.
 * 
 * ESSENTIAL:
 * Refer to the README.txt document for information on the various functions and variable names where sensor values are stored.
 * 
 * written by Kristoffer Slåttsveen
 * 2017 @NTNU - Norway
 * Published under the GNU General Public License v3 of June 29 2007.
 */

#import <qbot.h>

int xCoordinate = 5;
int yCoordinate = 10;
String message = "Hello, world!";

// Create an instance of the qBot class, name it whatever you like. I call it "bot".
QBot bot;

void setup() {
  //Initialize the qBot object, this wil take care of all Arduino pin definitions
  bot.start();
}

void loop() {
  //This is the loop, where most of the interesting stuff happens!

  // call any qBot function by calling it through the object. "bot.<function>"
  bot.oledWrite(xCoordinate, yCoordinate,message); 
}


