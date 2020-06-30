#pragma once

#include "log.h"

bool isBouncing(unsigned long* last_flake_millis);
enum class ButtonState {Pressed, Unchanged, Unpressed};
ButtonState buttonState(int pinValue, bool* wasPressed,  unsigned long* lastFlakeMillis);
char* buttonStateToString(ButtonState buttonState);
bool buttonToggle(ButtonState buttonState, bool* toggle);


