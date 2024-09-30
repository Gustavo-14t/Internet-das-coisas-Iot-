# Projeto Leds Piscantes

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), o projeto teve o seguinte requerimento:

CRIE UM CIRCUITO COM 2 LEDS VERDES , 2 LEDS VERMELHOS E 2 LES AZUIS. (NESSA OREDEM)

- NO PRIMIRO MOMENTO DEVE SER ACESO 1 LED VERDE, 1 VEREMLHO, 1 AZUL.
- NO SEGUNDO MOMENTO DEVE SER ACESO 2 AZUIS E 2 VERDES
- NO TERCEIRO MOMENTO DEV SER ACESO 1 VERDE , 2 VERMELHOS E 1 AZUL.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 2 led verde;
- 2 led vermelho;
- 2 led azul;
- 6 Resistores com resistência de 220Ω;
- 16 jumpers Macho/Macho;

## Montagem do Circuito
![Imagem do Circuito](/LedPiscantes/LedsPiscantes.png)

## Explicação do Código

// C++ code
--Declaração de variáveis

int ledVerde1 = 0;

int ledVerde2 = 1;

int ledVermelho1 = 2;

int ledVermelho2 = 3;

int ledAzul1 = 4;

int ledAzul2 = 5;

void setup()

{

-- Definindo se a variável vai receber um valor ou se ela vai retornar um valor 

 pinMode(ledVerde1, OUTPUT);

 pinMode(ledVerde2, OUTPUT);

 pinMode(ledVermelho1, OUTPUT);

 pinMode(ledVermelho2, OUTPUT);

 pinMode(ledAzul1, OUTPUT);

 pinMode(ledAzul2, OUTPUT);

}

void loop()

{

-- Dentro do loop, após todos esse comandos abaixo serem executados, eles vão se repetir até que outro código

seja gravado por cima dele


--digitalWrite se estiver HIGH ele abre o pino digital e permite que a corrente elétrica passe 

e acenda o led, LOW fecha a porta digital impedindo a alimentação do led fazendo com que ele desligue.


  digitalWrite(ledVerde1, HIGH);

  digitalWrite(ledVermelho1, HIGH);

  digitalWrite(ledAzul1, HIGH);

  delay(3000); -- Espera 1000 millisecond(s)

  digitalWrite(ledVermelho1,LOW);

  digitalWrite(ledVerde2, HIGH);

  digitalWrite(ledAzul2, HIGH);

  delay(3000);

  digitalWrite(ledVerde2,LOW);

  digitalWrite(ledAzul2,LOW);

  digitalWrite(ledVermelho1,HIGH);

  digitalWrite(ledVermelho2,HIGH);

  delay(3000);

  digitalWrite(ledVermelho2,LOW);

}
