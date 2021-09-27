int ledState = 0;
const int ledPin;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH) {
    ledState = 1 - ledState;
    digitalWrite(ledPin, ledState);  
  }
}
