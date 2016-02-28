const int switchpin = 2;
const int motorpin = 9;
int switchstate = 0;
int motorspeed = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorpin, OUTPUT);
  pinMode(switchpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchstate = digitalRead(switchpin);
  if (switchstate == HIGH) {
    analogWrite(motorpin, motorspeed);
    if (motorspeed < 255) {
      motorspeed ++;
      delay(100);
    }
  }
  else {
    analogWrite(motorpin, 0);
    motorspeed = 20;
  }
}
