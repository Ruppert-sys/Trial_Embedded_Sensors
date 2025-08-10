float Temp;
float Value = A0;
double Yellow = 12;
double Green =11;
double Red =13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
   Temp = analogRead(Value);
    Temp = (Temp * 500)/1024;
    Serial.print("Temp:");
    Serial.print(Temp);
    Serial.print("*C");
    Serial.println("");
    delay(1000);
    
   if( Temp >= 21)//60-110
   {
    digitalWrite(Yellow,HIGH);
    //digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
    delay(1000);
   }
   if(Temp <= 20)//0-30
   {
    digitalWrite(Green,HIGH);
    //digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    delay(1000);
   }
     
}
