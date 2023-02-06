int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  counter++;
  Serial.println((counter % 3 == 0) ? "Fizz" : String(counter));
  delay(500);
}
