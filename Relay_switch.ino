int button = 7;
int relayPin= 8;

int pushState= 0;
int lightON = 0; 
int pushValue= 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  pinMode(relayPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pushValue = digitalRead(button);

  if(pushValue == HIGH && lightON == LOW){
      pushState = 1- pushState; 
      delay(100);
  }
   lightON = pushValue;

   if(pushState == HIGH){
    Serial.println("Light ON");
    digitalWrite(relayPin,HIGH);
   }

   else{
    Serial.println("Light OFF");
    digitalWrite(relayPin,LOW);
   }
  
}
