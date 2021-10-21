#include <Arduino.h>

#include <HP-35Calc.h>

HPCalc calc = HPCalc();

void setup() {
  delay(5000); // time to get console running...
  Serial.begin(115200);
  Serial.println("starting hp 35 calculator...");
  Serial.println("press clr");
  calc.enterCommand(F_CLR);
  Serial.println("press 2");
  calc.enterCommand(F_TWO);
  Serial.println("press .");
  calc.enterCommand(F_DECIMAL);
  Serial.println("press 0");
  calc.enterCommand(F_ZERO);
  Serial.println("press 2");
  calc.enterCommand(F_TWO);
  Serial.println("press ln");
  calc.enterCommand(F_LN);
  Serial.println("press e^x");
  calc.enterCommand(F_E_TO_X);
  Serial.println("press chs");
  calc.enterCommand(F_CHS);

  Serial.print("RESULT = ");
  Serial.println(calc.getResultString());
}

void loop() {
}