
/*
  VEHÍCULO CONTROLADO POR BLUETOOTH Y APP
  Programa para control de laserbot kiwibot por APP y HC06.
  al recibir s para; f adelante; b atras; r derecha; l izquierda;
  Desarrollado por Miguel Granero, Jose Pujol y Alberto Pumar.
  Revisado Mayo 2016- Jose Pujol
  APP: https://play.google.com/store/apps/details?id=appinventor.ai_albyuda.HC06
*/

// variables constantes para los pines
// Pines de los servos
const int mLeft = 7; // servo izquierda
const int mRight = 4;  // servo derecha

// variable para almacenar lectura puerto serial
int incomingByte;

void setup() {
  // abrimos el puerto serie para la comunicacion
  Serial.begin(9600);
  // declaramos como salida servos
  pinMode(mLeft, OUTPUT);
  pinMode(mRight, OUTPUT);

}

void loop() {
  // si hay datos en el puerto serie
  if (Serial.available() > 0) {
    incomingByte = Serial.read(); // Fijamos la variable incomingByte a lo que lea en el serial

    // pequeño delay para recibir datos
    delay(15);
  }
  // segun recibamos s, f, b, r, l
  // activamos la funcion del motor
  if (incomingByte == 's') {
    stopA();
  }
  if (incomingByte == 'f') {
    frontward();
  }
  if (incomingByte == 'b') {
    backward();
  }
  if (incomingByte == 'r') {
    right();
  }
  if (incomingByte == 'l') {
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
