#include <Arduino.h>
#include "dimmer.h"

void setup() {
    Serial.begin(9600);
    initOutput();
}

void loop() {
    uint16_t percentage = readPercentage();
    setBrightness(percentage);
    Serial.println(percentage);
    yield();
}