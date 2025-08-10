 float temp;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(A0);
  temp = temp * 0.48828125;//((5/1024)*10);
  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}
