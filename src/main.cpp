#include "main.h"

void p(char *fmt, ... ){
  char buf[128]; // resulting string limited to 128 chars
  va_list args;
  va_start (args, fmt );
  vsnprintf(buf, 128, fmt, args);
  va_end (args);
  Serial.println(buf);
}


void setup() {
  Serial.begin(115200);
}


Potentiometer* poti = new Potentiometer(A0);

void loop() {
  //for (auto& potentiometer : potentiometers) {
  //  processPotentiometer(&potentiometer);
  //}
  //
  
  poti->process();
}
