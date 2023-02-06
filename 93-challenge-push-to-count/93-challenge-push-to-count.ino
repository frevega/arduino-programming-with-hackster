#define IS_DEBUGGING 1

const uint8_t buttonPin = 3;
uint8_t counter = 0, buttonValue = 0, previousValue = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
#if IS_DEBUGGING
  Serial.begin(9600);
#endif
}

void loop() {
  toggle();
}

void toggle() {
  buttonValue = digitalRead(buttonPin);
  if ((buttonValue != previousValue) && (buttonValue == LOW)) {
    counter += 1;
    Serial.println(counter);
  }
  delay(50);
  previousValue = buttonValue;
}