/*
  Performing Robots - Final Project
  Amina and Salama
  Bashful and Happy Dwarf
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "Sweeper.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN        7
#define NUMPIXELS 64

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

const int bashfulPixels[] = {9, 11, 13, 15, 18, 22, 28, 33, 38, 42, 43, 44, 45};
const int bashfulCount = 13;
const int happyPixels[] = {10, 14, 17, 19, 21, 23, 33, 36, 39, 42, 46, 51, 52, 53};
const int happyCount = 14;

const int happyPin = 7;
const int bashfulPin = 2;

const int CEPIN = 9;
const int CSNPIN = 10;
RF24 radio(CEPIN, CSNPIN);
const byte address[6] = "00001";

Sweeper servo(15);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  pinMode(happyPin, INPUT_PULLUP);
  pinMode(bashfulPin, INPUT_PULLUP);
  strip.begin();
  // RF24 setup
  bool retval = radio.begin();
  // Serial.println(retval);
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();
  servo.Attach(5);
}

void loop() {
  servo.Update();
  strip.show();
  uint8_t pipeNum;
  if (radio.available(&pipeNum))  //Looking for the data.
  {
    int data;

    Serial.print("data available on pipe ");
    Serial.println(pipeNum);

    radio.read(&data, sizeof(data));  //Reading the data
    Serial.print("data = ");
    Serial.println( data);


    switch (data) {
      case 0b00010000:
        Serial.println("turning right");
        strip.clear();
        playBashful();
        servo.Detach();
        break;
      case 0b00001000:
        Serial.println("forward");
        strip.clear();
        playHappy();
        servo.Attach(5);
        servo.Update();
        break;
      case 0b00000100:
        Serial.println("turning left");
        servo.Detach();
        break;
      default:
        Serial.println("invalid code");
        //servo.Detach();
        break;
    }
  } else {
    //Serial.println("stop");
  }
  delay(5);
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
