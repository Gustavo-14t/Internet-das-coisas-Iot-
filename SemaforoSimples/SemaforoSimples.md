# Projeto Semáforo Comum

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), o projeto simula um semáforo, onde um led verde liga e 2 segundos depois ele desliga e liga 
o led amaraelo que 2 segundos depois ele desliga e liga o led vermelho e 2 segundos depois ele desliga
entra no loop.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 led verde;
- 1 led amarelo;
- 1 vermelho;
- 3 Resistores com resistência de 220Ω;
- 8 jumpers Macho/macho;


## Montagem do Circuito
![Imagem do Circuito](/SemaforoSimples/SemaforoSpl.png)

## Explicação do Código

// C++ code
//
--Delcaração de Variáveis

int ledVerde = 7;

int ledVermelho = 2;

int ledAmarelo = 4;

void setup()

{
  --Definindo o tipo de cada pino, se é saída ou entrada
No caso (OUTPUT) é saída, aonde a luz e acessa no led.


  pinMode(ledVerde,OUTPUT);

  pinMode(ledVermelho,OUTPUT);
  
  pinMode(ledAmarelo,OUTPUT);

}

void loop()

{
-- digitalWrite abre a prota digital do arduino permitindo a passagem de corrente elétrica 
fazendo com que a luz do led seja ligada.
  
  digitalWrite(ledVerde, HIGH);

  delay(2000); Espera for 2000 millisecond(s)


  digitalWrite(ledVerde, LOW);

  digitalWrite(ledAmarelo, HIGH);

  delay(2000);  Espera 2000 millisecond(s)

  digitalWrite(ledAmarelo, LOW);

  digitalWrite(ledVermelho, HIGH);

  delay(2000); Espera 2000 millisecond(s)


  digitalWrite(ledVermelho, LOW);

}
