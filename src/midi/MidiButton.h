#pragma once

#include <Arduino.h>

#include "hardware/Button.h"
#include "log.h"
#include "sendMidi.h"

class MidiButton : public Button {
  int channel;
  int control;

  public:
    MidiButton(int pin_button, int channel, int control);
    void onClick();
};
