#define TRIGGERPIN 12
#define ECHOPIN 11
#define BUZZERPIN 8

int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

int travelTime = 0;
float distanceInCm = 0;

void setup() {
  // Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);

  travelTime = pulseIn(ECHOPIN, HIGH);
  delay(25);

  int cm = 1/29.154 * travelTime/2;
  cm = cm > 50 ? 50 : cm; 
  int blah = map(cm, 5, 50, 0, 7);
  // Serial.println(String(cm) + " " + String(blah));

  
  tone(BUZZERPIN, frequencies[blah]);
  delay(100);
}
