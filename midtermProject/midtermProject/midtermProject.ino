#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "pitches.h"

const int CEPIN = 9;
const int CSNPIN = 10;
const byte address[6] = "00001";
const int melodyPin = 3;
const int red_light_pin = A2;
const int green_light_pin = A1;
const int blue_light_pin = A0;
RF24 radio(CEPIN, CSNPIN);
Servo left_hand;
Servo right_hand;

// Melody setup
unsigned long previousMillis = 0;
const int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
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
  // servo
  left_hand.attach(1);
  right_hand.attach(2);
}

void loop() {
  if (radio.available())  //Looking for the data.
  {
    int data;
    radio.read(&data, sizeof(data));  //Reading the data
    //Serial.println(data);
    switch (data) {
        break;
      case 0x01:
        RGB_color(0, 255, 0);
        Serial.println("turning right");
        digitalWrite(rightDirPin, LOW);
        analogWrite(rightPWMPin, 200);
        playMelody();
        break;
      case 0x02:
        RGB_color(255, 0, 0);
        Serial.println("forward");
        digitalWrite(rightDirPin, HIGH);
        analogWrite(rightPWMPin, 0);
        digitalWrite(leftDirPin, LOW);
        analogWrite(leftPWMPin, 255);
        break;
      case 0x04:
        RGB_color(0, 255, 0);
        Serial.println("turning left");
        digitalWrite(leftDirPin, HIGH);
        analogWrite(leftPWMPin, 50);
        playMelody();
        break;
      default:
        RGB_color(LOW, LOW, LOW);
        Serial.println("invalid code");
        stop();
        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, LOW);
        break;
    }
  } else {
    RGB_color(LOW, LOW, LOW);
    Serial.println("stop");
    stop();
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

void playMelody() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    unsigned long currentMillis = millis();
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    if (currentMillis - previousMillis >= pauseBetweenNotes) {
      previousMillis = currentMillis;
      noTone(3);
    }
  }
}

void moveHands() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    left_hand.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    right_hand.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
