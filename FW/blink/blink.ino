/**
 * @file blink.ino
 * @author xuweican98@gmail.com
 * @brief 
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */ 

int AO[6] = { A0, A1, A2, A3, A4, A5 };
int PWM[6] = { 3, 5, 6, 9, 10, 11 };
int DO[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5 };
 
#define pinNum(x) sizeof(x) / sizeof(x[0])

void LEDInit(int *LED) {
  for (int i = 0; i < pinNum(DO); i++) {
    pinMode(DO[i], OUTPUT);
  }
}

void ledDemo(int *pins, int numPins, int delayTime) {
  for (int i = 0; i < numPins; i++) {
    digitalWrite(pins[i], HIGH);
    delay(delayTime);
  }
  for (int i = numPins - 1; i >= 0; i--) {
    digitalWrite(pins[i], LOW);
    delay(delayTime);
  }
}

void ledOnOff(int *pins, int numPins, bool status) {
  for (int i = 0; i < numPins; i++) {
    digitalWrite(pins[i], status);
  }
}

void setup() {
  LEDInit(DO);
  LEDInit(AO);

  ledDemo(AO, pinNum(AO), 50);
  ledDemo(DO, pinNum(DO), 50);
  ledOnOff(DO, pinNum(DO), 0);
  ledOnOff(AO, pinNum(AO), 1);
 
}

void loop() { 
   static int PwmVal = 0;
  static bool increase = true;
  for (int i = 0; i < pinNum(PWM); i++) 
  {
    PwmVal = (increase == true) ? PwmVal + 1 : PwmVal - 1;
    increase = (PwmVal <= 0 || PwmVal >= 255) ? !increase : increase;
    analogWrite(PWM[i], PwmVal);
  }
  delay(20);
}
