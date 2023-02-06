const int ledPin = 13;
const int receiverPin = 7;
const int laserPin = 8;
int receiverVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(receiverPin, INPUT);
  Serial.begin(9600);
  digitalWrite(receiverPin, HIGH);
  digitalWrite(laserPin, HIGH);
}

void loop() {
  receiverVal = digitalRead(receiverPin);
  digitalWrite(ledPin, receiverVal == LOW ? HIGH : LOW);
  Serial.println(receiverVal);
  /*delay(1000);
  digitalWrite(laserPin, LOW);
  delay(1000);*/
}
