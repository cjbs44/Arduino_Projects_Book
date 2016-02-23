const int switchpin = 8;
unsigned long previoustime = 0;
int switchstate = 0;
int prevswitchstate = 0;
int led = 2;
long interval = 600000;

void setup() {
  // put your setup code here, to run once:
  for(int x = 2;x<8;x++){
    pinMode(x, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currenttime = millis();
  if(currenttime - previoustime > interval) {
    previoustime = currenttime;
    digitalWrite(led, HIGH);
    led++;
    if(led == 7){
    }
  }
  switchstate = digitalRead(switchpin);
  if(switchstate != prevswitchstate){
    for(int x = 2;x<8;x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    previoustime = currenttime;
  }
  prevswitchstate = switchstate;
}
