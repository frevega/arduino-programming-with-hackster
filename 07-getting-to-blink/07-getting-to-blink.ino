int ledValue = HIGH;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ledValue = !ledValue;
  digitalWrite(LED_BUILTIN, ledValue);
  Serial.println(ledValue == LOW ? "LED OFF" : "LED ON");
  delay(1000);
}
