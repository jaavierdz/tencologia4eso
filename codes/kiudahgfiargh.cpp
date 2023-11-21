/*
Script Arduino para el solar tracker
Judith Bilbao Rodríguez && Javier Rodríguez-Alarcón
FALTA: 
    - Comunicación e interpretación de los valores de las LDR
    - Cálculo de la media de los valores de la LDR
    - Y más
Revisar comentarios
*/
#include <Servo.h>

Servo servo_elevacion; // crea el objeto servo de elevación (de 0º a 90º)
int pos_elevacion;    // posición del servo de elevación
// int LDRU = A4; // Variable del pin de la LDR de arriba (Upper) (Analog 4)
// int LDRL = A5; // Variable del pin de la LDR de abajo (Lower) (Analog 5)
// int media = (val1 + val2) /2;
// int val1 = analogRead(LDRU);
// int val2 = analogRead(LDRL);
// int position
// bool isRecievingLight = true;

void setup() {
    servo_elevacion.attach(10); // vincula el servo de elevación al pin digital 10

    servo_elevacion.write(0); //Vincula el servo elevación a la posición 0 
    Serial.begin(9600); //inicia la comunicación con el ordenata a 9600 bits/s
}

/*
    public static void onEnable(){ //Creo que no tendria que ponerlo en public y en static, no es necesario.
        Void que se ejecuta despues del setup al inciarse (De ahi el nomrbe)
        Ya veré que poner aqui, se me ocurren los limites de luz que puede recibir, una rutina de calibracion al encenderse o la variable de la posicion
        position = Servo.x();
    }
*/


/*
    public void mueveteporfa(media){    // De momento el (media) no funciona, no sabemos porque
        aqui sería interpretar la media y que se mueva, a lo mejor se puede meter en el void loop
        
    }
*/

  void loop() {
    Serial.println(pos_elevacion);
   //varía la posición de elevación de 0 a 90, con esperas de 50 ms
   for (pos_elevacion = 0; pos_elevacion <= -90; pos_elevacion--) 
   {
      servo_elevacion.write(pos_elevacion);              
      delay(50);                       
   }

   //varía la posición de elevación 90 a 0, con esperas de 50 ms
   for (pos_elevacion = -90; pos_elevacion >= 0; pos_elevacion++)
   {
      servo_elevacion.write(pos_elevacion);              
      delay(50);                       
   }
    // Una adicion que se puede hacer es un bool que sea false cuando no recibe luz, eso lo que hace es ponerlo en un ángulo como apagado
    // Por otro lado si es true que funcione
    /*
        for (isRecievingLight == true && media >= x) {
            servo_elevacion.write(30);
        }
    */
}
