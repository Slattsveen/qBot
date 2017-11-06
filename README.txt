This is the qBot library, it contains pin allocations and some predefined functions to make the qBot - Arduino project work. 

The qBot library requires the following libraries installed:
"Adafruit_GFX"		-	Library manager
"Adafruit_SSD1306"	-	Library manager
"I2Cdev"		-	Library manager?
"MPU6050"		-	Library manager?
"NewPing"		-	Library manager?

Please have a look at www.qbot.no for more information about projects, how to build it and so on.

qBot sensor variable names, all are updated by calling the "updateSensors()" function:

	unsigned short reflVals[3];			// values from the three IR reflective sensors
	unsigned short lightVal;			// value from the light sensor
	bool reedVal;					// state of the reed switch (true/false)
	bool buttonVals[2];				// state of the buttons (true/false)
	unsigned short ax, ay, az;  			// accelerometer values
	unsigned short gx, gy, gz;			// gyroscope values
	unsigned short distVal;				// measurement from distance sensor in cm


qBot functions:

	QBot(); 					// constructor
	void start();					// run in the setup loop
	void updateSensors();				// updates all sensor values
	void printSensors();				// Serial print of all sensor values
	void oledWrite(int x, int y, String message);	// write something on the OLED screen
	void clearOled();				// empty the OLED screen

// Motor control functions, fairly self-explanatory
	void forward();
	void reverse();
	void turnRight();
	void turnLeft();
	void stop();
	void forward(int speed);  // motor control with speed control
	void reverse(int speed);
	void turnRight(int speed);
	void turnLeft(int speed);