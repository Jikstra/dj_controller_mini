#pragma once

#include <Arduino.h>

#include "BaseComponent.h"
#include "log.h"

class Potentiometer : public BaseComponent {
  public:
    int pin;
    int smoothedValue = -1;
    int lastMidiValue = -1;

    Potentiometer(int pin);
    void setup();
    void process();
};
