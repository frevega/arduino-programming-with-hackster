const int RED_LED_PIN = 4;
const int GREEN_LED_PIN = 3;
const int BLUE_LED_PIN = 2;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  lightUp(RED_LED_PIN, 1, 150);
  lightUp(GREEN_LED_PIN, 2, 150);
  lightUp(BLUE_LED_PIN, 3, 150);
}

void lightUp(int pinID, int blinkTimes, int delayVal) {
  int ledValue = LOW;
  for (int i = 0; i < blinkTimes * 2; i++) {
    ledValue = !ledValue;
    digitalWrite(pinID, ledValue);
    delay(delayVal);
  }
}

