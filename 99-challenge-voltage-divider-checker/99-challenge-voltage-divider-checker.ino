const int debounceDelay = 50;
unsigned long lastDebounceTime = 0;
const uint8_t btnPin = 3, analogPin = A0;
uint8_t btnState = HIGH, btnValue = 0, prevBtnValue = 0;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  read();
}

void read() {
  btnValue = digitalRead(btnPin);
  if (btnValue != prevBtnValue) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay) && (btnValue != btnState)) {
    btnState = btnValue;

    if (btnValue == LOW) {
      Serial.println(analogRead(analogPin) * 5. / 1023);
    }
  }

  prevBtnValue = btnValue;
}