This is the qBot library, it contains pin allocations and some predefined functions to make the qBot - Arduino project work. 

The qBot library requires the following libraries installed, they are included in this zip-file. Make sure to move or copy the support libraries to the "libraries" directory:
"Adafruit_GFX"		-	Library manager
"Adafruit_SSD1306"	-	Library manager
"I2Cdev"		-	Library manager?  possibly online, find link
"MPU6050"		-	Library manager?  possibly online, find link
"NewPing"		-	Library manager?  possibly online, find link

Please have a look at www.qbot.no for more information about projects, how to build it and so on.The qBot has the following sensors on board:
- Sonic distance sensor - HC-SR04
- Reed switch
- 6 axis IMU, accelerometer and gyroscope. The chip is named MPU6050
- 2 x pushbuttons
- 3 x IR-reflective sensors - two facing down, one facing forward.

Additional features:
- H-bridge motor controller
- 0.96" OLED screen - 128x64 pixles
- NRF24L01+ RF-transciever - not supported in the qBot library yet, can be used with separate code. See "Trollbot" on github. CE = 8, CS = 10. Otherwise use SPI pins on the Arduino Micro.

qBot sensor variable names, all are updated by calling the "updateSensors()" function:

	unsigned short reflVals[3];			// values from the three IR reflective sensors
	unsigned short lightVal;			// value from the light sensor
	bool reedVal;					// state of the reed switch (true/false)
	bool buttonVals[2];				// state of the buttons (true/false)
	unsigned short ax, ay, az;  			// accelerometer values
	unsigned short gx, gy, gz;			// gyroscope values
	unsigned short distVal;				// measurement from distance sensor in cm

qBot sensor pin names, sensors can be read manually by calling for example analogRead(qBot.reflSens[0]):
	const char reflSens[3];				// can be read digital or analog
	const char lightSens;				// can be read digital or analog
	const char reedSensA1;				// can be read digital or analog
	const char buttons[2];				// Can be attached to interrupt 2 and 3


qBot functions:

	QBot(); 					// constructor
	void start();					// run in the setup loop
	void updateSensors();				// updates all sensor values
	void printSensors();				// Serial print of all sensor values
	void oledWrite(int x, int y, String message);	// write something on the OLED screen in position (x, y). (0, 0) is in the top left of the screen.
	void clearOled();				// empty the OLED screen

// Motor control functions, fairly self-explanatory

	void motor1(int speed /*-255 : 255*/); 			// control the two motors individually, by changing the sign of the speed variable you change the motor direction.
	void motor2(int speed /*-255 : 255*/);
	void motorStop();