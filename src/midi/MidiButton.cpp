#include "MidiButton.h"

MidiButton::MidiButton(int pin_button, int control, int channel) : Button(pin_button), control(control), channel(channel) {}

void MidiButton::onPress() {
  DBG("MidiButton [%i] Pressed!", pin_button);
  sendMIDI(0x9, channel, control, 0x7F);
}

void MidiButton::onRelease() {
  DBG("MidiButton [%i] Released!", pin_button);
  sendMIDI(0x9, channel, control, 0x00);
}
