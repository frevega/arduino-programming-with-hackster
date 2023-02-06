#include "ShiftRegisterPWM.h"

#define IS_DEBUGGING 0

ShiftRegisterPWM sr(2, 25);
uint8_t const MAX_LED = 15;
#if IS_DEBUGGING
int i = 0, delayTime = 1000;
#else
uint8_t i = 0, delayTime = 50;
#endif

void setup() {
  pinMode(2, OUTPUT);  // sr data pin  (14)
  pinMode(3, OUTPUT);  // sr clock pin (11)
  pinMode(4, OUTPUT);  // sr latch pin (12)

  sr.interrupt(ShiftRegisterPWM::UpdateFrequency::Fast);
#if IS_DEBUGGING
  Serial.begin(9600);
#endif
}

void loop() {
  for (i = 1; i <= MAX_LED; i++) {
    ledsFX(i);
  }

  for (uint8_t j = i - 1; j > 0; j--) {
    ledsFX(j);
  }
}

void ledsFX(uint8_t ledPos) {
#if IS_DEBUGGING
  Serial.println(ledPos);
#endif
  sr.set(ledPos - 3, 0);
  sr.set(ledPos - 2, 8);
  sr.set(ledPos - 1, 75);
  sr.set(ledPos, 255);
  sr.set(ledPos + 1, 75);
  sr.set(ledPos + 2, 8);
  sr.set(ledPos + 3, 0);
  delay(delayTime);
}
