#include <Servo.h>
 
int const leftSensorPin = A0;
int const rightSensorPin = A1;
 
Servo myServo;
 
int angle = 90;
int leftSensorValue = 0;
int rightSensorValue = 0;
int colchon = 30;
 
void setup(){
  myServo.attach(11);
  Serial.begin(9600);
  myServo.write(angle);
}
 
void loop(){
  leftSensorValue = analogRead(leftSensorPin);
  delay(10);
  rightSensorValue = analogRead(rightSensorPin);
  delay(10);
  Serial.print("Left Sensor Value: ");
  Serial.print(leftSensorValue);
  Serial.print(" - Right Sensor Value: ");
  Serial.print(rightSensorValue);
  Serial.print(" - Angle: ");
  Serial.println(angle);
 
  if (rightSensorValue > leftSensorValue && angle > 5 && rightSensorValue-leftSensorValue > colchon){
    angle = angle - 5;
    myServo.write(angle);
  }
  if (rightSensorValue < leftSensorValue && angle < 175 && leftSensorValue-rightSensorValue > colchon){
    angle = angle + 5;
    myServo.write(angle);
  }
  else
  delay(10); 
}
