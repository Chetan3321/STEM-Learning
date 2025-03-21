//MACROS are defined here
uint8_t LED = 17;

void setup() {
  //Setup code goes here, to run once
  pinMode(LED, OUTPUT);

}

void loop() {
  //Main code goes here, to run repeatedly
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);

}