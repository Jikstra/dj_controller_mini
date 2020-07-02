#include "MidiClickablePotentiometer.h"

MidiClickablePotentiometer::MidiClickablePotentiometer(int pin, int pin_button, int control, int channel) : ClickablePotentiometer(pin, pin_button), control(control), channel(channel) {}

void MidiClickablePotentiometer::onChange(int value) {
  int midiValue = map(value, 0, 1023, 0, 127);
  if (midiValue == lastMidiValue) return;
  lastMidiValue = midiValue;

  DBG("MidiClickablePotentiometer [%i] %i", pin, midiValue);
  sendMIDI(0xB, channel, control, midiValue);
}

void MidiClickablePotentiometer::onClick() {
  DBG("MidiClickablePotentiometer [%i] Clicked!", pin);
  sendMIDI(0x9, channel, control, 0x00);
}
