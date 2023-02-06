const int RED_LED_PIN = 11;
const int GREEN_LED_PIN = 10;
const int BLUE_LED_PIN = 9;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int r = 0; r < 256; r += 5) {
    //Serial.print("R: " + String(r) + " ");
    analogWrite(RED_LED_PIN, r);
    for (int g = 0; g < 256; g += 5) {
      //Serial.print("G: " + String(g) + " ");
      analogWrite(GREEN_LED_PIN, g);
      for (int b = 0; b < 256; b += 5) {
        // Serial.println("B: " + String(b));
        analogWrite(BLUE_LED_PIN, b);
        delay(delayAtColor(r, g, b));
      }
    }
  }
}

int delayAtColor(int r, int g, int b) {
  // Serial.println(String(r) + " " + String(g) + " " + String(b));
  if ((r == 255 && g == 0 && b == 0)
      || (r == 255 && g == 15 && b == 0)
      || (r == 255 && g == 60 && b == 0)
      || (r == 0 && g == 255 && b == 0)
      || (r == 0 && g == 0 && b == 255)
      || (r == 75 && g == 0 && b == 255)) {
    Serial.println("Found some color: R: " + String(r) + ", G: " + String(g) + ", B: " + String(b));
    return 2000;
  }

  return 0;
}