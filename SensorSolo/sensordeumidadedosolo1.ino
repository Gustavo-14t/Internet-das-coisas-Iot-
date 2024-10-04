///Biblioteca para conexão serial do sensor
#include <SoftwareSerial.h>

// Variável do sensor 
int sensor = A0;

void setup()
{
  //Definir o snesor com entrada
  pinMode(sensor, INPUT);
  
  //Ultilizando o monitor serial
  Serial.begin(9600);
    

}

void loop()
{
  // Guardar o valor lido pelo sensor em uma variável
  int umidade = analogRead(sensor);
  
  if(umidade<300){
  Serial.println("Umidade baixa");
  Serial.println("Umidade do solo: ");
  Serial.println(umidade);
  delay(2000);
  }if(umidade>300 && umidade <= 500){
  Serial.println("Umidade ideal");
  Serial.println("Umidade do solo: ");
  Serial.println(umidade);
  delay(5000);
  }if(umidade>500){
  Serial.println("Umidade alta");
  Serial.println("Umidade do solo: ");
  Serial.println(umidade);
  delay(5000);
  Serial.println(" ");
  }
}