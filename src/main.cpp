#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>

Adafruit_TSL2591 _tsl = Adafruit_TSL2591(2591);
int TSL2591X = 41; // I2C scanner reported 0x29  

void configureSensor() {
  _tsl.setGain(TSL2591_GAIN_MED);
  _tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (_tsl.begin()) {
    Serial.println("Sensor ready!");
  } else {
    Serial.println("Found no sensor.");
  }
  configureSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Brightness: ");
  Serial.println(_tsl.getLuminosity(TSL2591_VISIBLE));
  delay(999);
}