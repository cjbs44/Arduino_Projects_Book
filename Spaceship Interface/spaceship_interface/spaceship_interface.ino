int switchstate = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchstate = digitalRead(2);
  //this is a comment
  if (switchstate == LOW) {
    //the button is not pressed
    digitalWrite(3, HIGH); //green LED
    digitalWrite(4, LOW); //red LED
    digitalWrite(5, LOW); //red LED
  }
  else { // the button is pressed
    digitalWrite(3, LOW); //green LED
    digitalWrite(4, LOW); //red LED
    digitalWrite(5, HIGH); //red LED
    delay(250); //wait for a quarter of a second
    //toggle the LEDs only if switch still closed
    switchstate = digitalRead(2);
    //re-read switch state
    if (switchstate == HIGH) { //only toggle red led's if switch still closed
      digitalWrite(4, HIGH); //red LED
      digitalWrite(5, LOW); //red LED
      delay(250); //wait for a further quarter of a second
    }
  }
} //go back to the beginning of the loop
