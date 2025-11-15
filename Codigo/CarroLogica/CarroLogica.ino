/*La logica del codigo es poder hacer qu el carro recorra una distancia recta, contando los obejtos y acelerando
o disminuyendo su velocidad*/


//Libreria
#include <ESP32Servo.h>

//Declaracion de constantes y variables
#define TRIG_PIN 5 //Morado
#define ECHO_PIN 17 //Verde
#define SERVO_PIN 2 //Naranja
Servo servo;
int angulo = 0;
int objetos = 0; 
void setup() {
  //Configuracion del serial para que este en la misma frecuencia, y sea mas rapido 
  Serial.begin(115200);
  servo.attach(SERVO_PIN, 500, 2400); // pin, pulso mínimo, pulso máximo

  //Configuracion de los pines del Eco
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

//Impresion para verificar que todo esta bien 
  Serial.println("Sistema listo");
}

void loop() {
  // ----- medir distancia -----
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

//-------Convertitr la distancia en una magnitud-------
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distancia = duration * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

//------Logica condisional para evaluar que debe hacer-----
if(distancia <= 8)
{
  objetos = objetos +1;
  angulo = 90;

}
else if (distancia >8 && distancia <= 15)
{
  angulo = 180;
}else{
  angulo = 0;
}
  
//Intruccion para que el servo se mueva(el valor)
  servo.write(angulo);
//Delay para que el programa tenga tiempo de ejecutar antes de volver a evaluar
  delay(1000);
  delay(1000);
  Serial.println("Objetos contados: " + String(objetos));

  }
