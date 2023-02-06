#define IS_DEBUGGING 0

int ledPin = 6, buttonPin = 3;
uint8_t ledState = 0, buttonValue = 0, previousValue = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
#if IS_DEBUGGING
  Serial.begin(9600);
#endif
}

void loop() {
  toggleLed();
}

void toggleLed() {
  buttonValue = digitalRead(buttonPin);
  if ((buttonValue != previousValue) && (buttonValue == LOW)) {
    ledState = (ledState + 1) % 2;
    Serial.println(ledState);
  }
  digitalWrite(ledPin, ledState);
  delay(50);
  previousValue = buttonValue;
}