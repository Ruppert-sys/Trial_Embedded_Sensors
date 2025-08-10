int lightPin = 0; //Photoresistor Pin

void setup() { //set outputs and inputs
pinMode(12, OUTPUT); //a
pinMode(11, OUTPUT); //b
pinMode(10, OUTPUT); //c
pinMode(9, OUTPUT); //p
pinMode(8, OUTPUT); //f
pinMode(7, OUTPUT); //g
pinMode(6, OUTPUT); //e
pinMode(5, OUTPUT); //d
  Serial.begin(9600); // Monitor
}

void loop() {
  
      int lightLevel = analogRead(lightPin); //Read the lightlevel
      lightLevel = map(lightLevel, 50, 120, 0, 9);
      Serial.println(lightLevel);
      int l = lightLevel;
      if(l==0){zero();}
      if(l==1){one();}
      if(l==2){two();}
      if(l==3){three();}
      if(l==4){four();}
      if(l==5){five();}
      if(l==6){six();}
      if(l==7){seven();}
      if(l==8){eight();}
      if(l==9){nine();}
}
void one(){
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH); 
    delay(250);
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
}

void two(){
  digitalWrite(12, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(11, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW); 
}
void three(){
    digitalWrite(12, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(5, LOW); 
}
void four(){
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH); 
    delay(250);
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);  
}
void five(){
    digitalWrite(12, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);  
    digitalWrite(5, LOW); 
}
void six(){
    digitalWrite(12, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);  
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW); 
}
void seven(){
   digitalWrite(12, HIGH); 
   digitalWrite(11, HIGH); 
   digitalWrite(10, HIGH);
    delay(250);
   digitalWrite(12, LOW); 
   digitalWrite(11, LOW); 
   digitalWrite(10, LOW); 

 
}
void eight(){
    digitalWrite(12, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);  
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW); 
}
void nine(){
    digitalWrite(12, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);  
    digitalWrite(5, LOW); 
}
void zero(){
    digitalWrite(12, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, HIGH); 
    delay(250);
    digitalWrite(12, LOW); 
    digitalWrite(11, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW); 
}
