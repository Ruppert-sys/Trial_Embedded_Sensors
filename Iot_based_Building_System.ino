#include<ESP8266WiFi.h>
#include<ThingSpeak.h>;
#include<WiFiClient.h>;

const int trigpin=D1;
const int echopin=D2;
const int ledPin1=D3;
const int ledPin2=D4;
const int ledPin3=D5;
const int ledPin4=D6;

long duration;
int distance;

WiFiClient client;
const char *ssid = "PLDTHOMEFIBR66740";
const char *pass = "PLDTWIFIeqw7w";
unsigned long ChannelNum = 1867961;
const char *apiKey = "274U3VK46JA2Z0JW";

void setup() {
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(ledPin4,OUTPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(115200);

WiFi.begin(ssid,pass);
ThingSpeak.begin(client);

}

void loop() {
digitalWrite(trigpin,LOW);
delayMicroseconds(20);

digitalWrite(trigpin,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin,LOW);

duration = pulseIn(echopin,HIGH);
distance = duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
delay(0);

if(distance>=1){
digitalWrite(ledPin1,HIGH);
//digitalWrite(ledPin2,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin4,LOW);
ThingSpeak.writeField(ChannelNum,1,ledPin1,apiKey);
}
else  
{
digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin2,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin4,LOW);
}
if(distance>=3){
digitalWrite(ledPin2,HIGH);
//digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin4,LOW);
ThingSpeak.writeField(ChannelNum,2,ledPin2,apiKey);
}
else {
 digitalWrite(ledPin2,LOW);
// digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin4,LOW);
}
if(distance>=5){
digitalWrite(ledPin3,HIGH);
//digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin2,LOW);
//digitalWrite(ledPin4,LOW);
ThingSpeak.writeField(ChannelNum,3,ledPin3,apiKey);
}
else {
digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin2,LOW);
//digitalWrite(ledPin4,LOW);
}
if(distance>=7){
digitalWrite(ledPin4,HIGH);
//digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin2,LOW);
ThingSpeak.writeField(ChannelNum,4,ledPin4,apiKey);
}
else {
digitalWrite(ledPin4,LOW);
//digitalWrite(ledPin1,LOW);
//digitalWrite(ledPin3,LOW);
//digitalWrite(ledPin2,LOW);
 }






}
