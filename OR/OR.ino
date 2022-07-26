#include "math.h"  
byte p1 , p2 ;  //variables de entrada
float n1 , n2 , n3 ; // variables de las salidas de las neuronas
float a1 , a2 ; // las salidas de las funciones de activacion 
float e=2.7182818 ; // Definimos e para trabjar con la tanjente hiperbolica

void setup() { 
   pinMode (7 , INPUT); 
   pinMode (8 , INPUT); 
   pinMode (13 , OUTPUT);
   Serial.begin(9600);
  }

  
void loop()
{
   p1=digitalRead ( 7 );  //definimos pin 7 de entrada
   p2=digitalRead ( 8 ) ; //definimos pin 8 de entrada
   Serial.print(p1);
   Serial.print(" ");
   Serial.print(p2);
   Serial.print(" ");
   // definimos la sumatoria de nuestra neurona
   n1= p1 * (-2.8674) + p2 * (-2.4581) + (4.8654) ;
   n2 = p1 * (-2.0679) + p2 * (-3.3273) + (0.5961) ; 
   a1 = tansig ( n1 ) ; 
   a2 = tansig ( n2 );
   
   //capa de la neurona
   
   n3 = a1 * (0.0327) + a2 * (-0.6741) + ( 0.3333) ; 
   n3=round(n3); //redondeamos para que no salga - negativos 
   digitalWrite ( 13 , n3 );
   Serial.println(n3);


}

// definimos la funcion tangente hiperbolica
// funcion tansig
float tansig ( float x ) { 
  float a ; 
  
  a = ( pow ( e , x ) -pow ( e , -x ) ) / ( pow ( e , x ) + pow ( e , -x ) ) ; 
  return a ; // regreseamos el valor de a
  }
