# Acender Led RGB

Este projeto foi o 2º projeto desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), onde foi criado um sistema que liga e pode variar as cores de um Led RGB.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 2 Led RGB;
- 6 Resistores com resistência de 150Ω;
- 8 jumpers Macho/Macho;
  

## Montagem do Circuito
![Imagem do Circuito](/LedRGB/LedRGB.png)

## Explicação do Código
--Delcarando as variáveis


int R = 6;  //porta vermelha

int G = 3;  //porta verde

int B = 5;  //porta azul


int R2 = 9;  

int G2 = 10;  

int B2 = 11; 


void setup()

{
--Definindo o que as variavéis vão fazer
(OUPUT = saída, quer dizer que essas variáveis vão retornar a saída de algo
no caso do led, ele acende)

  pinMode(R, OUTPUT);
  
  pinMode(G, OUTPUT);
  
  pinMode(B, OUTPUT);


  
  pinMode(R2, OUTPUT);
  
  pinMode(G2, OUTPUT);
  
  pinMode(B2, OUTPUT);

  
}

void loop()

{
--Declarando variáveis que podem receber qualquer valor entre 0 e 255, 
elas irão manipular os leds fazendo eles mudarem de cor toda vez que repetirem o loop


  int v1 = random(0,255);
  
  int v2 = random(0,255);
  
  int v3 = random(0,255);

  --AnalogWrite define a abertura da porta analógica que manda energia para o LedRBG fazendo ele piscar

  analogWrite(R, v1);
  
  analogWrite(G, v2);
  
  analogWrite(B, v3);

  delay(0); -- Esperar 0 millisecond(s)

  
  analogWrite(R2, v1+v2);
  
  analogWrite(G2, v2+v3);
  
  analogWrite(B2, v3+v1);
  
  delay(0); -- Esperar 0 millisecond(s)
  
}
