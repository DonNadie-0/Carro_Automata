// C++ code

//Libreria para poder manejar el servoMotor
#include <Servo.h>

//Motor de la entrada 1
int motorA =11;

//Motor de la entrada 2
int motorB = 3;

//Variable del pin de servo
int servoPin = 9;

Servo dirrecion;
direccion_servo =dirrecion;
//Variables de los leds como indicador de dirrecionales:

int led_izquierda =7;
int led_derecha =6;

//Variables de los botones de las dirrecionales:
int boton_direccional_iz = 13;
int boton_direccional_de = 12;

/* Variables de los botones de la funciones ir hacia adelante
rapido y lento:
*/
int boton_hacia_adelanteR = 5;
int boton_hacia_adelanteD = 4;

/*Variables de los botones de ir hacia atras despacio y lento:
*/

int boton_hacia_atrasR = 8;
int boton_hacia_atrasD = 10;



void setup()
{
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  dirrecion.attach(servoPin);
  pinMode(led_izquierda, OUTPUT);
  pinMode(led_derecha, OUTPUT);
  pinMode(boton_direccional_iz, INPUT);
  pinMode(boton_direccional_de, INPUT);
  pinMode(boton_hacia_adelanteR, INPUT);
  pinMode(boton_hacia_adelanteD, INPUT);
  pinMode(8, INPUT);
  pinMode(10, INPUT);


}

void loop()
{ 
  //1er Condisional que permite activar el del la dirrecion izqu
  if(digitalRead(13) == HIGH){
    direccional_izquierda();
  }else{
    digitalWrite(led_izquierda,LOW);
  }
  
  //2undo Condisional que activa la dirrecional hacia la derecha
   if(digitalRead(12) == HIGH){
    direccional_derecha();
  }else{
    digitalWrite(led_derecha,LOW);
  }
  
  /*Condisional multiple que activa el ir hacia delante rapido
  Tambien si va hacia atras rapido o despacio*/
  if (digitalRead(boton_hacia_adelanteR) == HIGH) {
    adelanteR();   // rápido
  } 
  else if (digitalRead(boton_hacia_adelanteD) == HIGH) {
    adelanteD();   // despacio
  }
    
  else if(digitalRead(boton_hacia_atrasR) == HIGH){
      hacia_atrasR(); //Rapido
    
  }
   else if(digitalRead(boton_hacia_atrasD) == HIGH){
      hacia_atrasD(); //Atras despacio
    
  }
  //Apagar el motor despues de cada terminacion del condicional
  else{
    analogWrite(motorA, 0);
    analogWrite(motorB, 0);
  }
  
  
  
  //Condisional que activa ir hacia atras rapido o lento
 

  //Controla la velocidad analoga y si va en reversa 
  //analogWrite(motorA,0);
  //analogWrite(motorB,255);
  
  //Controla la dirrecion del servo
  dirrecion.write(90);
  delay(1000);
  dirrecion.write(45);
  delay(1000);
  

}
void direccional_izquierda(){
  digitalWrite(7, HIGH);
}
void direccional_derecha(){
  digitalWrite(led_derecha, HIGH);
}
void adelanteR(){
  analogWrite(motorA,0);
  analogWrite(motorB,255);
}
void adelanteD(){
  analogWrite(motorA,0);
  analogWrite(motorB,160);
}
void hacia_atrasR(){
  analogWrite(motorA,255);
  analogWrite(motorB,0);
}
void hacia_atrasD(){
  analogWrite(motorA,160);
  analogWrite(motorB,0);
}
