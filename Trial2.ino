#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include<WiFiClient.h>
int pinIR = D1;
int sound = D0;
const int LEDgreen = D2;
const int LEDred = D3;
int value;

WiFiClient client;
  const char *ssid = "PLDTHOMEFIBR66740";
  const char *pass = "PLDTWIFIeqw7w";
  unsigned long ChannelNum = 1851111;
  const char *apiKey = "4V1J4SO7X96URE79";
  
void setup() {
 Serial.begin(115200);
 pinMode(pinIR,INPUT);
 pinMode(sound,OUTPUT);
 pinMode(LEDgreen,OUTPUT);
 pinMode(LEDred,OUTPUT);
 WiFi.begin(ssid,pass);
 ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
   value = digitalRead(pinIR);
   Serial.println(" Temperature:"+value);

   if(value == 1){
     digitalWrite(D0,LOW);
    digitalWrite(LEDgreen,HIGH);
    digitalWrite(LEDred,LOW);
    Serial.println("CHILL NO FIRE!");
   }
   else{
    digitalWrite(D0,HIGH);
    digitalWrite(LEDred,HIGH);
    digitalWrite(LEDgreen,LOW);
    Serial.println("FIRE! FIRE! FIRE!");
   }
   ThingSpeak.writeField(ChannelNum,4,value,apiKey);
   delay(6000);
}
