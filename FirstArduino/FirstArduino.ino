const int pin = 2;
//const int threshold = 150;
void setup() {
  pinMode(pin,OUTPUT);
}

void loop() {
  digitalWrite(pin,HIGH);
  delay(5000);//logically, this is how long the LED is ON for
  digitalWrite(pin,LOW);
  delay(5000);
}
