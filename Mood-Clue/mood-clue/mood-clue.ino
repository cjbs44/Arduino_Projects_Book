#include <Servo.h>
Servo myservo;
int const potpin = A0;
int potval;
int angle;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(potpin);
  Serial.print("potval: ");
  Serial.print(potval);
  angle = map(potval, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  myservo.write(angle);
  delay(15);
}
