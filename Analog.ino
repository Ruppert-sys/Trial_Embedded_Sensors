 const int ledPin = 13;
const int ldrPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ldrPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrSTATUS = analogRead(ldrPin);

  if(ldrSTATUS <=50){
    digitalWrite(ledPin, HIGH);
    Serial.println("Room is Dark, Turn on the Light");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("........");
  }
}
