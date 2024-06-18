/**
 * @file CheezUNO.ino
 * @author xuweican98@gmail.com
 * @brief 
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <SoftPWM.h>

int AO[6] = { A0, A1, A2, A3, A4, A5 };
int PWM[6] = { 3, 5, 6, 9, 10, 11 };
int DO[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5 };

int Pin[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                A0, A1, A2, A3, A4, A5 };

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

  SoftPWMBegin();

  for (int i = 0; i < pinNum(Pin); i++) {
    SoftPWMSet(i, 0);
    SoftPWMSetFadeTime(i, 1000, 1000);
  }
  delay(500);
}

void loop() {
  for (int i = 0; i < pinNum(Pin); i++) {
    SoftPWMSet(i, 255);
  }
  delay(1000);
  for (int i = 0; i < pinNum(Pin); i++) {
    SoftPWMSet(i, 0);
  }
  delay(1000);
}
