#include "pitches.h"
#include "setlist.h"

#define SPEAKER 4
#define LED 9
int NOTE_DUR = 137;

const int song1threshold = 300;
const int song2threshold = 650;
const int song3threshold = 1023;

void play(int note, int dur){
  tone(SPEAKER,note);
  delay(dur * NOTE_DUR);
  noTone(SPEAKER);
  delay(dur* NOTE_DUR/3);
}

void song1();
void song2();
void song3();
void flash_led();

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER,OUTPUT);
  pinMode(LED,OUTPUT);
}
void loop() {
  int sensorval = analogRead(A2);//potentiometer is on Pin A2
  Serial.println(sensorval);
  if(sensorval <= song1threshold ){
    song1();
  }else if(sensorval >= song1threshold && sensorval <= song2threshold){
    song2();
  }else{
    song3();
  }    
}

//Flash LED 1x for Song1, 2x for Song2, 3x for Song3
void flash_led(){
  digitalWrite(LED,HIGH);
  delay(2000);
  digitalWrite(LED,LOW);
  delay(2000);
}

void song1(){
  flash_led();
  play(NOTE_A3,5);
  play(NOTE_B3,5);
  play(NOTE_C3,5);
  play(NOTE_D3,5);
  play(NOTE_E3,5);
  play(NOTE_F3,5);
}

void song2(){
  flash_led();
  flash_led();
  play(NOTE_A1,5);
  play(NOTE_B1,5);
  play(NOTE_C1,5);
  play(NOTE_D1,5);
  play(NOTE_E1,5);
  play(NOTE_F1,5);

}

void song3(){
  flash_led();
  flash_led();
  flash_led();
  play(NOTE_A6,5);
  play(NOTE_B6,5);
  play(NOTE_C6,5);
  play(NOTE_D6,5);
  play(NOTE_E6,5);
  play(NOTE_F6,5);

}