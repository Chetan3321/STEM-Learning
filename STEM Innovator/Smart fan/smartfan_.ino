//MACROS are defined here
uint8_t myVar = 17;
uint8_t myMotor_1 = 4;
uint8_t myMotor_2 = 0;
uint8_t myMotor_1_chnl = 2;

#define myUltrasonic_E 2
#define myUltrasonic_T 15

float getDistance(int trig,int echo){
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH)/58.8;
}

void setup() {
  //Setup code goes here, to run once
  pinMode(myVar, INPUT);
  ledcSetup(myMotor_1_chnl, 5000, 8);
  ledcAttachPin(myMotor_1,myMotor_1_chnl);
  pinMode(myMotor_2, OUTPUT);

}

void loop() {
  //Main code goes here, to run repeatedly
  if (getDistance(myUltrasonic_T, myUltrasonic_E) < 20) {
    ledcWrite(myMotor_1_chnl,2.55*50);
    digitalWrite(myMotor_2,HIGH);
    delay(3000);
    ledcWrite(myMotor_1_chnl,2.55*70);
    digitalWrite(myMotor_2,HIGH);
    delay(3000);
    ledcWrite(myMotor_1_chnl,2.55*100);
    digitalWrite(myMotor_2,HIGH);
    delay(3000);
  }
  if (digitalRead(myVar) == 1) {
    ledcWrite(myMotor_1_chnl,2.55*0);
    digitalWrite(myMotor_2,HIGH);
    delay(3000);
  }

}