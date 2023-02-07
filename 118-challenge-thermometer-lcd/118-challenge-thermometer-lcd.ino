#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2

// DHT-11
DHT dht(DHTPIN, DHTTYPE);
float humidity = NAN, celcius = NAN;

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
    lcd.print("temperature     ");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Humidity: " + String(humidity) + "%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:    " + String(celcius));
  lcd.write(223);
  lcd.print("C");
}
