#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2

// DHT-11
DHT dht(DHTPIN, DHTTYPE);
float humidity = -1000, celcius = -1000;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// POTENTIOMETER & LCD LED
const int potPin = A0, lcdLedPin = 3;

unsigned long timeInterval = 2000, currentTime = 0, previousTime = 0;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(potPin, INPUT);
}

void loop() {
  analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
  readDHT();
}

void readDHT() {
  currentTime = millis();
  if (currentTime - previousTime >= timeInterval) {
    previousTime = currentTime;
    humidity = dht.readHumidity();
    celcius = dht.readTemperature();

    printTemp();
  }
}

void printTemp() {
  if (isnan(humidity) || isnan(celcius)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read  ");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
    return;
  } else if (humidity == -1000 && celcius == -1000) {
    lcd.setCursor(0, 0);
    lcd.print("Waiting for DHT ");
    lcd.setCursor(0, 1);
    lcd.print("sensor reading! ");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("H:        " + String(humidity) + "%");
  lcd.setCursor(0, 1);
  lcd.print("T:       " + String(celcius));
  lcd.write(223);
  lcd.print("C");
}
