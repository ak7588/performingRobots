#include <Servo.h>

const int buttonPinOne = 12;
const int buttonPinTwo = 13;
const int redLed = 8;
const int greenLed = 7;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservoTwo;
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoTwo.attach(3);
}

void loop() {
  int buttonStateOne = digitalRead(buttonPinOne);
  int buttonStateTwo = digitalRead(buttonPinTwo);
  Serial.println(buttonStateOne);
  Serial.println(buttonStateTwo);

  if (buttonStateOne) {
    for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } 

  if (buttonStateTwo) {
    for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
      myservoTwo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  } 
}
