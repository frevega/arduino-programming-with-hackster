#define IS_DEBUGGING 0

const int debounceDelay = 50;
unsigned long lastDebounceTime = 0;
const int btnPin = 3;
int counter = 0;
uint8_t btnState = HIGH, btnValue = 0, prevBtnValue = 0;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  count();
}

void count() {
  btnValue = digitalRead(btnPin);
  if (btnValue != prevBtnValue) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay) && (btnValue != btnState)) {
#if IS_DEBUGGING
    debugBtnState();
#endif
    btnState = btnValue;

    if (btnValue == LOW) {
      counter += 1;
      Serial.println(counter);
#if IS_DEBUGGING
      debugDebounceTime();
#endif
    }
  }

  prevBtnValue = btnValue;
}

void debugBtnState() {
  Serial.println(btnState);
  Serial.print(" ");
  Serial.print(btnValue);
}

void debugDebounceTime() {
  Serial.print(millis());
  Serial.print(" ");
  Serial.print(lastDebounceTime + debounceDelay);
  Serial.print(" ");
  Serial.println(millis() > (lastDebounceTime + debounceDelay) ? "True" : "False");
}