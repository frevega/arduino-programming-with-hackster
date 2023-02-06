const int btnPin = 3;
const int ledPin = 6;

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, digitalRead(btnPin) == LOW ? HIGH : LOW);
}
