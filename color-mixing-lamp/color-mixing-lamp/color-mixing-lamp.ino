const int greenledpin = 9;
const int redledpin = 11;
const int blueledpin = 10;
const int redsensorpin = A0;
const int greensensorpin = A1;
const int bluesensorpin = A2;
int redvalue = 0;
int bluevalue = 0;
int greenvalue = 0;
int redsensorvalue = 0;
int greensensorvalue = 0;
int bluesensorvalue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //turn on serial monitor
  //set pinmodes to output
  pinMode(greenledpin,OUTPUT);
  pinMode(redledpin,OUTPUT);
  pinMode(blueledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redsensorvalue = analogRead(redsensorpin);
  delay(5);
  greensensorvalue = analogRead(greensensorpin);
  delay(5);
  bluesensorvalue = analogRead(bluesensorpin);
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redsensorvalue);
  Serial.print("\t Green: ");
  Serial.print(greensensorvalue);
  Serial.print("\t Blue: ");
  Serial.println(bluesensorvalue);
  redvalue = redsensorvalue/4;
  greenvalue = greensensorvalue/4;
  bluevalue = bluesensorvalue/4;
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redvalue);
  Serial.print("\t Green: ");
  Serial.print(greenvalue);
  Serial.print("\t Blue: ");
  Serial.println(bluevalue);
  analogWrite(redledpin, redvalue);
  analogWrite(greenledpin, greenvalue);
  analogWrite(blueledpin, bluevalue);
  delay(500);
}
