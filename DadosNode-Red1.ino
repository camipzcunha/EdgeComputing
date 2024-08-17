/////Json
#include <ArduinoJson.h>
const int TAMANHO = 50;  //define o tamanho do buffer para o json
 
///// Sensor DHT
#include "DHT.h"
#define DHTPIN  7  //define o pino usado no arduino
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); //declara a objeto da classe
 
////// Outras declarações
#define led 13 //define led conectado no pino 13
int sensorPin = A1;
 
 
 
void setup()
{
  //inicialia c sensor
  dht.begin();
 
  //inicializa comunicação serial
  Serial.begin(9600);
 
  //configura pinos de saida do arduinos
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
}
 
void loop()
{
  StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json
 
  // Faz a leitura da temperatura  
  float temp = dht.readTemperature();
  // faz a leitura da humidade
  float umi = dht.readHumidity();
  float lumi = 0;
  float val = 0;
  val = analogRead(sensorPin);
 
  lumi = map(val, 54 , 974, 0, 100);
 
 
  //formato de escrita do json
  json["temperatura"] = temp;
  json["umidade"] = umi;
  json["luminosidade"] = lumi;
 
  serializeJson(json, Serial);
  Serial.println();
 
  //delay
  delay(5000);
  digitalWrite(led, !digitalRead(led));
}
/* * Entrada analógica * le o valor do ... por Isabelle Dallabeneta Carlesso
Isabelle Dallabeneta Carlesso
20:52
/*
* Entrada analógica
* le o valor do sensor de luminosidade e envia valor para o computador
*/
int sensorPin = A0;    // selecione o pino de entrada ao potenciômetro
int val;
void setup() {
Serial.begin(9600);
}
void loop() {
val = analogRead(sensorPin);    // ler o valor do potenciômetro
int luz = map(val, 54 , 974, 0, 100);
  Serial.println(luz);            //emvia valor para o pc
  Serial.println(val);            //emvia valor para o pc
delay(1000);                    //aguarda 1 segundo
}
tem menu de contexto
