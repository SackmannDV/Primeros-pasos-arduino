#include <LiquidCrystal.h>
const int tx = 8; //usamos pines pwm
const int rx = 9;
long distancia;
long tiempo;
const int rs =, en =, d4 =, d5 =, d6 =, d7 =; //Definir pines
LiquidCrystal lcd(rs, en, d4, d5, d6 , d7);

//Definimos que la variable tx (por transmission)
//este en un estado de 1 y en modo de salida; por
//otra parte la variable rx (por receiver) esta en
//modo de escucha
void setup() {
  lcd.begin( , ); //Configura el tamano del LCD
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  digitalWrite(tx, LOW);
  pinMode(rx, INPUT);
}

void loop() {
  ///digitalWrite(tx, LOW);
  digitalWrite(tx, HIGH);
  delayMicroseconds(10);
  digitalWrite(tx, LOW);
  //------------------------//
  //tiempo = (pulseIn(rx)/2);
  tiempo = (pulseIn(rx, HIGH) / 2);
  distancia = long (tiempo * 0.0343);
  //Serial.println(distancia);
  delay(500);
  Serial.print("Distancia en es: ");
  Serial.print(distancia);
  Serial.println(" centimetros");
}
