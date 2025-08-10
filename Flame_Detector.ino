//#include<ESP8266WiFi.h>
//#define pmPin D2

const int flamepin = D3;
const int soundpin = D4;
int LED = A0;
int Flame = LOW;

/*WiFiClient client;
  const char *ssid = "PLDTHOMEFIBR66740";
  const char *pass = "PLDTWIFIeqw7w";
  unsigned long ChannelNum = 1851111;
  const char *apiKey = "4V1J4SO7X96URE79";
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(flamepin, INPUT);
  pinMode(soundpin, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  // WiFi.begin(ssid,pass);
  // ThingSpeak.begin(client);

}

void loop() {

  // put your main code here, to run repeatedly:
  Flame = digitalRead(flamepin);

  //  int Value = analogRead(pmPin);
  //  int brightness = Value / 4;
  //  analogWrite(flamepin,brightness);
  // if(Flame == 1) {
  // delay(100);
  // digitalWrite(LED,HIGH);
  // digitalWrite(soundpin,HIGH);
  // Serial.println("Temperature:"+flamepin);
  // delay(200);
  // }
  // else{
  // digitalWrite(soundpin,LOW);
  // digitalWrite(LED,LOW);
  // Serial.println("Temperature:"+flamepin);
  // delay(200);
  // }
  if (Flame == HIGH)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(soundpin, HIGH);
    Serial.println("FIRE! FIRE! FIRE!");
    Serial.println("Temperature:" + Flame);
  }
  else {
    Serial.println("CHILL NO FIRE!");
    digitalWrite(LED, LOW);
    digitalWrite(soundpin, LOW);
    Serial.println("Temperature:" + Flame);
  }
  delay(6000);
  //  ThingSpeak.writeField(ChannelNum,1,flamepin,apiKey);

}
