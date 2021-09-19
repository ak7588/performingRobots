const int in1Pin = 5;
const int in2Pin = 4;
const int in3Pin = 7;
const int in4Pin = 6;
const int button_one = 2;
const int button_two = 12;
int button_two_state;
boolean prevState = 0;
boolean flag1 = 0;
boolean flag2 = 0;
unsigned long delayTime = 0;

void setup() {
  delayTime = millis();
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  // move in one direction before 7 seconds passed
  if ((millis() - delayTime) >= 7000) {
      if (digitalRead(button_one) == HIGH) {
        digitalWrite(in4Pin, LOW);
        digitalWrite(in3Pin, HIGH);
      } else {
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
      }
    
      if (digitalRead(button_two) == HIGH) {
         digitalWrite(in1Pin, LOW);
         digitalWrite(in2Pin, HIGH);
      } else {
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
      }
  // change direction to go backwards    
  } else {
      if (digitalRead(button_one) == HIGH) {
        digitalWrite(in3Pin, LOW);
        digitalWrite(in4Pin, HIGH);
      } else {
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
      }
    
      if (digitalRead(button_two) == HIGH) {
         digitalWrite(in2Pin, LOW);
         digitalWrite(in1Pin, HIGH);
      } else {
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
      }
  }
}
