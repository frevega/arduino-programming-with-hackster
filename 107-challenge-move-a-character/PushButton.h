#include "AnimationState.h"

#ifndef PushButton_h
#define PushButton_h

class PushButton {
private:
  const int debounceDelay = 50;
  unsigned long lastDebounceTime = 0;
  int pin;
  int state;
  int value = 0, previousValue = 0;
  AnimationState animationState;

public:
  PushButton(int pin, AnimationState animationState);
  AnimationState readButton();
};

#endif