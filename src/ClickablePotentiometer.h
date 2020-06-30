#pragma once

#include <Arduino.h>

#include "Potentiometer.h"
#include "Button.h"
#include "log.h"


class ClickablePotentiometer : public Potentiometer {
  public:
    int pinButton;
    unsigned long lastFlake;
    bool wasPressed = false;
    bool toggle = false;
    
    ClickablePotentiometer(int pinPotentiometer, int pinButton);
    void setup();
    void process();
    void onChange();
};
