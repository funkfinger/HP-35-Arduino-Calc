#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "hp35Calc.h"

HPCalc calc = HPCalc();

void setup() {
  delay(1000);
  Serial.begin(115200);
  delay(5000);
  Serial.println("starting hp 35 calculator...");
}

void loop() {
  calc.enterCommand(F_CLR);
  calc.enterCommand(F_TWO);
  calc.enterCommand(F_DECIMAL);
  calc.enterCommand(F_ZERO);
  calc.enterCommand(F_TWO);
  calc.enterCommand(F_LN);
  calc.enterCommand(F_E_TO_X);
  calc.enterCommand(F_CHS);
  // calc.enterCommand(F_ENTER);

  // calc.enterCommand(F_THREE);
  // calc.enterCommand(F_ENTER);
  // calc.enterCommand(F_TIMES);
  // calc.enterCommand(F_PI);
  // calc.enterCommand(F_TIMES);


  Serial.println(calc.getResultString());
  delay(5000);
}