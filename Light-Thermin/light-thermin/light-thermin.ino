int sensorvalue;
int sensorlow = 1023;
int sensorhigh = 0;
const int ledpin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);
  while (millis() < 5000) {
    sensorvalue = analogRead(A0);
    if (sensorvalue > sensorhigh) {
      sensorhigh = sensorvalue;
    }
    if (sensorvalue < sensorlow) {
      sensorlow = sensorvalue;
    }
  }
  digitalWrite(ledpin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue = analogRead(A0);
  int pitch = map(sensorvalue,sensorlow,sensorhigh, 50, 4000);
  tone(8,pitch,20);
  delay(10);
}
