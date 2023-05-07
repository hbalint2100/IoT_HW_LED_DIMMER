#pragma once
#include "Arduino.h"

#define ADC_OFFSET 4
#define LED_PIN 14

uint16_t readPercentage();
void initOutput();
void setBrightness(uint16_t percentage);