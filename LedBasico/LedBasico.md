# Acendendo o Led

Este projeto foi o 1º cirucito desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), onde um led vermelho deveria ser acesso.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 Resistor com resistência de 220Ω;
- 4 jumpers Macho/Macho;

 ## Montagem do Circuito
![Imagem do Circuito](/LedBasico/LedBasico.png)

## Explicação do Código


// C++ code

//comentários curtos

/*comentários longos*/

int led = 4;  

void setup() //função para configuração inicial roda 1 vez 

//no início

{

  // definir configurações do led INPUT (entrada)

  //OUTPUT (saída)

 pinMode(led,OUTPUT);//Definir o led como saída

  /*

  função de definição de entrada/saída de equipamento

  receber 2 parâmtros:

  (porta que o disposistivo esta conectado)

  */

}

//função de execução de instruções infinitas/loop

void loop()

{

 //ligar meu led, para liga usa-se HIGH = instrução para

 //liberar a passage gem energia.

  digitalWrite(led,HIGH);

  //adicionar pausa

  delay(3000); // espera 3 segundos e após isso 

  //executar cmd abaixo

  //Desligar o led usa-se (LOW)

  digitalWrite(led,LOW);

   delay(3000); // espera 3 segundos

}

