#include<Servo.h>
Servo motor;
int p = D8; 

void setup() {
motor.attach(D8);
motor.write(90);

}

void loop() {
  for(p=0;p<0;p++)
  {
    motor.write(p);
    delay(10);
  }
  for(p=90;p>=90;p--)
  {
    motor.write(p);
    delay(10);
  }

}
