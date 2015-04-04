/*
HexaBot_littel firmware 
Copyright (C) 2015 Crakernano 4 Trastejant


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

https://github.com/trastejant/hexaBot-little
http://www.trastejant.es
*/

#include <Servo.h>
#include <Ultrasonic.h>

//declaracion de objetos para control de las patas

Servo pata1_falangeProximal;
Servo pata2_falangeProximal;
Servo pata3_falangeProximal;
Servo pata4_falangeProximal;
Servo pata5_falangeProximal;
Servo pata6_falangeProximal;

Servo pata1_falangeDistal;
Servo pata2_falangeDistal;
Servo pata3_falangeDistal;
Servo pata4_falangeDistal;
Servo pata5_falangeDistal;
Servo pata6_falangeDistal;

Servo pata1_falangeMedia;
Servo pata2_falangeMedia;
Servo pata3_falangeMedia;
Servo pata4_falangeMedia;
Servo pata5_falangeMedia;
Servo pata6_falangeMedia;

//Agrupamos los motores de cada pata en un array
Servo pata1[] = {pata1_falangeProximal,pata1_falangeMedia,pata1_falangeDistal}; 
Servo pata2[] = {pata2_falangeProximal,pata2_falangeMedia,pata2_falangeDistal}; 
Servo pata3[] = {pata3_falangeProximal,pata3_falangeMedia,pata3_falangeDistal}; 
Servo pata4[] = {pata4_falangeProximal,pata4_falangeMedia,pata4_falangeDistal}; 
Servo pata5[] = {pata5_falangeProximal,pata5_falangeMedia,pata5_falangeDistal}; 
Servo pata6[] = {pata6_falangeProximal,pata6_falangeMedia,pata6_falangeDistal}; 

//Array de motores
Servo motores[] = {pata1_falangeProximal,pata1_falangeMedia,pata1_falangeDistal,
                   pata2_falangeProximal,pata2_falangeMedia,pata2_falangeDistal,
                   pata3_falangeProximal,pata3_falangeMedia,pata3_falangeDistal,
                   pata4_falangeProximal,pata4_falangeMedia,pata4_falangeDistal,
                   pata5_falangeProximal,pata5_falangeMedia,pata5_falangeDistal,
                   pata6_falangeProximal,pata6_falangeMedia,pata6_falangeDistal
}; 

Ultrasonic ultrasonic(48,49); // (Trig PIN,Echo PIN)

void setup(){ 
  pata1_falangeProximal.attach(2);
  pata2_falangeProximal.attach(3);
  pata3_falangeProximal.attach(4);
  pata4_falangeProximal.attach(5);
  pata5_falangeProximal.attach(6);  
  pata6_falangeProximal.attach(7);
  
  pata1_falangeDistal.attach(8);
  pata2_falangeDistal.attach(9);
  pata3_falangeDistal.attach(10);
  pata4_falangeDistal.attach(11);
  pata5_falangeDistal.attach(12);  
  pata6_falangeDistal.attach(13);
  
  pata1_falangeMedia.attach(14);
  pata2_falangeMedia.attach(15);
  pata3_falangeMedia.attach(16);
  pata4_falangeMedia.attach(17);
  pata5_falangeMedia.attach(18);  
  pata6_falangeMedia.attach(19);
  
   Serial.begin(9600); 
   Serial.println("Ready");   
   start();
} 
 
void loop() { 
  Serial.print(distancia()); // CM or INC
  Serial.println(" cm" );
  
  Serial.print("X: " );
  Serial.print(analogRead(A1)); 
  Serial.print(" Y: " );
  Serial.print(analogRead(A2)); 
  Serial.print(" Z: " );
  Serial.println(analogRead(A3)); 

  delay(1000);//Esperamos un segundo antes de repetir el bucle
} 

void start(){
//Secuencia de encendido

  for(int i= 0; i<4; i++){pata1[i].write(90);}//Centrar servos de la pata 1
  for(int i= 0; i<4; i++){pata2[i].write(90);}//Centrar servos de la pata 2
  for(int i= 0; i<4; i++){pata3[i].write(90);}//Centrar servos de la pata 3
  for(int i= 0; i<4; i++){pata4[i].write(90);}//Centrar servos de la pata 4
  for(int i= 0; i<4; i++){pata5[i].write(90);}//Centrar servos de la pata 5
  for(int i= 0; i<4; i++){pata6[i].write(90);}//Centrar servos de la pata 6

} 

//Rutina de comprobacion del funcionamiento de las patas
void checkin(){
//El bucle recorre todos los sermotores del robot
for(int i = 0; i < sizeof(motores); i++){
  moverPata(motores[i],90);//Colocamos la pata en la mitad de su recorrido
  delay(500);//Damos tiempo al servo para posicionarse
    if(motores[i].read()==90){
      
      /*Comprobamos si el servo esta en la posicion que deberia estar
      Si lo esta mandamos un mensaje por consola indicandolo*/
      Serial.print("Motor ");
      Serial.print(i);
      Serial.println("it OK");  
    }else{
      /*Si no esta en la posicion correcta reintentamos posicionar la pata*/
      moverPata(motores[i],90);
      delay(500);
      
      if(posicionPata(motores[i],90)){
        /*Comprobamos de nuevo la posicion de la pata, 
        si se ha posicionado correctamente mandamos
        un mensaje por consola que lo indique*/
        Serial.print("Motor ");
        Serial.print(i);
        Serial.println("it OK");  
      
      }else{
        //Si sigue sin estar en posicion, mandamos un error por consola
            Serial.print("Motor ");
            Serial.print(i);
            Serial.println("ERROR");  
            }//Fin del else
    }//Fin del else
      
  }//Fin del bucle 

}//fin del procedimiento

//devuelve la distancia medida por el sensor de ultrasonidos(EN CM)
int distancia(){return ultrasonic.Ranging(CM);} 

//Coloca un motor en la posicion dada
void moverPata(Servo motor, int pos){ motor.write(pos);}

//Comprueba si la posicion de un servomotor con la posicion dada
boolean posicionPata(Servo motor, int pos){if(motor.read() == pos){return true;}else{return false;}}

//Devuelve la posicion de un sermotor
float posicionPata(Servo motor){return motor.read();}

//Devuelve un array con las posiciones X,Y,Z leidas por el acelerometro
int tilt(){int pos[] = {analogRead(A1), analogRead(A2), analogRead(A3) };} 

//Devuelve el valor medido por el acelerometro en el eje dado
int titlt(char d){
  
  switch (d) {
    case 'x':    
         return analogRead(A1);
      break;
      
    case 'y':    
        return analogRead(A2);
      break;
      
    case 'z':   
        return analogRead(A3);
      break;
      
    default:
      return 501;//Enviamos el codigo 501 que detectaremos como error
    } 

} 
