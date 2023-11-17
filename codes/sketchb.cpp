/*
  Tecnologia 4ºESO
  
*/
#include <Servo.h>
Servo myservo;


int angulo = 20;
int motorPin = 10;
const int LDR1 = A4;
const int LDR2 = A5;
int val1 = analogRead(LDR1);
int val2 = analogRead(LDR2);
int media = (val1 + val2)/2;
const int limiteluz = 200;
const int LimiteSup = 45;
const int LimiteInf = 120;
int posicion = 45;

void setup(){
    posicion = myservo.read();
    myservo.attach(motorPin);
    myservo.write(angulo);
    Serial.begin(9600);
}
void mueveteporfa(promedio){
      if (media > limiteluz && posicion < Limitesup) {
        posicion --;
        myservo.write(posicion);
      }
      else{
        if (media > limiteluz && posicion > Limiteinf){
          posicion ++;
          myservo.write(posicion);
        }
      }
    }
void loop(){

    

}