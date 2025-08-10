#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float value;
int temp = A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(temp,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(temp)* 0.4882815;
  value = (value - 0.5)*100.00;
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(value); 
  delay(1000);
  lcd.println();
  
}
