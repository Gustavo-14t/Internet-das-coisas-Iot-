# Projeto Presença Alarmante

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT), o projeto pediu que: Ao sensor PIR detectar uma presença ele emitisse um som usando o 
Piezo e acendesse um led vermelho.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 Piezo;
- 1 Sensor PIR;
- 1 Resistor com resistência de 1kΩ;
- 9 jumpers Macho/Macho;


## Montagem do Circuito
![Imagem do Circuito](/PresençaAlarmante/PresençaAlarmante.png)

## Explicação do Código

--Declaração de variáveis

int sensorPIR = 5;

int buzzer = 3;

int led = 2;

void setup(){
- Definindo se elas são de entradas ou saída de dados


  pinMode(sensorPIR, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(led, OUTPUT);

}

void loop (){

-Delcarando uma variável que recebe o valor que o sensorPIR ler.
int detectarPresenca = digitalRead(sensorPIR);

-- Adicioando uma condição, detectarPresença detectar algum valor então, o piezo
 irá emitir um som e o led será ligado; senão, a piezo não emitirá som e o led não desligará.

  if (detectarPresenca == 1){

  tone(buzzer,10000);

  digitalWrite(led, HIGH);

  delay(10000);

  }else{

  digitalWrite(led, LOW);

  noTone(buzzer);
}
    
}
