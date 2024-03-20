const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
const int ledPin = 12;

// Volts per G-force
const double sensitivity = 0.34;

const double volts = 3.3;
const int ADC_UNITS = 1023;

double x, y, z;

void setup() {
  pinMode(ledPin, OUTPUT);
  analogReference(EXTERNAL);
}

void loop() {
  x = readAccelerometer(xPin);
  y = readAccelerometer(yPin);
  z = readAccelerometer(zPin);

  if (isInRange(x,  0.1) && isInRange(y, 0.1) && isInRange(z, 1.01, 0)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(75);
}

float readAccelerometer(int pin) {
  return (analogRead(pin) - ADC_UNITS / 2) * volts / (sensitivity * ADC_UNITS);
}

bool isInRange(double val, double reference) {
  return val <= reference && val >= -reference;
}

bool isInRange(double val, double reference1, double reference2) {
  return val <= reference1 && val >= reference2;
}