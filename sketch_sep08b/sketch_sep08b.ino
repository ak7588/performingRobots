const int blueled = 9;
const int yelled = 8;
const int pushButton = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blueled, OUTPUT);
  pinMode(yelled, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushButton);
  bool prevState = false;
  Serial.println(buttonState);
  if (buttonState == 1 && prevState == LOW){
    digitalWrite(blueled, HIGH);
      digitalWrite(yelled, HIGH);
  } else {
     digitalWrite(blueled, LOW);
     digitalWrite(yelled, LOW);
  }
   prevState = buttonState;   
}
