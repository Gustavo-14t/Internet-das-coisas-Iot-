# Projeto Robô Segurança

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), onde foi nos dado a seguinte exigência: Seu dever aqui é, criar uma cabeça de robô que ao detectar
algum objeto/pessoa/parede a sua frente emita um sinal ao corpo dele e faça-o girar para o outro lado.
Ao encontrar um obstáculo ele deve acender um led vermelho, e só depois deve girar o corpo para o outro lado.

## Componentes Usados

- 1 Arduíno Uno;
- 1 Placa de ensaio (Protoboard);
- 1 Sensor de distância ultrassônico;
- 1 Micro Servo motor;
- 1 led na cor vermelha;
- 1 Resistor com resistência de 220Ω;
- 9 jumpers Macho/Macho;
- 3 jumpers Maho/Fêmea;

## Montagem do Circuito 

![Imagem do circuito](/RoboSeguranca/RoboSeguranca.png)

## Explicação do Código
//Biblioteca para a ultilização do servo motor

#include <Servo.h>

Servo microServo;

int led = 0;

int servo = 2;

int posicao = 0;

--Método que envia e recebe dados para o sensor ultrassônico

long distancia(int trigger, int echo){ 

 -- trigger porta de saída 

  pinMode(trigger,OUTPUT);

  digitalWrite(trigger,LOW);

  delay(5);//espera 5 milisegundos

  --mandando o sinal

  digitalWrite(trigger,HIGH);

  delay(10); --espere 10 milisegundos

  digitalWrite(trigger,LOW);

 -- echo porta de entrada

  pinMode(echo,INPUT);

  return pulseIn(echo,HIGH);  

}

void setup()

{

  -- inicializando o servo na porta digital  

  microServo.attach(servo);  

  pinMode(led, OUTPUT);  

  microServo.write(posicao); 

}

void loop()

{
  --Variável cm que vai receber os dados do sensor ultrassônico e multiplicar pelo valor decimal
convertendo para centímetros.

  int cm = 0.01723 * distancia (1, 1);
  
--Se a variável cm for menor que 30 então o servo motor muda de posição e aqcende o led

  if(cm<30){ 	

  --MANDE O MOTOR PARA A NOVA POSIÇÃO

  posicao = posicao +5;

  microServo.write(posicao);

  digitalWrite(led, HIGH);

  delay(100);   

  }else{--Se não ele desliga leg e o servo motor não irá se mover

  digitalWrite(led, LOW);

  }

}
