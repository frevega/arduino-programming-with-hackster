int sides = 0;
bool isAskingAgain = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sides == 0 && !isAskingAgain) {
    Serial.println("Enter the number of sides on the die");
  } else if (sides > 0) {
    Serial.println("Die has " + String(sides) + " sides and you rolled " + String(randomNumber(sides)));
  }

  while(Serial.available() == 0) {}

  sides = Serial.readString().toInt();
  isAskingAgain = sides == 0;
}

int randomNumber(int limit) {
  randomSeed(millis());

  return random(1, limit + 1);
}

/*void loop() {
  randomSeed((millis() % 3) + (millis() / 2));
  for (int i = 0; i < 5; i++) {
    Serial.print(String(random(1, 101)) + " ");
  }
  Serial.println();
  delay(500);
}*/