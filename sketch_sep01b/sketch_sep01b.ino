const int pinOne = 12;
const int pinTwo = 13;
const int buttonPinOne = 2;
const int buttonPinTwo = 3;

int buttonStateOne = 0;
int buttonStateTwo = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  buttonStateOne = digitalRead(buttonPinOne)
  buttonStateTwo = digitalRead(buttonPinTwo)
  
  if buttonStateOne == 1 {
    digitalWrite(pinOne, HIGH);
  } else {
    digitalWrite(pinOne, LOW);
  }

  if buttonStateTwo == 1 {
    digitalWrite(pinTwo, HIGH);
  } else {
    digitalWrite(pinTwo, LOW);
  }
}
