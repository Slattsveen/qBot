/*
	qBot library cpp file, here all the good stuff takes place!
*/

#include "qbot.h"
#include "Arduino.h"
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "NewPing.h"

Adafruit_SSD1306 display(13);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DIST);
MPU6050 accelgyro;

QBot::QBot(){ ////////////////////////  CONSTRUCTOR   //////////////////////////
		
	// Initialize variables with values
	reflVals = new unsigned int[3] {0, 0, 0};
	lightVal = 0;
	reedVal = false;
	buttonVals = new bool[2] {false, false};
	//unsigned short ax, ay, az;  // accelerometer values
	//unsigned short gx, gy, gz;	// gyroscope values
	distVal = 300;	
}

void QBot::start(){  /////////////////  SETUP   ///////////////////////
	Serial.begin(9600);

  //Sensor pin definitions
  for (int i = 0; i < 3; i++) {
    pinMode(reflSens[i], INPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(buttons[i], INPUT);
  }
  
  //attachInterrupt(2, ISR1, RISING);
  //attachInterrupt(3, ISR2, RISING);
  
  pinMode(lightSens, INPUT);
  pinMode(reedSens, INPUT);
  //accel gyro
  Wire.begin();
  accelgyro.initialize();
  accelgyro.testConnection();

  //Output pin definitions
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);
  stop(); // make sure motors start OFF
  

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  //OLED screen setup
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.display();
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(25, 6);
  display.println("qBot");
  display.display();
  delay(500);
  Serial.println("Setup complete");
}
/*
void ISR1(){
	button1Pressed = true;
}
void ISR2(){
	button2Pressed = true;
}
*/

void QBot::updateSensors(){
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); //Accelerometer and gyro data
  lightVal = analogRead(lightSens);                   //Light sensor data
  reedVal = digitalRead(reedSens);                    //Reed-switch data
  for (int i = 0; i < 3; i++) {                       //IR-reflective sensors
    reflVals[i] = digitalRead(reflSens[i]);
  }
  for (int i = 0; i < 2; i++) {                       //Button States
    buttonVals[i] = digitalRead(buttons[i]);
  }
  //buttonVals[0] = button1Pressed;
  //buttonVals[1] = button2Pressed;
  
  distVal = 0;
  unsigned char numReadings = 2;
  for (int i = 0; i < numReadings; i++) {
    delay(30);
    distVal += sonar.ping()	/ US_ROUNDTRIP_CM;
  }
  distVal = distVal/numReadings;
}



void QBot::printSensors(){
  Serial.print("Distance: ");
  Serial.println(distVal);

  Serial.print("Light value: ");
  Serial.println(lightVal);

  Serial.print("Reed-switch value : ");
  Serial.println(reedVal);

  Serial.print("Reflection sensors : ");
  Serial.print(reflVals[0]);
  Serial.print(" : ");
  Serial.print(reflVals[1]);
  Serial.print(" : ");
  Serial.println(reflVals[2]);

  Serial.print("Buttons : ");
  Serial.print(buttonVals[0]);
  Serial.print(" : ");
  Serial.println(buttonVals[1]);

  Serial.print("Accel/gyro: ");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print(" | ");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);
}

void QBot::oledWrite(int x, int y, String message){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.println(message);
  display.display();
}
void QBot::clearOled(){
	display.clearDisplay();
	display.display();
}

// Motor functions, one function for each motor, changing the sign of the speed value changes the motor direction

  void QBot::motor1(int speed   /* -255 : 255*/){
	if(speed >= 0){
		pinMode(MOTOR1_A, OUTPUT);
		pinMode(MOTOR1_B, OUTPUT);
		digitalWrite(MOTOR1_A, LOW);
		analogWrite(MOTOR1_B, abs(speed));
	}else{
		pinMode(MOTOR1_A, OUTPUT);
		pinMode(MOTOR1_B, OUTPUT);
		analogWrite(MOTOR1_A, abs(speed));
		digitalWrite(MOTOR1_B, LOW);
	}
  
  void QBot::motor2(int speed   /* -255 : 255*/){
	if(speed >= 0){
		pinMode(MOTOR2_A, OUTPUT);
		pinMode(MOTOR2_B, OUTPUT);
		digitalWrite(MOTOR2_A, LOW);
		analogWrite(MOTOR2_B, abs(speed));
	}else{
		pinMode(MOTOR2_A, OUTPUT);
		pinMode(MOTOR2_B, OUTPUT);
		analogWrite(MOTOR2_A, abs(speed));
		digitalWrite(MOTOR2_B, LOW);
	}
}

}
void QBot::stop(){
  pinMode(MOTOR1_A, INPUT);
  pinMode(MOTOR1_B, INPUT);
  pinMode(MOTOR2_A, INPUT);
  pinMode(MOTOR2_B, INPUT);
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
}
