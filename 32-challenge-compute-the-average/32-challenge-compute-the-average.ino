int a[] = { 0, 2, -4, 12, -52, 42, -96, 7, -23, 99 };
//int a[] = { 125, 1920, 503, 299, 67, 13578, 7632, 22043 };

void setup() {
  float sum = 0;
  size_t aSize = sizeof(a) / sizeof(a[0]);

  for (int i = 0; i < aSize; i++) {
    sum += a[i];
  }

  Serial.begin(9600);
  Serial.println(sum / aSize, 4);
}

void loop() {
}
