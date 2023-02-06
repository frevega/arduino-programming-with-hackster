#include "PushButton.h"
#include "Arduino.h"

PushButton::PushButton(int pin, AnimationState animationState) {
  this->pin = pin;
  this->animationState = animationState;
  state = LOW;
  pinMode(pin, INPUT_PULLUP);
}

AnimationState PushButton::readButton() {
  value = digitalRead(pin);
  AnimationState response = NONE;

  if (value != previousValue) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay) && (value != state)) {
    state = value;
    if (value == LOW) {
      response = animationState;
    }
  }

  previousValue = value;

  return response;
}