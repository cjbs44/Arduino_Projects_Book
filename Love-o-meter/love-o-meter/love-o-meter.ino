const int sensorpin = A0;
const float baselinetemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //open a serial port
  for(int pinnumber = 2; pinnumber < 5; pinnumber++){ //create a loop from 2 through 4
   pinMode(pinnumber, OUTPUT); //set the pin as an output
  digitalWrite(pinnumber, LOW); //set the pin low to turn off the led's
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorval = analogRead(sensorpin); // read the voltage from the Temp Sensor
  Serial.print("Sensor Value: ");
  Serial.print (sensorval); //print out the sensor value to the serial monitor
  // convert the ADC reading to a voltge 0-5 = 0-1023
  float voltage = (sensorval/1024.0) * 5.0;
  Serial.print(", volts: ");
  Serial.print(voltage); //print out the calculated voltage to the serial monitor
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  //tune on leds incrementaly 20C and every 2C after
  if(temperature < baselinetemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselinetemp+2 && temperature < baselinetemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselinetemp+4 && temperature < baselinetemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselinetemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
