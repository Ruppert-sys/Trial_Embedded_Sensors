#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>;
#include<WiFiClient.h>;
#include<BlynkSimpleEsp8266.h>

const int stepper1 =D4;
const int stepper2 =D5;
const int stepper3 =D6;
const int stepper4 =D7;
int step_num = 0;
void setup() {
  pinMode(stepper1,OUTPUT);
  pinMode(stepper2,OUTPUT);
  pinMode(stepper3,OUTPUT);
  pinMode(stepper4,OUTPUT);
}

void loop() {
  for(int a = 0;a<1000;a++){
  OneStep(false);
  delay(10);
  }
  for(int a = 0;a<1000;a++){
  OneStep(true);
  delay(10);
  }

}

void OneStep(bool dir){
  if(dir){
    switch(step_num){
      case 0:
      digitalWrite(stepper1,HIGH);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,LOW);
      break;
      case 1:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,HIGH);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,LOW);
      break;
      case 2:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,HIGH);
      digitalWrite(stepper4,LOW);
      break;
      case 3:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,HIGH);
      break;
    }
}
else{
  switch(step_num){
      case 0:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,HIGH);
      break;
      case 1:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,HIGH);
      digitalWrite(stepper4,LOW);
      break;
      case 2:
      digitalWrite(stepper1,LOW);
      digitalWrite(stepper2,HIGH);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,LOW);
      break;
      case 3:
      digitalWrite(stepper1,HIGH);
      digitalWrite(stepper2,LOW);
      digitalWrite(stepper3,LOW);
      digitalWrite(stepper4,LOW);
      break;
  }
  
}
step_num++;
if(step_num>3){
  step_num=0;
}
}
