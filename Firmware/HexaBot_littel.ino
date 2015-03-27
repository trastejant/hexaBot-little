/**/

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

  delay(1000);
} 

void start(){
//Secuencia de encendido

  pata1_falangeProximal.write(90);
  pata2_falangeProximal.write(90);
  pata3_falangeProximal.write(90);
  pata4_falangeProximal.write(90);
  pata5_falangeProximal.write(90);  
  pata6_falangeProximal.write(90);
  
  pata1_falangeDistal.write(90);
  pata2_falangeDistal.write(90);
  pata3_falangeDistal.write(90);
  pata4_falangeDistal.write(90);
  pata5_falangeDistal.write(90);  
  pata6_falangeDistal.write(90);
  
  pata1_falangeMedia.write(90);
  pata2_falangeMedia.write(90);
  pata3_falangeMedia.write(90);
  pata4_falangeMedia.write(90);
  pata5_falangeMedia.write(90);  
  pata6_falangeMedia.write(90);

} 

void checkin(){
//Rutina de comprobacion del funcionamiento de las patas
} 

int distancia(){
  return ultrasonic.Ranging(CM); 
} 

int tilt(){
  int pos[] = {analogRead(A1), analogRead(A2), analogRead(A3) };
} 

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
      return 501;
    } 

} 
