void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // Count to 10, but replace the number 5 with the word "five"
  for (int i = 1; i <= 10; i++) {
    if (i == 5) {
      Serial.println("five");
    } else {
      Serial.println(i);
    }
  }
}

void loop() {
  int ms = 200;

  // Make the LED flash faster and faster until it appears as
  // a static light. Reset when the delay reaches 0 ms.
  while (ms > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(ms);
    digitalWrite(LED_BUILTIN, LOW);
    delay(ms);
    ms -= 5;
  }
}