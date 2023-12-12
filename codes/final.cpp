#include <Servo.h> 
 
Servo myservo;   
int LDR1 = 0;  
int LDR2 = 1;
int val1 = 0;   
int val2 = 0;
int diferencia = val1 - val2;
int calibration = 20;  
int pos = 90;    
 
void setup() 
{ 
  myservo.attach(11);  
} 
 
 
void loop() { 
  val1 = calibration + analogRead(LDR1);    
  val2 = analogRead(LDR2);
  if (val1<120 && val2<20){  
    while(pos<=160)
    {
      pos++;
      myservo.write(pos);
      delay(100);
    }
  }        
  if (diferencia>15){
    if(pos<=160)  
    {
      pos++;
      myservo.write(pos);  
    }
  }
  else if (diferencia<-15)  
  {
    if (pos>20)  
    {
      pos--;
      myservo.write(pos);  
    }
  }
  delay(100);
} 
