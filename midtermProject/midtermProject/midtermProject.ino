#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "pitches.h"
#include "MelodyPlayer.h"
#include "Sweeper.h"

const int CEPIN = 9;
const int CSNPIN = 10;
const byte address[6] = "00001";
const int melodyPin = 3;
const int red_light_pin = A2;
const int green_light_pin = A1;
const int blue_light_pin = A0;
RF24 radio(CEPIN, CSNPIN);
Sweeper left(10);
Sweeper right(10);
MelodyPlayer myTune(melodyPin);

bool twoIsPressed = false;
bool oneIsPressed = false;

const int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// Motor controller pins
const int rightDirPin = 4;
const int rightPWMPin = 5;
const int leftDirPin = 7;
const int leftPWMPin = 6;

void setup() {
    // Motor controller pins
  pinMode(rightDirPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  Serial.begin(115200);
  // RF24 setup
  bool retval = radio.begin();
  // Serial.println(retval);
  radio.openReadingPipe(0, address);  // Destination address 
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();    
  // LED setup
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  unsigned long time = millis();
  if (radio.available())  //Looking for the data.
  {
    int data;
    radio.read(&data, sizeof(data));  //Reading the data
    switch (data) {
        break;
      case 0x01:
        oneIsPressed = true;
        twoIsPressed = false;
        break;
      case 0x02:
        twoIsPressed = true;
        oneIsPressed = false;
        break;
      case 0x04:
        oneIsPressed = false;
        twoIsPressed = false;
        break;
      default:
        break;
    }
  } else {
    RGB_color(LOW, LOW, LOW);
    Serial.println("stop");
    stop();
  }

  if (twoIsPressed) {
    RGB_color(255, 255, 0);
    myTune.startPlaying();
    myTune.update();
    left.Detach();
    right.Detach();
    Serial.println("forward");
    digitalWrite(rightDirPin, LOW);
    analogWrite(rightPWMPin, 255);
    digitalWrite(leftDirPin, HIGH);
    analogWrite(leftPWMPin, 0);  
  } else if (oneIsPressed) {
    RGB_color(255, 0, 0);
    Serial.println("turning right");
    digitalWrite(rightDirPin, LOW);
    analogWrite(rightPWMPin, 200);
    myTune.stopPlaying();
    left.Attach(A3);
    right.Attach(A4);
    left.Update();
    right.Update();
  } 
  delay(5);
}

void stop() {
  digitalWrite(rightDirPin, LOW);
  analogWrite(rightPWMPin, 0);
  digitalWrite(leftDirPin, LOW);
  analogWrite(leftPWMPin, 0);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
