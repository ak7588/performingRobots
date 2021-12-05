/*
Performing Robots - Final Project
Amina and Salama
Bashful and Happy Dwarf
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

#define PIN        6 
#define NUMPIXELS 64 

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 

const int bashfulPixels[] = {9,11,13,15,18,22,28,33,38,42,43,44,45};
const int bashfulCount = 13;
const int happyPixels[] = {10,14,17,19,21,23,33,36,39,42,46,51,52,53};
const int happyCount = 14;

const int happyPin = 7;
const int bashfulPin = 2;

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  pinMode(happyPin, INPUT_PULLUP);
  pinMode(bashfulPin, INPUT_PULLUP);
  strip.begin();
}

void loop() {
  strip.show();
    
  Serial.println(digitalRead(bashfulPin));
  Serial.println(digitalRead(happyPin));
  
  if (digitalRead(bashfulPin) == 0) {
    strip.clear();
    playBashful(); 
  }

  if (digitalRead(happyPin) == 0) {
    strip.clear();
    playHappy();
  }
}

void playBashful() {
  for (int i = 0; i < bashfulCount; i++) {
    strip.setPixelColor(bashfulPixels[i], strip.Color(15, 0, 0));  
  }
}

void playHappy() {
  for (int i = 0; i < happyCount; i++) {
    strip.setPixelColor(happyPixels[i], strip.Color(10, 10, 0));  
  }
}
