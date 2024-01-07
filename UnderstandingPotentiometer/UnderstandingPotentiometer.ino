#define PIN 5
void setup() {
  Serial.begin(9600);
  pinMode(PIN,OUTPUT);
}

void loop() {
  int ret = analogRead(PIN);
  Serial.println(ret);
  delay(1000);
}
