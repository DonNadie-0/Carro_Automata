// C++ code
//
#include<Servo.h> 
// lo anterior es la llamada a una libreria, es necesario para usar el Servo



// Motor a, pin 11 (input 1)
int motor1a = 11;
// motor b, pin 6 (input 2)
int motor1b = 6;
// el servo motor esta conectado al pin 9
int servoPin = 9;
// creacion del objeto de tipo Servo
Servo direccion;
// creacion de la variable de los cm del sensor
int centimetros = 0;
// creacion variable contador de objetos
int objetos = 0;
int botonStart=12;
int iteracion = 0;
bool comprobado = false;
unsigned long tiempoInicial = 0;
bool objetoDetectado = false;


void setup()
{
 
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  // metodo para inicializar el objeto del Servo
  direccion.attach(servoPin);
  pinMode(botonStart, INPUT);
  Serial.begin(9600); // con serial no se puede usar puerto 0 y 1 
  
}

 void loop()
 {
   // boton de arranque para ejecutar el programa
   if(digitalRead(botonStart)!= LOW && comprobado == false)
    {
      delay(200); 
  	  comprobado = true;
    }
   
   if(comprobado == true)
   {
	 programa();   
   }
     
 }

// funcion que ejecuta el programa
void programa()
{
  // arrancamos el carro a toda velocidad 
  adelanteRapido();
  
  // conversion para la medicion de los centimetros
  centimetros = 0.01723 * leecturaDistanciaUltrasonica(7,8);
	
  // condicional para contar objetos
   if(centimetros<200)                                                         
   {
     if(!objetoDetectado)
     {
  	    objetos = objetos + 1; // se detecto un objeto 
        objetoDetectado = true;
       if(objetos==1)
      {
     	tiempoInicial = millis(); 
      }
     } 
     
   } else
      {
     	objetoDetectado=false;
      }
  
  //Condicional que evalua si se a contado un objeto como minimo
  //para qeu arranque.
  if(objetos >=1)
  {
    //Condiiconal para evaluar si el intervalo ya paso 
    if((millis() - tiempoInicial)>5000)
   {
      //acaba el intervalo
      if(objetos==2)
     {
  	  dosObjetos();
     }
     if(objetos==3)
     {
  	    tresObjetos();
     }
      //Serial.print(millis());
      Serial.println("=========================");
      Serial.println(" pasaron 5 segundos");
      Serial.println("=========================");
      iteracion += 1;
      Serial.println("Iteracion numero: "+String(iteracion));
  	  Serial.println("Objetos contados: "+String(objetos));
      Serial.print("Tiempo de ejecucion: ");
      Serial.println(millis());
      objetos = 0;
   }
   
  }
   
 
}



// metodo de detecciomn de el sensor de sonido
long leecturaDistanciaUltrasonica(int trigPin , int echoPin)
{
 pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pinMode(echoPin,INPUT);
  return pulseIn(echoPin,HIGH);
}
// metodo de curva
void tresObjetos()
{
	analogWrite(motor1a,0); 
    analogWrite(motor1b,100);
    direccion.write(45);
  	delay(450);
  	direccion.write(90);
  	delay(450);
  	analogWrite(motor1a,0);
  	analogWrite(motor1b,225);
    delay(500);
}

// metodo de zizas
void dosObjetos()
{
  analogWrite(motor1a,0); 
  analogWrite(motor1b,100);
  direccion.write(45);
  delay(400);
  direccion.write(145);
  delay(400);
  direccion.write(45);
  delay(400);
  direccion.write(145);
  delay(400);
  direccion.write(45);
  delay(400);
  direccion.write(145);
  delay(400);
  
  
}
// metodo para apagar motor
void apagarMotor()
{
analogWrite(motor1a,0); 
  analogWrite(motor1b,0);
}
// metodo para adelante rapido
void adelanteRapido()
{
  direccion.write(90);
  analogWrite(motor1a,0); 
  analogWrite(motor1b,225);
  
}

// metodo para adelante lento
void adelanteDespacio()
{
	direccion.write(90);
  analogWrite(motor1a,0); 
  analogWrite(motor1b,100);
  
}

// metodo para ir atras lento
void atrasDespacio()
{
	direccion.write(90);
  analogWrite(motor1a,100); 
  analogWrite(motor1b,0);
  delay(5000);
  
}

// metodo para ir atras rapido
void atrasRapido()
{
	direccion.write(90);
  analogWrite(motor1a,225); 
  analogWrite(motor1b,0);
  
}
void DetenerMotor(){
  analogWrite(motor1a,0); 
  analogWrite(motor1b,0);
}
  
