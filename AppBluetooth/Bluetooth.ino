/*
  VEHÍCULO CONTROLADO POR BLUETOOTH Y APP
  Programa para control de printbot kiwibot por APP y HC06.
  al recibir s para; f adelante; b atras; r derecha; l izquierda;
  H enciende LEDs, L apaga LEDs; Z zumbador; z apaga el zumbador
  Desarrollado por Miguel Granero, Jose Pujol y Alberto Pumar.
  Revisado Mayo 2016
  APP: https://play.google.com/store/apps/details?id=appinventor.ai_albyuda.HC06
*/

// variables constantes para los pines
// Pines de los servos
const int mLeft = 7; // servo izquierda
const int mRight = 4;  // servo derecha
// pines LED RGB
const int ledPinR = 6;
const int ledPinG = 5;
const int ledPinB = 9;
// pin timbre
const int buzzerPin = 10;

// variable para almacenar lectura puerto serial
int incomingByte;
// variable para almacenar el modo de movimiento
int mode = 's'; // lo inicializamos en parado

void setup() {
  // abrimos el puerto serie para la comunicacion
  Serial.begin(9600);
  // declaramos como salida servo, RGB, zumbador
  pinMode(mLeft, OUTPUT);
  pinMode(mRight, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
  // si hay datos en el puerto serie
  if (Serial.available() > 0) {
    incomingByte = Serial.read(); // Fijamos la variable incomingByte a lo que lea en el serial

    //guardamos en variable mode la direccion de funcionamiento del vehiculo
    // segun recibamos s, f, b, r, l
    if (incomingByte == 's') {
      mode = 's';
    }
    if (incomingByte == 'f') {
      mode = 'f';
    }
    if (incomingByte == 'b') {
      mode = 'b';
    }
    if (incomingByte == 'r') {
      mode = 'r';
    }
    if (incomingByte == 'l') {
      mode = 'l';
    }

    //si recibimos H encendemos los LEDs
    if (incomingByte == 'H') {
      digitalWrite(ledPinR, HIGH);
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinB, HIGH);
    }
    //si recibimos L apagamos los LEDs
    if (incomingByte == 'L') {
      digitalWrite(ledPinR, LOW);
      digitalWrite(ledPinG, LOW);
      digitalWrite(ledPinB, LOW);
    }
    //si recibimos Z activamos timbre
    if (incomingByte == 'Z') {
      digitalWrite(buzzerPin, HIGH);
    }
    //si recibimos z apagamos timbre
    if (incomingByte == 'z') {
      digitalWrite(buzzerPin, LOW);
    }
    // pequeño delay para recibir datos
    delay(15);
  }
  // activamos el modo de funcionamiento
  if (mode == 's') {
    stopA();
  }
  if (mode == 'f') {
    frontward();
  }
  if (mode == 'b') {
    backward();
  }
  if (mode == 'r') {
    right();
  }
  if (mode == 'l') {
    left();
  }

}

// funciones del motor

void frontward () {

  digitalWrite(mLeft, HIGH);
  digitalWrite(mRight, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mLeft, LOW);
  delayMicroseconds(1000);
  digitalWrite(mRight, LOW);
  delayMicroseconds(18000);
}
void backward() {
  digitalWrite(mRight, HIGH);
  digitalWrite(mLeft, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mRight, LOW);
  delayMicroseconds(1000);
  digitalWrite(mLeft, LOW);
  delayMicroseconds(18000);
}

void left() {
  digitalWrite(mLeft, HIGH);
  digitalWrite(mRight, HIGH);
  delayMicroseconds(2000);
  digitalWrite(mLeft, LOW);
  digitalWrite(mRight, LOW);
  delayMicroseconds(18000);
}
void right() {
  digitalWrite(mLeft, HIGH);
  digitalWrite(mRight, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mLeft, LOW);
  digitalWrite(mRight, LOW);
  delayMicroseconds(19000);
}
void stopA() {
  digitalWrite(mLeft, LOW);
  digitalWrite(mRight, LOW);
}
