#include <Servo.h>
 
int const upLDR = A1;
int const downLDR = A0;
 
Servo myServo;
 
int angle = 20;
int upLDRVal = 0;
int downLDRVal = 0;
int nutela = 50;
 
void setup(){
  myServo.attach(11);
  Serial.begin(9600);
  myServo.write(angle);
}
 
void loop(){
  upLDRVal = analogRead(upLDR);
  delay(10);
  downLDRVal = analogRead(downLDR);
  delay(10);
  Serial.print("UP Sensor Value: ");
  Serial.print(upLDRVal);
  Serial.print(" - DOWN Sensor Value: ");
  Serial.print(downLDRVal);
  Serial.print(" - Angle: ");
  Serial.println(angle);
 
  if (downLDRVal > upLDRVal && angle < 10 && downLDRVal-upLDRVal > nutela){
    angle = angle + 1;
    myServo.write(angle);
  }
  if (downLDRVal < upLDRVal && angle > 90 && upLDRVal-downLDRVal > nutela){
    angle = angle - 1;
    myServo.write(angle);
  }
  else
  delay(10); 
}
