#include "qbot.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <I2Cdev.h>
#include "MPU6050.h"
#include <NewPing.h>

QBot bot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bot.start();
}

void loop() {
  bot.updateSensors();
  bot.printSensors();
  // put your main code here, to run repeatedly:
  bot.stop();
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  bot.forward();
  delay(500);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  bot.stop();
  delay(500);
}
