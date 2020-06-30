#pragma once

#include <Arduino.h>

#include "Potentiometer.h"
#include "log.h"
#include "midi.h"

class MidiPotentiometer : public Potentiometer {
  int channel;
  int control;
  int lastMidiValue = -1;

  public:
    MidiPotentiometer(int pin, int channel, int control);
    void onChange(int value);
};
