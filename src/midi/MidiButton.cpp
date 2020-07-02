#include "MidiButton.h"

MidiButton::MidiButton(int pin_button, int control, int channel) : Button(pin_button), control(control), channel(channel) {}

void MidiButton::onClick() {
  DBG("MidiButton [%i] Clicked!", pin_button);
  sendMIDI(0x9, channel, control, 0x00);
}
