const int RED_LED_PIN = 5;
int counter = 0;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  counter++;
  if (counter % 3 == 0) {
    Serial.println("Fizz");
    digitalWrite(RED_LED_PIN, HIGH);
    delay(500);
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    Serial.println(String(counter));
  }
  
  delay(500);
}
