const byte REGISTERS_QTTY = 10;
const float LEDS_QTTY = 74;//8 * REGISTERS_QTTY;
const byte LEDS_PER_REGISTRY_QTTY = ceil(LEDS_QTTY / REGISTERS_QTTY);

// 74HC595
const byte SERIAL_DATA_PIN = 13;   // Pin 14 74HC595 (1)
const byte LATCH_CLOCK_PIN = 12;   // pin 12 74HC595 (1)
const byte SHIFT_CLOCK_PIN = 11;   // pin 11 74HC595 (1)
const byte CLEAR_PIN = 10;         // Pin 10 74HC595 (1)
const byte OUTPUT_ENABLE_PIN = 9;  // Pin 13 74HC595 (1)

// Potentiometer
const byte potPin = A0;

const int animationDelay = 30;

int shiftRegistersPins[] = { SERIAL_DATA_PIN, LATCH_CLOCK_PIN, SHIFT_CLOCK_PIN, CLEAR_PIN, OUTPUT_ENABLE_PIN };

byte *ledsState = new byte[REGISTERS_QTTY];

void setup() {
  //Serial.begin(9600);
  for (size_t i = 0; i < REGISTERS_QTTY; i++) {
    ledsState[i] = 0;
  }

  for (size_t i = 0; i < sizeof(shiftRegistersPins) / sizeof(int); i++) {
    pinMode(shiftRegistersPins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);

  digitalWrite(CLEAR_PIN, LOW);
  digitalWrite(CLEAR_PIN, HIGH);
}

void loop() {
  lightEffects();
}


void lightEffects() {
  for (int i = 0; i < LEDS_QTTY; i++) {
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(i, HIGH);
    delay(animationDelay);
    writeToRegister(i, LOW);
  }

  for (int i = LEDS_QTTY - 1; i >= 0; i--) {
    analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
    writeToRegister(i, HIGH);
    delay(animationDelay);
    writeToRegister(i, LOW);
  }
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

  // for (byte i = 0; i < sizeof(ledsState); i++) {
  //   Serial.print(String(i) + ": ");
  //   Serial.print(ledsState[i], DEC);
  //   Serial.print(" ");
  // }
  // Serial.println();
}