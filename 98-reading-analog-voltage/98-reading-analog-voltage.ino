const int analogPin = A0;
int analogValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(analogPin);
  Serial.println(analogValue * 5. / 1023);
  delay(100);
}
