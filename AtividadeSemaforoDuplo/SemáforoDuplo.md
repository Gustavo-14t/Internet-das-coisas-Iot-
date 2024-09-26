# Projeto Semáforo com sensor de distância

Este projeto foi desenvolvido dentro do Thinkercad, na disciplina de Internet das Coisas 
(IOT), para a criação de protótipo com arduíno que simula dois semáforos de carros e 2
de pedestres onde quando o pedestre se aprixomar a uma distância de 50 cm do sensor, o sinal 
verde mudará para, amarelo e depois para o vermelho, e abrir o sinal verde pedestre, e se o sensor 
não detectar ninguém dentro do campo de 50 cm então ele o semáforo do pedestre ficará vermelho e
o dos carros ficará verde.

## Componentes Usados

- 1 Arduíno Uno;
- 1 Placa de ensaio (Protoboard);
- 2 Sensores de distância ultrassônico;
- 10 Resistores com resistência de 1kΩ;
- 4 Leds na cor verde;
- 4 Leds na cor vermelha;
- 2 Leds na cor amarela;
- 24 jumpers Macho/Macho;
- 6 jumpers Macho/Fêmea;

## Montagem do Circuito 

![Imagem do circuito](/AtividadeSemaforoDuplo/AtividadeSemaforoDuplo.png.png)

## Explicação do Código

// C++ code
//

--Declarando Variáveis

int ledVerde1 = 0;

int ledAmarelo1 = 1;

int ledVermelho1 = 2;

int verdePedestre1 = 6;

int vermelhoPedestre1 = 7;

int verdePedestre2 = 8;

int vermelhoPedestre2 = 9;


void setup()

{ --Definindo o que cada variável vai fazer

  pinMode(ledVerde1, OUTPUT);

  pinMode(ledAmarelo1, OUTPUT);

  pinMode(ledVermelho1, OUTPUT);
  
  pinMode(verdePedestre1, OUTPUT);

  pinMode(vermelhoPedestre1, OUTPUT);

  
  pinMode(verdePedestre2, OUTPUT);

  pinMode(vermelhoPedestre2, OUTPUT);

  
}

long distancia1(int trigger, int echo){ 

 // trigger porta de saída
 
  pinMode(trigger,OUTPUT);

  digitalWrite(trigger,LOW);

  delay(5);//espera 5 milisegundos

  //mandando o sinal

  digitalWrite(trigger,HIGH);

  delay(10);//espere 10 milisegundos

  digitalWrite(trigger,LOW);

  
 // echo porta de entrada

  pinMode(echo,INPUT);
  
  return pulseIn(echo,HIGH);

  
}

long distancia2(int trigger, int echo){
 
 // trigger porta de saída
 
  pinMode(trigger,OUTPUT);

  digitalWrite(trigger,LOW);

  delay(5);//espera 5 milisegundos

  //mandando o sinal

  digitalWrite(trigger,HIGH);

  delay(10);//espere 10 milisegundos

  digitalWrite(trigger,LOW);

  
 // echo porta de entrada

  pinMode(echo,INPUT);

  
  return pulseIn(echo,HIGH);

    
}



void loop()

{

  int cm1 = 0.01723 * distancia1 (10, 10);

  int cm2 = 0.01723 * distancia2 (11, 11);

  
  digitalWrite(ledVerde1, HIGH);

  
  if((cm1<50 || cm2<50)){

  -- Esse if vai perguntar se a frequência que o ultrasensor está reecebendo

  -- é menor que 50, se sim, ele vai executar toda a linha de código abaixo

  -- ligando o semáforo amarelo, esperando 2 segundos e lignado o vermelho do semáforo

  -- vermelho dos carros e liganfo o semáforo verde dos pedestres
  
  digitalWrite(vermelhoPedestre1, LOW);

  digitalWrite(vermelhoPedestre2, LOW);

  digitalWrite(ledVerde1, LOW);

    
  delay(0);

  digitalWrite(ledAmarelo1,HIGH); 

  delay(2000);

  digitalWrite(ledAmarelo1,LOW);   

  digitalWrite(ledVermelho1,HIGH);
     
  digitalWrite(verdePedestre1,HIGH);

  digitalWrite(verdePedestre2,HIGH);

  delay(5000);
   
  digitalWrite(ledVermelho1,LOW);  

  }else {

-- Se não, ele executa todos os comandos abaixo, ligando o semáforo verde dos carros

-- Desligando a cor verde e ligando a cor vermelho do semáforo dos pedestres.

    
  digitalWrite(ledVerde1, HIGH);

    
  digitalWrite(verdePedestre1,LOW);

  digitalWrite(vermelhoPedestre1, HIGH);
  
    
  digitalWrite(verdePedestre2,LOW);

  digitalWrite(vermelhoPedestre2, HIGH);

  delay(5000);

    

  }
  
}
