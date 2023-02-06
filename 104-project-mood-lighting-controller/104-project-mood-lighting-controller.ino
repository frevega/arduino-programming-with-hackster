const byte REGISTERS_QTTY = 10;
const float LEDS_QTTY = 74;  //8 * REGISTERS_QTTY;
const byte LEDS_PER_REGISTRY_QTTY = ceil(LEDS_QTTY / REGISTERS_QTTY);

// 74HC595
const byte SERIAL_DATA_PIN = 13;   // Pin 14 74HC595 (1)
const byte LATCH_CLOCK_PIN = 12;   // pin 12 74HC595 (1)
const byte SHIFT_CLOCK_PIN = 11;   // pin 11 74HC595 (1)
const byte CLEAR_PIN = 10;         // Pin 10 74HC595 (1)
const byte OUTPUT_ENABLE_PIN = 9;  // Pin 13 74HC595 (1)

const int animationDelay = 30;
int shiftRegistersPins[] = { SERIAL_DATA_PIN, LATCH_CLOCK_PIN, SHIFT_CLOCK_PIN, CLEAR_PIN, OUTPUT_ENABLE_PIN };
byte *ledsState = new byte[REGISTERS_QTTY];

// Potentiometer
const byte potPin = A0;

// Button
const int debounceDelay = 50;
unsigned long lastDebounceTime = 0;
const byte btnPin = 2;
int randomOption = 0;
byte btnState = HIGH, /*btnValue = 0, */ prevBtnValue = 0;

void setup() {
  Serial.begin(9600);
  for (size_t i = 0; i < REGISTERS_QTTY; i++) {
    ledsState[i] = 0;
  }

  for (size_t i = 0; i < sizeof(shiftRegistersPins) / sizeof(int); i++) {
    pinMode(shiftRegistersPins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);
  pinMode(btnPin, INPUT_PULLUP);

  digitalWrite(CLEAR_PIN, LOW);
  digitalWrite(CLEAR_PIN, HIGH);
}

void loop() {
  lightEffects();
}

void lightEffects() {
  switch (randomOption) {
    case 0:
      effectFour(0, 36);
      break;
    case 1:
      effectFour(-36, 0);
      break;
    case 2:
      effectThree(0, 73);
      break;
    case 3:
      effectThree(-36, 36);
      break;
    case 4:
      effectThree(0, 36);
      break;
    case 5:
      effectThree(-36, 0);
      break;
    case 6:
      rapidBurstEffect(73, 0);
      break;
    case 7:
      larsonScannerEffect(73, 0);
      break;
  }
}

void rapidBurstEffect(int min, int max) {
  bool keepOnGoing = true;

  for (int i = min; (i >= max) && keepOnGoing; i--) {
    for (int j = i; (j >= max) && keepOnGoing; j--) {
      if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
        keepOnGoing = false;
      }
      analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
      writeToRegister(abs(j), HIGH);
      delay(1);
      writeToRegister(abs(j), LOW);
    }
  }

  for (int i = max; (i >= -min) && keepOnGoing; i--) {
    for (int j = i; (j >= -min) && keepOnGoing; j--) {
      if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
        keepOnGoing = false;
      }
      analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
      writeToRegister(abs(j), HIGH);
      delay(1);
      writeToRegister(abs(j), LOW);
    }
  }
}

void larsonScannerEffect(int min, int max) {
  bool keepOnGoing = true;

  for (int i = min; (i >= max) && keepOnGoing; i--) {
    if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
      keepOnGoing = false;
    }
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(abs(i), HIGH);
    delay(12);
    writeToRegister(abs(i), LOW);
  }

  for (int i = max; (i <= min) && keepOnGoing; i++) {
    if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
      keepOnGoing = false;
    }
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(abs(i), HIGH);
    delay(12);
    writeToRegister(abs(i), LOW);
  }
}

void effectThree(int min, int max) {
  bool keepOnGoing = true;

  for (int i = max; (i >= min) && keepOnGoing; i--) {
    for (int k = min; (k <= i) && keepOnGoing; k++) {
      if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
        keepOnGoing = false;
      }
      analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
      writeToRegister(abs(k), HIGH);
      writeToRegister(LEDS_QTTY - 1 - abs(k), HIGH);
      delayMicroseconds(15);
      writeToRegister(abs(k), LOW);
      writeToRegister(LEDS_QTTY - 1 - abs(k), LOW);
    }

    writeToRegister(abs(i), HIGH);
    writeToRegister(LEDS_QTTY - 1 - abs(i), HIGH);
  }
}

void effectFour(int min, int max) {
  bool keepOnGoing = true;

  for (int i = min; (i <= max) && keepOnGoing; i++) {
    if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
      keepOnGoing = false;
    }
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(abs(i), HIGH);
    writeToRegister(LEDS_QTTY - 1 - abs(i), HIGH);
    delay(20);
  }

  for (int i = max; (i >= min) && keepOnGoing; i--) {
    if ((randomOperation(digitalRead(btnPin)) == LOW) && keepOnGoing) {
      keepOnGoing = false;
    }
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(abs(i), LOW);
    writeToRegister(LEDS_QTTY - 1 - abs(i), LOW);
    delay(20);
  }
}

int randomOperation(int btnValue) {
  byte randomOperationResponse = HIGH;

  if (btnValue != prevBtnValue) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay) && (btnValue != btnState)) {
    btnState = btnValue;

    if (btnValue == LOW) {
randomGenTag:
      randomSeed(millis());
      int randomValue = random(0, 8);
      if (randomOption != randomValue) {
        randomOperationResponse = LOW;
        randomOption = randomValue;
        // Serial.println(randomOption);
      } else {
        goto randomGenTag;
      }
    }
  }

  prevBtnValue = btnValue;

  return randomOperationResponse;
}

void writeToRegister(byte pin, byte ledState) {
  byte currentRegisterIndex = pin / LEDS_PER_REGISTRY_QTTY;
  byte currentPinIndex = pin - (LEDS_PER_REGISTRY_QTTY * currentRegisterIndex);

  digitalWrite(LATCH_CLOCK_PIN, LOW);
  for (byte registerIndex = 0; registerIndex < REGISTERS_QTTY; registerIndex++) {
    byte *leds = &ledsState[registerIndex];

    if (registerIndex == currentRegisterIndex) {
      bitWrite(*leds, currentPinIndex, ledState);
    }

    shiftOut(SERIAL_DATA_PIN, SHIFT_CLOCK_PIN, MSBFIRST, *leds);
  }

  digitalWrite(LATCH_CLOCK_PIN, HIGH);
}