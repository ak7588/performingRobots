const int in1Pin = 5;
const int in2Pin = 4;
const int in3Pin = 7;
const int in4Pin = 6;
const int button = 2;
boolean prevState = 0;
boolean flag = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  Serial.println(button);
  // put your main code here, to run repeatedly:
  
  int buttonState = digitalRead(button);
  Serial.println(buttonState);

  // so that it stays on while the button is pressed once
  if (buttonState == 1 && prevState == 0) {
      flag = !flag;
  }

  if (flag) {
      // both just move
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, LOW);
      digitalWrite(in3Pin, HIGH);
      digitalWrite(in4Pin, LOW);
      delay(1000);
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, HIGH);
      digitalWrite(in3Pin, HIGH);
      digitalWrite(in4Pin, HIGH);
      delay(1000);
  }

  prevState = buttonState;
}
