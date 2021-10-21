#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include <HP-35Calc.h>

HPCalc calc = HPCalc();

void setup() {
  delay(5000); // time to get console running...
  Serial.begin(115200);
}

void loop() {
}