#include "main.h"

BaseComponent* components[] = {
  // DECK LEFT
  new MidiClickableRotaryEncoder(2, 3, 4, 1, 0),
  new MidiClickableRotaryEncoder(5, 6, 7, 2, 0),
  new MidiPotentiometer(A0, 3, 0), // Volume
  new MidiPotentiometer(A1, 4, 0), // Low
  new MidiPotentiometer(A2, 5, 0), // Mid
  new MidiPotentiometer(A3, 6, 0), // High
  new MidiPotentiometer(A4, 7, 0), // Gain 
  //new ClickablePotentiometer(A5, 2) // FX1
};

void setup() { 
  Serial.begin(115200);
  for (auto& component : components) {
    component->setup();
  }
}


void loop() {
  for (auto& component : components) {
    component->process();
  }
}
