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
  new Potentiometer(A0), // Volume
  new Potentiometer(A1), // Low
  new Potentiometer(A2), // Mid
  new Potentiometer(A3), // High
  new Potentiometer(A4), // Gain 
  new ClickablePotentiometer(A5, 2) // FX1
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
