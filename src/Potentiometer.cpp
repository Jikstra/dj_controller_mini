#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin) : pin(pin) {}
  

void Potentiometer::setup() {}

void Potentiometer::process() {
  int value = analogRead(pin);

  // Smooth the analog value with some mathgic
  int smoothedDifference = (value - smoothedValue) / 4;
  if (smoothedDifference == 0) return;
  smoothedValue += smoothedDifference;

  int midiValue = map(value, 0, 1023, 0, 127);
  if (midiValue == lastMidiValue) return;
  lastMidiValue = midiValue;


  println("%i", midiValue);
}
