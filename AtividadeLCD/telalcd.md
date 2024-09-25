# Projeto de Tela LCD com sensor de distância

Este projeto foi desenvolvido dentro do Thinkercad, na disciplina de Internet das Coisas 
(IOT), para a criação de protótipo com arduíno que simule uma mensagem de "Mantenha diastância"
e outra "ALERTA" todsa vez que alguém se aproximar a menos de 1 metro do sensor.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 LCD 16x2;
- 1 Resistor com resistência de 1kΩ;  
- 1 Sensor de distância Ultrassônico;
- 14 jumpers Macho/Macho;
- 3 jumpers Macho/Fêmea;

## Montagem do Circuito
![Imagem do Circuito](/AtividadeLCD/TELA-LCD.png)

## Explicação do Código


Importando a biblioteca do LCD.

#include LiquidCrystal


criar variável do lcd

LiquidCrystal lcd = {2,3,4,9,10,11,12};

Método para capturar a distância

retorna número quebrado longo

long distancia(int trigger, int echo){
 
trigger porta de saída

pinMode(trigger,OUTPUT);

digitalWrite(trigger,LOW);

delay(5);  espera 5 milisegundos

  
mandando o sinal

digitalWrite(trigger,HIGH);

delay(10);  espere 10 milisegundos

digitalWrite(trigger,LOW);

echo porta de entrada

pinMode(echo,INPUT);

Captura a duração de um pulso em um pino (que pode ser HIGH ou LOW ).

return pulseIn(echo,HIGH);

}


Declaração de variáveis

int ledLcd = 13;

char z [20] = "Manter Distancia";

char x [12] = "ALERTA";


void setup()  Define inicialização e a configurtação dos pinos da placa arduíno

{
  
 pinMode (ledLcd, OUTPUT);

  pinMode (ledLcd,OUTPUT);  DEFINIR LEDLCD SAIDA

  digitalWrite(ledLcd,HIGH); Ligar os LEDs do LCD

  lcd.begin(16,2);  informar que po lcd tem 16 colunas e 2 linhas

  lcd.clear();  informar o lcd limpo

}


void loop()  Função de ciclo do arduíno

{

  Transformar o valor recebido em centímetros

  int cm = 0.01723 * distancia (8, 8);

  if (cm<100){  se menor que 1 metro/100cm

  lcd.setCursor(0,0);   iniciar a escrita na linha 0 coluna 0

  lcd.print(x);

  lcd.setCursor(0,1);

  lcd.print(z);

   delay(50);

   lcd.clear();

 ;

  }else{

lcd.clear();

  };
  
}

