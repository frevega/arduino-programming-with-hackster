const int8_t analogPin = A0, ledPin = 6;
int ledValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ledValue = map(analogRead(analogPin), 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);
}
