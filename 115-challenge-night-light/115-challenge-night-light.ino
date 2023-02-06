const int READ_PIN = A0, LED_PIN = 6;
int readValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(READ_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

// Solution 1: `THERESOLD

void loop() {
  readValue = analogRead(READ_PIN);
  Serial.println(readValue);
  digitalWrite(LED_PIN, readValue <= 570 ? HIGH : LOW);
}

// Solution 2: PWM LED

// void loop() {
//   readValue = analogRead(READ_PIN);
//   Serial.println(readValue);
//   analogWrite(LED_PIN, map(readValue, 1023, 0, 0, 255));
// }
