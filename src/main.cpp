#include "main.h"

BaseComponent* components[] = {
  // LEFT DECK
  new MidiClickableRotaryEncoder(2,  3,  4,  MIDI_CTRL_BEAT_JUMP, MIDI_LEFT_DECK_CHANNEL),
  new MidiClickableRotaryEncoder(5,  6,  7,  MIDI_CTRL_LOOP,      MIDI_LEFT_DECK_CHANNEL),
  new MidiPotentiometer(         A0,         MIDI_CTRL_VOLUME,    MIDI_LEFT_DECK_CHANNEL), // Volume
  new MidiPotentiometer(         A1,         MIDI_CTRL_EQ_LOW,    MIDI_LEFT_DECK_CHANNEL), // Low
  new MidiPotentiometer(         A2,         MIDI_CTRL_EQ_MID,    MIDI_LEFT_DECK_CHANNEL), // Mid
  new MidiPotentiometer(         A3,         MIDI_CTRL_EQ_HIGH,   MIDI_LEFT_DECK_CHANNEL), // High
  new MidiPotentiometer(         A4,         MIDI_CTRL_GAIN,      MIDI_LEFT_DECK_CHANNEL), // Gain 
  new MidiClickablePotentiometer(A5, 53,     MIDI_CTRL_FX1,       MIDI_LEFT_DECK_CHANNEL), // FX1
  new MidiButton(                23,         MIDI_CTRL_PLAY,      MIDI_LEFT_DECK_CHANNEL), // Play
  new MidiButton(                25,         MIDI_CTRL_MONITOR,   MIDI_LEFT_DECK_CHANNEL), // Monitor
  new MidiButton(                27,         MIDI_CTRL_SYNC,      MIDI_LEFT_DECK_CHANNEL), // Sync

  // RIGHT DECK
  new MidiClickableRotaryEncoder(8,  9,  10, MIDI_CTRL_BEAT_JUMP, MIDI_RIGHT_DECK_CHANNEL),
  new MidiClickableRotaryEncoder(11, 12, 13, MIDI_CTRL_LOOP,      MIDI_RIGHT_DECK_CHANNEL),
  new MidiPotentiometer(         A6,         MIDI_CTRL_VOLUME,    MIDI_RIGHT_DECK_CHANNEL), // Volume
  new MidiPotentiometer(         A7,         MIDI_CTRL_EQ_LOW,    MIDI_RIGHT_DECK_CHANNEL), // Low
  new MidiPotentiometer(         A8,         MIDI_CTRL_EQ_MID,    MIDI_RIGHT_DECK_CHANNEL), // Mid
  new MidiPotentiometer(         A9,         MIDI_CTRL_EQ_HIGH,   MIDI_RIGHT_DECK_CHANNEL), // High
  new MidiPotentiometer(         A10,        MIDI_CTRL_GAIN,      MIDI_RIGHT_DECK_CHANNEL), // Gain 
  new MidiClickablePotentiometer(A11, 52,    MIDI_CTRL_FX1,       MIDI_RIGHT_DECK_CHANNEL), // FX1
  new MidiButton(                22,         MIDI_CTRL_PLAY,      MIDI_RIGHT_DECK_CHANNEL), // Play
  new MidiButton(                24,         MIDI_CTRL_MONITOR,   MIDI_RIGHT_DECK_CHANNEL), // Monitor
  new MidiButton(                26,         MIDI_CTRL_SYNC,      MIDI_RIGHT_DECK_CHANNEL), // Sync

  new MidiButton(                37,         MIDI_CTRL_SHIFT,     MIDI_ALL_CHANNEL), // Shift
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
