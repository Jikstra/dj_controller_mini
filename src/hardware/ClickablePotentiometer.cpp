#include "ClickablePotentiometer.h"

ClickablePotentiometer::ClickablePotentiometer(int pinPotentiometer, int pinButton) : Potentiometer(pinPotentiometer), pinButton(pinButton) {
}

void ClickablePotentiometer::setup() {
  pinMode(pinButton, INPUT_PULLUP);
}

void ClickablePotentiometer::process() {
  Potentiometer::process();

  int pinValue = digitalRead(pinButton);

  ButtonState button_state = buttonState(pinValue, &wasPressed, &lastFlake);

  if(!buttonToggle(button_state, &toggle)) {
    return;
  }

  println("ClickablePotentiometer [%i] Toggle!", pinButton);

}