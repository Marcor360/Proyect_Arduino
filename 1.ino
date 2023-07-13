int trig = 2; // pin 2 a Trigger del sensor
int echo = 3; // pin 3 a echo del sensor
int led = 9; // pin 9 led +
//Motor
const int stepPin = 5; //Pin 
const int dirPin = 4; //Pin 
const int enPin = 8;//Pin 
void setup() {
Serial.begin (9600); //Se inicia el puerto Serial
// Configuración de pines de salida
pinMode (trig, OUTPUT);
pinMode (echo, INPUT);
pinMode (led, OUTPUT);
//Partes del motor 
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
}
void loop() {
//Declaramos dos variables auxiliares para el cálculo de la distancia respecto al tiempo
long tiempo;
long distancia;
digitalWrite(trig, LOW); //El pin Trigger apagado empieza en el ciclo apagado
delayMicroseconds(10); //Pasan 10 microsegundos después...
digitalWrite(trig, HIGH); //El pin Trigger se enciende
delayMicroseconds(10); //Pasan 10 microsegundos después...
digitalWrite(trig, LOW); //El pin Trigger se apagará
tiempo = pulseIn(echo, HIGH); //La variable tiempo guardará el valor que tarda en llegar
//al receptor de eco, ancho del pulso
distancia = tiempo/58; //Hacemos la relación de la distancia en cm
//Programación del led
if (distancia <= 5) { //Si la distancia es menor o igual a 5 cm el led se encenderá y todo el sistema prendera
digitalWrite(led,  HIGH);
delay (6000);//Tiempo que dura prendido el led y se apagara el motor
digitalWrite(led,  LOW);
delay (5000); // Tiempo que durara apagado el led y se volvera a prender el motor
} 
else {
digitalWrite(led, LOW);
}
//Mostrará la distancia en el monitor serial (9600)
Serial.print (distancia);
Serial.println ("cm");
delay (50); //se actualizará la información cada 50 ms
}
//Fin de codigo (～￣▽￣)～

//Codigo del motor //*Nota todavia no esta dentro del if por motivos de pruevas*
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(5000); //Sinco segundos
}