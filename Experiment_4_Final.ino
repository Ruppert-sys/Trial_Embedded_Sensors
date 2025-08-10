#include <Servo.h> 
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include<WiFiClient.h>

Servo myservo;


const char *ssid = "PLDTHOMEFIBR66740";
const char *pass = "PLDTWIFIeqw7w";
WiFiClient client;
const char *server = "api.thingspeak.com";
unsigned long ChannelNum = 1843888;
const char *apiKey = "LHPLPDDOYVLM1Y0K";

int n=0;
int pos = 0;
void setup()
{
// put your setup code here, to run once:
pinMode(A0, INPUT);  
pinMode(D2,OUTPUT);
pinMode(D1,OUTPUT);// Soil Moisture Sensor 1 PIN A0
Serial.begin(9600);                                  //  Sensor Buart Rate
myservo.attach(D3);     

WiFi.begin(ssid,pass);
ThingSpeak.begin(client); //  Servo PIN D9
}
void loop()
{
// put your main code here, to run repeatedly:
int n= analogRead(A0);                         // Soil Moisture Sensor 1 PIN A0
delay(10);
Serial.println(n);
delay(1000);

if (n>=399)
{            // tell servo to go to position in variable 'pos'
myservo.write(0);
digitalWrite(D2, HIGH);
digitalWrite(D1, LOW);  
myservo.write(0);       // Relay ON
delay(1000);

}

else
{
myservo.write(180);  
digitalWrite(D2, LOW);
digitalWrite(D1,HIGH);
delay(1000);// Relay OFF

}
ThingSpeak.writeField(ChannelNum,1,n,apiKey);
}
