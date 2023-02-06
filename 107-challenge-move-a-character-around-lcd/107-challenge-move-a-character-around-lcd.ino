#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int potPin = A0, ledLightPin = 3;

byte spaceInvaderOne[] = { 0x0, 0xA, 0x1F, 0x15, 0x1F, 0x15, 0x0, 0x0 };
byte spaceInvaderTwo[] = { 0x0, 0x4, 0x1F, 0x15, 0x1F, 0xA, 0x0, 0x0 };

void setup() {
  // Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

unsigned long timeInterval = 180, currentTime = 0, previousTime = 0, previousTime2 = 0;
const int MAX_COUNT = 16;
bool lstopped = false;
int lcounter = MAX_COUNT;
int rcounter = 0;

void loop() {
  analogWrite(ledLightPin, map(analogRead(potPin), 0, 1023, 0, 255));

  currentTime = millis();
  if ((currentTime - previousTime >= timeInterval) && !lstopped) {
    previousTime = currentTime;
    lcd.createChar(0, lcounter % 2 == 0 ? spaceInvaderOne : spaceInvaderTwo);
    lcd.setCursor(15, 0);
    lcd.write(byte(0));
    if (lcounter < MAX_COUNT) {
      lcd.scrollDisplayLeft();
    }
    lcounter -= 1;
  }

  currentTime = millis();
  if ((currentTime - previousTime2 >= timeInterval) && lstopped) {
    previousTime2 = currentTime;
    lcd.createChar(0, rcounter % 2 == 0 ? spaceInvaderOne : spaceInvaderTwo);
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    if (rcounter > 0) {
      lcd.scrollDisplayRight();
    }
    rcounter += 1;
  }

  if (lcounter <= -1 && !lstopped) {
    lstopped = true;
    lcd.clear();
  }

  if (rcounter > MAX_COUNT) {
    lcounter = MAX_COUNT;
    lstopped = false;
    rcounter = 0;
    lcd.clear();
  }
}

/*
void loop() {
  analogWrite(ledLightPin, map(analogRead(potPin), 0, 1023, 0, 255));

  currentTime = millis();
  if ((currentTime - previousTime >= timeInterval)) {
    previousTime = currentTime;
    lcd.createChar(0, lcounter % 2 == 0 ? spaceInvaderOne : spaceInvaderTwo);
    !lstopped ? lcd.setCursor(15, 0) : lcd.setCursor(0, 1);
    lcd.write(byte(0));
    if (!lstopped && (lcounter < MAX_COUNT)) {
        lcd.scrollDisplayLeft();
    } else if (lstopped && (lcounter > 0)) {
        lcd.scrollDisplayRight();
    }
    lcounter = !lstopped ? lcounter -= 1 : lcounter += 1;
  }

  if (!lstopped && (lcounter < 0 && !lstopped)) {
    Serial.println("if " + String(lcounter));
    lcounter = 0;
    lstopped = true;
    lcd.clear();
  } else if (lstopped && (lcounter > MAX_COUNT)) {
    Serial.println("else " + String(lcounter));
    lcounter = MAX_COUNT;
    lstopped = false;
    lcd.clear();
  }
}
*/

/* SOURCE OF TRUTH
void loop() {
  lcd.clear();
  for (size_t j = 0; j < 16; j++) {
    analogWrite(ledLightPin, map(analogRead(potPin), 0, 1023, 0, 255));
    lcd.scrollDisplayLeft();
    lcd.createChar(0, spaceInvaderOne);
    lcd.setCursor(16, 0);
    lcd.write(byte(0));
    delay(175);

    lcd.createChar(0, spaceInvaderTwo);
    lcd.write(byte(0));
    delay(175);
  }
  
  lcd.clear();
  for (size_t j = 0; j < 16; j++) {
    analogWrite(ledLightPin, map(analogRead(potPin), 0, 1023, 0, 255));
    lcd.createChar(0, spaceInvaderOne);
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    delay(175);

    lcd.createChar(0, spaceInvaderTwo);
    lcd.write(byte(0));
    delay(175);
    lcd.scrollDisplayRight();
  }
}
*/