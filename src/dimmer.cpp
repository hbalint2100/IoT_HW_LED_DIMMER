#include "dimmer.h"

uint16_t currentPercentage = 0;

uint16_t readPercentage()
{
    float sum = 0;
    int16_t measured;
    for(int i = 0; i < 4; i++)
    {
        measured = analogRead(A0)-ADC_OFFSET;
        sum += ((measured<0?0:measured)*((float)1024/(1024-ADC_OFFSET)));
        delayMicroseconds(500);
    }
    
    return (uint16_t)sum/4;
}

void initOutput()
{
    pinMode(LED_PIN,OUTPUT);
    analogWriteResolution(10);
}

void setBrightness(uint16_t percentage)
{
    if(percentage!=currentPercentage)
    {
        currentPercentage = percentage;
        analogWrite(LED_PIN,percentage);
    }
}