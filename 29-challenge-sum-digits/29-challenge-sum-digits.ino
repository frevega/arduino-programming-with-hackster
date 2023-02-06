void setup() {
  Serial.begin(9600);
  Serial.println(sumDigits(0));     // Should be 0
  Serial.println(sumDigits(2));     // Should be 2
  Serial.println(sumDigits(28));    // Should be 10
  Serial.println(sumDigits(504));   // Should be 9
  Serial.println(sumDigits(2048));  // Should be 14
  Serial.println(sumDigits(32767));  // Should be 25
}

void loop() {
}

int sumDigits(int x) {
  for (int sum = 0; x != 0; x /= 10) {
    sum += x % 10;

    if (x / 10 == 0) {
      return sum;
    }
  }
}