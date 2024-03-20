const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

// Volts per G-force
const double sensitivity = 0.34;

const double volts = 3.3;
const int ADC_UNITS = 1023;

double x, y, z;

void setup() {
  analogReference(EXTERNAL);
  Serial.begin(9600);
}

void loop() {
  x = (analogRead(xPin) - ADC_UNITS / 2) * volts / (sensitivity * ADC_UNITS);
  y = (analogRead(yPin) - ADC_UNITS / 2) * volts / (sensitivity * ADC_UNITS);
  z = (analogRead(zPin) - ADC_UNITS / 2) * volts / (sensitivity * ADC_UNITS);

  Serial.println("X: " + String(x) + " Y: " + String(y) + " Z: " + String(z));
  delay(75);
}
