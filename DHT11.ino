#include "DHT.h"
//#include "LiquidCrystal.h"
#define DHTPIN 2
#define DHTTYPE DHT11

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


DHT dht(DHTPIN,DHTTYPE); 
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Humidity & Temperature");
    dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    delay(2000);
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();

    Serial.print("Humidity");
    Serial.print(hum);
    //Serial.setCursor(0,1);
    Serial.print("% Temperature:");
    Serial.print(temp);
    Serial.println("C");  
}
