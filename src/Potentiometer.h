#pragma once

#include <Arduino.h>

#include "log.h"

class Potentiometer {
  public:
    int pin;
    int smoothedValue = 0;
    int lastMidiValue = 0;

    Potentiometer(int pin);
    void setup();
    void process();
};
