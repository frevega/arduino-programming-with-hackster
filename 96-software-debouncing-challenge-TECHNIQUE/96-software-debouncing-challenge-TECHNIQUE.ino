#define IS_DEBUGGING 0

const int debounceDelay = 50;
unsigned long lastDebounceTime = 0;
const uint8_t btnOnePin = 3, btnTwoPin = 6;
uint8_t btnOneState = HIGH, btnOneValue = 0, prevbtnOneValue = 0;
uint8_t btnTwoState = HIGH, btnTwoValue = 0, prevbtnTwoValue = 0;
int counter = 0;

void setup() {
  pinMode(btnOnePin, INPUT_PULLUP);
  pinMode(btnTwoPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  count();
}

void count() {
  btnOneValue = digitalRead(btnOnePin);
  btnTwoValue = digitalRead(btnTwoPin);

  if ((btnOneValue != prevbtnOneValue) || (btnTwoValue != prevbtnTwoValue)) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay) && ((btnOneValue != btnOneState) || (btnTwoValue != btnTwoState))) {
#if IS_DEBUGGING
    debugbtnOneState();
#endif
    btnOneState = btnOneValue;
    btnTwoState = btnTwoValue;

    if (btnOneValue == LOW) {
      counter += 1;
      Serial.println(counter);
#if IS_DEBUGGING
      debugDebounceTime();
#endif
    } else if (btnTwoValue == LOW) {
      counter -= 1;
      Serial.println(counter);
    }
  }

  prevbtnOneValue = btnOneValue;
  prevbtnTwoValue = btnTwoValue;
}

void debugbtnOneState() {
  Serial.print(btnOneState);
  Serial.print(" ");
  Serial.print(btnOneValue);
  Serial.print(" - ");
  Serial.print(btnTwoState);
  Serial.print(" ");
  Serial.println(btnTwoValue);
}

void debugDebounceTime() {
  Serial.print(millis());
  Serial.print(" ");
  Serial.print(lastDebounceTime + debounceDelay);
  Serial.print(" ");
  Serial.println(millis() > (lastDebounceTime + debounceDelay) ? "True" : "False");
}