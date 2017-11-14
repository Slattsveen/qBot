/*
	qBot library header file
	Written by Kristoffer Slåttsveen
	14.11.2017
	
	Published under the GNU General Public License v3 of June 29 2007.
*/

#ifndef qBot_h
#define qBot_h

#include "Arduino.h"

//global funcgtions
/*
void ISR1();
void ISR2();
volatile bool* button1Pressed = false;
volatile bool* button2Pressed = false;
*/

class QBot{
	public:
	// Functions
	QBot();
	void start();
	void updateSensors();
	void printSensors();
	void oledWrite(int x, int y, String message);
	void clearOled();
	
		// Motor control functions
	void motorStop();
	void motor1(int speed);  // motor control with speed control, int sign defines direction
	void motor2(int speed);
	
	// Variables
		// Sensor storage
	unsigned short* reflVals;
	unsigned short lightVal = 0;
	bool reedVal = false;
	bool* buttonVals;
	unsigned short ax, ay, az;  // accelerometer values
	unsigned short gx, gy, gz;	// gyroscope values
	unsigned short distVal = 300;

	// Sensor pins
	const char reflSens[3] = {A2, A3, A4};
	const char lightSens = A0;
	const char reedSens = A1;
	const char buttons[2] = {0, 1};
		// Output pins
	#define LED1 9 
	#define LED2 13 
	
	private:
	
	// Pins
		// Sensor pins
	#define TRIGGER_PIN 4
	#define ECHO_PIN 7
	#define MAX_DIST 300   //value for maximum distance sensor setup, all above will return 0
	

	#define MOTOR1_A 5  
	#define MOTOR1_B 6
	#define MOTOR2_A 11  
	#define MOTOR2_B 12
};

#endif