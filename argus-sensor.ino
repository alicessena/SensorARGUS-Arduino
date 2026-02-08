#include <Servo.h>

Servo chaveEnergia;

const int trigPin = 9;
const int echoPin = 8;

const int ledVerde = 2;
const int ledAmarelo = 5;
const int ledVermelho = 3;

const int pinoServo = 10;

void setup() {
  chaveEnergia.attach(pinoServo);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  chaveEnergia.write(0);
  Serial.begin(9000);
}

void loop() {
  long duracao;
  float distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH); 
  distancia = (duracao * 0.0343) / 2;

  if (distancia >= 150) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    chaveEnergia.write(0);
  }
  else if (distancia >= 50) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

    chaveEnergia.write(0);
  }
  else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    chaveEnergia.write(90); 
    Serial.println(distancia);
  }
	
  delay(250);
}
