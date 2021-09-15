const int in1Pin = 5;
const int in2Pin = 4;
const int in3Pin = 7;
const int in4Pin = 6;
const int button_one = 2;
const int button_two = 12;
int button_two_state;
boolean prevState = 0;
boolean flag = 0;

void setup() {

  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {

  if (digitalRead(button_one) == HIGH) {
    if (digitalRead(button_two) == HIGH) {
        digitalWrite(in3Pin, HIGH);
        digitalWrite(in4Pin, HIGH);
        delay(1000);
        digitalWrite(in3Pin, LOW);
        digitalWrite(in4Pin, HIGH);
    } else {
      digitalWrite(in3Pin, HIGH);
      digitalWrite(in4Pin, HIGH);
      delay(1000);
      digitalWrite(in3Pin, HIGH);
      digitalWrite(in4Pin, LOW);
    }
   } else {
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, HIGH);
   }
}
