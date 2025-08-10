
// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#include<ESP8266WiFi.h>;
#include<ThingSpeak.h>;
#include<WiFiClient.h>;
#include <SimpleDHT.h>;
#include<Servo.h>
#include <DHT.h> 
#define BLYNK_TEMPLATE_ID "TMPL8Ru_6g-4"
#define BLYNK_DEVICE_NAME "Multiple Sensors"
#define APP_DEBUG
#include "BlynkEdgent.h"
#define DHTPIN D3
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI


const char *ssid = "PLDTHOMEFIBR66740";
const char *pass = "PLDTWIFIeqw7w";

Servo motor;
long duration;
int distance;

const int Sensor=A0;
const int LED=D0;
const int trigpin=D1;
const int echopin=D2;
//const int pinDHT11 = D3;
const int stepper1 =D4;
const int stepper2 =D5;
const int stepper3 =D6;
const int stepper4 =D7;
int p = D8; 
int step_num = 0;
DHT dht(DHTPIN, DHT11);

WiFiClient client;

unsigned long ChannelNum = 1843926;
const char *apiKey = "IWRTAZQTFX6NRWJB";
const char* data = "api.thingspeak.com";

void setup() {
 Serial.begin(115200);
 delay(100); 
 BlynkEdgent.begin();
 pinMode(Sensor,OUTPUT);
 pinMode(LED,OUTPUT);
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 pinMode(stepper1,OUTPUT);
 pinMode(stepper2,OUTPUT);
 pinMode(stepper3,OUTPUT);
 pinMode(stepper4,OUTPUT);
 motor.attach(D8);
 motor.write(180);
 dht.begin();
 Serial.println("Temperature and Humidity Data:");
 
 WiFi.begin(ssid,pass);
 ThingSpeak.begin(client);

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

void loop() {
// put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  BlynkEdgent.run();
  int light = analogRead(Sensor);
  if (light < 50){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
  Serial.println(light);
  delay(1000);


  {
digitalWrite(trigpin,LOW);
delayMicroseconds(2);

digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration = pulseIn(echopin,HIGH);
distance = duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);
 } 
  {
  for(int a = 0;a<1000;a++){
  OneStep(false);
  delay(10);
  }
  for(int a = 0;a<1000;a++){
  OneStep(true);
  delay(10);
  }

}

 {
  for(p=0;p<180;p++)
  {
    motor.write(p);
    delay(10);
  }
  for(p=180;p>=1;p--)
  {
    motor.write(p);
    delay(10);
  }

}

  if (client.connect(data,80)){
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" degrees Celcius, Humidity: ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
    delay(100);
  }

 
  ThingSpeak.writeField(ChannelNum,1,light,apiKey);
  ThingSpeak.writeField(ChannelNum,2,distance,apiKey);
  ThingSpeak.writeField(ChannelNum,3,h,apiKey);
  ThingSpeak.writeField(ChannelNum,4,step_num,apiKey);
  ThingSpeak.writeField(ChannelNum,5,p,apiKey);
  delay(100);
}
