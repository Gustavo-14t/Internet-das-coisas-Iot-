# Atividade com Buzzer

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), nesta atividade foi nos apresentado o Piezo, que é um dispositivo que transforma
a energia em frequencia sonora, onde foi possível tocar músicas com Arduíno, porém só
tocamos as notas dó, ré, mi e fá. 

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 Piezo;
- 3 jumpers Macho/Macho;


## Montagem do Circuito
![Imagem do Circuito](/AtividadeBuzzer/Buzzer.png)

## Explicação do Código

int buzzer = 3;  

#define doo 261.2

#define re 294

#define mi 330

#define fa 349

void setup()

{

}

void loop()

{

  //FUNÇÃO DE LIGAR tone()

  tone(buzzer,doo,500);

  delay(600); //Espera 6 segundos

  tone(buzzer,re,500);

  delay(600); //Espera 6 segundos

  tone(buzzer,mi,500);

  delay(600); //Espera 6 segundos

  tone(buzzer,fa,500);

  delay(600); //Espera 6 segundos
  
  //FUNÇÃO DE DESLIGAR noTone()

  noTone(buzzer); 

}
