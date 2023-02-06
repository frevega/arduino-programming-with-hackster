#include <LiquidCrystal_I2C.h>
#include "AnimationState.h"
#include "PushButton.h"

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte spaceInvaderOne[] = { 0x0, 0xA, 0x1F, 0x15, 0x1F, 0x15, 0x0, 0x0 };
byte spaceInvaderTwo[] = { 0x0, 0x4, 0x1F, 0x15, 0x1F, 0xA, 0x0, 0x0 };
int ldcXPosition = 0, lcdYPosition = 0;

// BUTTONS
PushButton leftButton(6, LEFT);
PushButton rightButton(5, RIGHT);
PushButton verticalButton(4, VERTICAL);

// POTENTIOMETER
int potPin = A0, lcdLedPin = 3;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  prepareCharacter();
}

void loop() {
  analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
  lcdAnimation();
}

void lcdAnimation() {
  if (verticalButton.readButton() == VERTICAL) {
    lcdYPosition = (lcdYPosition += 1) % 2;
    prepareCharacter();
  } else if (leftButton.readButton() == LEFT) {
    ldcXPosition = ldcXPosition > 0 ? ldcXPosition -= 1 : 0;
    prepareCharacter();
  } else if (rightButton.readButton() == RIGHT) {
    ldcXPosition = ldcXPosition < 15 ? ldcXPosition += 1 : 15;
    prepareCharacter();
  }
}

void prepareCharacter() {
  lcd.clear();
  lcd.createChar(0, (ldcXPosition + lcdYPosition) % 2 == 0 ? spaceInvaderOne : spaceInvaderTwo);
  lcd.setCursor(ldcXPosition, lcdYPosition);
  lcd.write(byte(0));
}