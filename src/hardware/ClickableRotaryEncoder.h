#pragma once

#include <Arduino.h>


#include "hardware/RotaryEncoder.h"
#include "Button.h"
#include "log.h"

class ClickableRotaryEncoder : public RotaryEncoder {
    public:
      int pin_button;
      unsigned long button_last_flake;
      bool button_was_pressed = false;
      bool button_toggle = false;

      ClickableRotaryEncoder(int pin_ccw, int pin_button, int pin_cw);
      void setup();
      void process();
      void onTurn(Direction direction);
      void onClick();
};
