const int in1Pin = 5;
const int in2Pin = 4;
const int in3Pin = 7;
const int in4Pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // just moves
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  delay(1000);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
  delay(1000);

  // makes sounds 
  analogWrite(in1Pin, 15);
  digitalWrite(in2Pin, LOW);
  delay(1000);
  digitalWrite(in1Pin, LOW);
  analogWrite(in2Pin, 95);
  delay(1000);
  
}
