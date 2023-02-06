const int PWM_LED_PIN = 11;
const int MIN_VALUE = 0;
const int MAX_VALUE = 255;
const int DELAY_VALUE = 50;
int ledValue = 0;
bool isLightingUp = true;

void setup() {
  pinMode(PWM_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*for (int ledValue = MIN_VALUE; ledValue <= MAX_VALUE; ledValue+=15) {
    analogWrite(PWM_LED_PIN, ledValue);
    Serial.println(ledValue);

    if (ledValue == MAX_VALUE) {
      for (int ledValue = MAX_VALUE; ledValue >= MIN_VALUE; ledValue-=15) {
        analogWrite(PWM_LED_PIN, ledValue);
        Serial.println(ledValue);
        delay(DELAY_VALUE);
      }
    }
    delay(DELAY_VALUE);
  }*/

  while (isLightingUp ? ledValue < MAX_VALUE : ledValue > MIN_VALUE) {
    ledValue += isLightingUp ? 15 : -15;
    analogWrite(PWM_LED_PIN, ledValue);
    Serial.println(ledValue);
    delay(DELAY_VALUE);
  }
  isLightingUp = !isLightingUp;
}
