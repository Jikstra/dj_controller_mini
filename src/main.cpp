#include "main.h"

void p(char *fmt, ... ){
  char buf[128]; // resulting string limited to 128 chars
  va_list args;
  va_start (args, fmt );
  vsnprintf(buf, 128, fmt, args);
  va_end (args);
  Serial.println(buf);
}

BaseComponent* components[] = {
  // DECK LEFT
  new MidiPotentiometer(A0, 1, 0), // Volume
  new MidiPotentiometer(A1, 2, 0), // Low
  new MidiPotentiometer(A2, 3, 0), // Mid
  new MidiPotentiometer(A3, 4, 0), // High
  new MidiPotentiometer(A4, 5, 0), // Gain 
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
