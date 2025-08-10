#include <Servo.h>
Servo motor;
int i;
void setup() {
  // put your setup code here, to run once:
  motor.attach(9);
  motor.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<180;i++)
  {
  motor.write(i);
  delay(10);
}
  for(i=180;i>=1;i--){
  motor.write(i);
  delay(10);
}

}
