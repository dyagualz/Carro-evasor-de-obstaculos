// Sensores ultrasónicos
const int trigCentral = 3; 
const int echoCentral = 2;
const int trigIzquierdo = 12; 
const int echoIzquierdo = 13;
const int trigDerecho = 4;
const int echoDerecho = 5;
// Controlador de motores
const int ENA = 11;
const int IZQ1 = 9;
const int IZQ2 = 8;
const int DER2 = 7;
const int DER1 = 6;
const int ENB = 10;
// Distancia mínima a un obstáculo
const int distanciaMinima = 15;
void setup() {
pinMode(trigCentral, OUTPUT);
pinMode(echoCentral, INPUT);
pinMode(trigIzquierdo, OUTPUT);
pinMode(echoIzquierdo, INPUT);
pinMode(trigDerecho, OUTPUT);
pinMode(echoDerecho, INPUT);
pinMode(ENA, OUTPUT);
pinMode(IZQ1, OUTPUT);
pinMode(IZQ2, OUTPUT);
pinMode(DER2, OUTPUT);
pinMode(DER1, OUTPUT);
pinMode(ENB, OUTPUT);
}
void loop() {
int distanciaCentral = medirDistancia(trigCentral, echoCentral);
int distanciaIzquierda = medirDistancia(trigIzquierdo, echoIzquierdo);
int distanciaDerecha = medirDistancia(trigDerecho, echoDerecho);
if (distanciaCentral < distanciaMinima) {
retroceder();
delay(200); // Ajusta el tiempo de retroceso según sea necesario
if (random(2) == 0) {
girarDerecha();
} else {
girarIzquierda();
}
} else if (distanciaIzquierda < distanciaMinima && distanciaDerecha < distanciaMinima) {
retroceder();
delay(200);
if (random(2) == 0) {
girarDerecha();
} else {
girarIzquierda();
}
} else if (distanciaIzquierda < distanciaMinima) {
girarDerecha();
} else if (distanciaDerecha < distanciaMinima) {
girarIzquierda();
} else {
avanzar();
}
}
int medirDistancia(int trigPin, int echoPin) {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long duracion = pulseIn(echoPin, HIGH);
int distancia = duracion / 29 / 2;
return distancia;
}
void avanzar() {
digitalWrite(IZQ1, HIGH);
digitalWrite(IZQ2, LOW);
digitalWrite(DER2, LOW);
digitalWrite(DER1, HIGH);
analogWrite(ENA, 90);
analogWrite(ENB, 90);
}
void girarDerecha() {
digitalWrite(IZQ1, HIGH);
digitalWrite(IZQ2, LOW);
digitalWrite(DER2, HIGH);
digitalWrite(DER1, LOW);
analogWrite(ENA, 200);
analogWrite(ENB, 255);
delay(200); // Ajusta el tiempo de giro según sea necesario
}
void girarIzquierda() {
digitalWrite(IZQ1, LOW);
digitalWrite(IZQ2, HIGH);
digitalWrite(DER2, LOW);
digitalWrite(DER1, HIGH);
analogWrite(ENA, 255);
analogWrite(ENB, 200);
delay(200); // Ajusta el tiempo de giro según sea necesario
}
void retroceder() {
digitalWrite(IZQ1, LOW);
digitalWrite(IZQ2, HIGH);
digitalWrite(DER2, HIGH);
digitalWrite(DER1, LOW);
analogWrite(ENA, 90);
analogWrite(ENB, 90);
}