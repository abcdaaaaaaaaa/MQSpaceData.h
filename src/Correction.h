#ifndef CORRECTION_H
#define CORRECTION_H

#include <Arduino.h>

float fmap(float x, float in_min, float in_max, float out_min, float out_max);
float limit(float value, float minVal, float maxVal);
float scaleTemperature(float temp, int mode);
float calculateCorrection(float temp, float rh, const String& model);

#endif
