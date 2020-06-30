#include "MidiPotentiometer.h"

MidiPotentiometer::MidiPotentiometer(int pin, int control, int channel) : Potentiometer(pin), control(control), channel(channel) {}

void MidiPotentiometer::onChange(int value) {  
  int midiValue = map(value, 0, 1023, 0, 127);
  if (midiValue == lastMidiValue) return;
  lastMidiValue = midiValue;

  DBG("MidiPotentiometer [%i] %i", pin, midiValue);
  sendMIDI(0xB, channel, control, midiValue);
}
