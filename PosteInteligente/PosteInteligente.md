# Projeto Poste Inteligente 

Este projeto foi desenvolvido dentro do Thinkercad, na disciplina de Internet das Coisas 
(IOT), para a criação de protótipo com arduíno que simula um poste que ao receber certa quantidade de luminosidade
pode acender ou desligar, dependedo do grau de luminosidade que ele detectar.

## Componentes Usados

- 1 Arduíno Uno;
- 1 Placa de ensaio (Protoboard);
- 1 Fotorresistor;
- 1 Resistor com resistência de 150Ω;
- 1 Resistor com resistência de 10 kΩ;
- 7 Jumpers Macho/Macho;

## Montagem do Circuito 

![Imagem do circuito](/PosteInteligente/PosteInteligente.png)

## Explicação do Código

// C++ code
//
int led = 3;

int sensorLuminosidade = A0;

int luz = 0;

//Variável para capturar a luminosidade.


void setup(){

 //Led é de saída

 pinMode(led,OUTPUT);
  
 //sensorLuminosidade é de entrada 

 pinMode(sensorLuminosidade, INPUT);

}

void loop(){

  //Capturar o que o sensor leu no ambiente 

  //analogRead é usado para leitura analógica
  
  luz = analogRead(sensorLuminosidade);

  /* as portas analógicas capturam dados que variam  de

   0 até 1023 */

  if(luz<500){

  analogWrite(led, 1023);//LIGAR LED
 
  if(luz>500 & luz < 900){  

  // passar ao led instensidade média 

  analogWrite(luz, 500);   

  }  

  }else{
   
  analogWrite(led, 0); // DESLIGAR LED

}
 
}
