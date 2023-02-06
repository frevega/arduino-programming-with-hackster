double operands[5][2] = { { 3, 2 }, { 5, 1 }, { 9, 0 }, { 2, 14 }, { 0, 4 } };
double powResult = 0;
double powerResult = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < sizeof(operands) / sizeof(operands[0]); i++) {
    powResult = ceil(pow(operands[i][0], operands[i][1]));
    powerResult = power(operands[i][0], operands[i][1]);
    Serial.print(String(operands[i][0]) + "^" + String(operands[i][1]) + ": " + String(powResult));
    Serial.print(" = " + String(powerResult));
    Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");
  }

  /* Should be 9
  powResult = pow(3, 2);
  powerResult = power(3, 2);
  Serial.print("3^2: " + String(powResult));
  Serial.print(" = " + String(powerResult));
  Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");

  // Should be 5
  powResult = pow(5, 1);
  powerResult = power(5, 1);
  Serial.print("5^1: " + String(powResult));
  Serial.print(" = " + String(powerResult));
  Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");

  // Should be 1
  powResult = pow(9, 0);
  powerResult = power(9, 0);
  Serial.print("9^0: " + String(powResult));
  Serial.print(" = " + String(powerResult));
  Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");

  // Should be 16384
  powResult = pow(2, 14);
  powerResult = power(2, 14);
  Serial.print("2^14: " + String(powResult));
  Serial.print(" = " + String(powerResult));
  Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");

  // Should be 0
  powResult = pow(0, 4);
  powerResult = power(0, 4);
  Serial.print("0^4: " + String(powResult));
  Serial.print(" = " + String(powerResult));
  Serial.println(powResult == powerResult ? ": SUCCESS" : ": ERROR");*/
}

void loop() {
}

double power(double base, double exponent) {
  double aux = 1;
  for (int i = 0; i < int(exponent); i++) {
    aux *= base;
  }
  return aux;
}