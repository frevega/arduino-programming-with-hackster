#include "pitches.h"

const int buzzerPin = 8;
unsigned long TIME_INTERVAL = 1000, currentTime = 0, previousTime = 0;
int melody[] = {
 NOTE_CS4, NOTE_CS4, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_DS5,
 NOTE_D5, NOTE_D5, NOTE_DS4, NOTE_DS4, NOTE_CS5, NOTE_CS5, NOTE_D4
};
int noteDurations[] = {
  2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

  for (size_t thisNote = 0; thisNote < (sizeof(melody) / sizeof(melody[0])); thisNote += 1) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void loop() {

}