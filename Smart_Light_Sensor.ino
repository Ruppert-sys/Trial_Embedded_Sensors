#include<ESP8266WiFi.h>


const int SensorPin = A0;
static const uint8_t D1 = 16;

//int LowTH = 500;
//int HighTH = 600;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(D1, OUTPUT);
    pinMode(SensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int SensorValue = analogRead(SensorPin);

if (SensorValue <=100){

  digitalWrite(D1, HIGH);
  Serial.println("Sense is Dark, LED is On");
  
}
else{
  digitalWrite(D1, LOW);
  Serial.println(".......");
}
}
