# Projeto medir unidade do solo


Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT). Introduçaõ à ultilização do sensor de umidade do solo conectado ao Arduíno, junto com
um Script de um algoritmo que passa as seguintes instruções: 

-Se a umidade for menor que 300 então é um solo seco;
-Se a umidade for maior que 300 e menor que 500 então é um solo ideal;
-Se a umidade for maior que 500 então é um solo úmido;

## Componentes Usados

- 1 Arduíno Uno;
- 1 Sensor de umidade do solo;
- 3 jumpers Macho/Macho;

## Montagem do Circuito 

![Imagem do circuito](/SensorSolo/SensorSolo.png)

## Explicação do Código

--Biblioteca para conexão serial do sensor

#include <SoftwareSerial.h>

-- Variável do sensor 

int sensor = A0;

void setup()

{

  --Definir o snesor com entrada

  pinMode(sensor, INPUT);

  --Ultilizando o monitor serial

  Serial.begin(9600);

}

void loop()

{

  -- Guardar o valor lido pelo sensor em uma variável

  int umidade = analogRead(sensor);

-- Se a umidade for menor que 300 ele executa o algoritmo abaixo

  if(umidade<300){

  Serial.println("Umidade baixa");

  Serial.println("Umidade do solo: ");

  Serial.println(umidade);
  
  delay(2000);

--Se umidade for maior que 300 e menor 500 então ele executa o algoritmo abaixo

  }if(umidade>300 && umidade <= 500){

  Serial.println("Umidade ideal");

  Serial.println("Umidade do solo: ");

  Serial.println(umidade);

  delay(5000);

--Se umidade for maior que 500 então ele executa o algoritmo abaixo

  }if(umidade>500){

  Serial.println("Umidade alta");

  Serial.println("Umidade do solo: ");

  Serial.println(umidade);

  delay(5000);

  Serial.println(" ");

  }

}
