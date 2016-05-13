/*
VEHÍCULO CONTROLADO POR BLUETOOTH Y APP
 Programa para control de printbot kiwibot por APP y HC06.
 Desarrollado por Miguel Granero, Jose Pujol y Alberto Pumar.
 Revisado Noviembre 2015
 */
// LEDS
const int ledPinR = 6;
const int ledPinG = 5;
const int ledPinB = 9;
//Timbre
const int buzzerPin = 10;
// Pines de los servos
const int MLeft = 7;
const int MRight = 4;
// variable para almacenar lectura puerto serial
int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(MLeft, OUTPUT);
  pinMode(MRight, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read(); // Fijamos la variable incomingByte a lo que lea en el serial
  }
  //Asociamos la memoria a estos codigos que indican la direccion del motor
 
  //Aqui hacemos con los motores lo que hayamos recibido por el serial, como hemos fijado arriba
  if (incomingByte == 's') {
    stopA();
  }
  if (incomingByte == 'f') {
    frontwards();
  }
  if (incomingByte == 'l') {
    left();
  }
  if (incomingByte == 'b') {
    backward();
  }
  if (incomingByte == 'r') {
    right();
  }
  //Aqui encendemos totalmente los LEDs
  if (incomingByte == 'H') {
    analogWrite(ledPinR, 255);
    analogWrite(ledPinG, 255);
    analogWrite(ledPinB, 255);
  }
  //Aqui apagamos los LEDs
  if (incomingByte == 'L') {
    analogWrite(ledPinR, 0);
    analogWrite(ledPinG, 0);
    analogWrite(ledPinB, 0);
  }
  //En los proximos 2 bloques encendemos o apagamos el timbre
  if (incomingByte == 'Z') {
    digitalWrite(buzzerPin, HIGH);//Estos para el timbre
  }
  if (incomingByte == 'z') {
    digitalWrite(buzzerPin, LOW);
  }
  delay(15);
}
void frontwards() {
  digitalWrite(MRight, HIGH);
  digitalWrite(MLeft, HIGH);
  delayMicroseconds(1000);
  digitalWrite(MRight, LOW);
  delayMicroseconds(1000);
  digitalWrite(MLeft, LOW);
  delayMicroseconds(18000);
}
void backward () {
  digitalWrite(MLeft, HIGH);
  digitalWrite(MRight, HIGH);
  delayMicroseconds(1000);
  digitalWrite(MLeft, LOW);
  delayMicroseconds(1000);
  digitalWrite(MRight, LOW);
  delayMicroseconds(18000);
}
void left(){
  digitalWrite(MLeft, HIGH);
  digitalWrite(MRight, HIGH);
  delayMicroseconds(2000);
  digitalWrite(MLeft, LOW);
  digitalWrite(MRight, LOW);
  delayMicroseconds(18000);
}
void right(){
  digitalWrite(MLeft, HIGH);
  digitalWrite(MRight, HIGH);
  delayMicroseconds(1000);
  digitalWrite(MLeft, LOW);
  digitalWrite(MRight, LOW);
  delayMicroseconds(19000);
}
void stopA() {
  digitalWrite(MLeft, LOW);
  digitalWrite(MRight, LOW);
}
