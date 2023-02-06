int counter = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*while (counter >= 0) {
    Serial.println(counter);
    delay(250);
    counter--;
  } */

  for (counter; counter >= 0; counter--) {
    Serial.println(counter);
    delay(100);
  }
}
