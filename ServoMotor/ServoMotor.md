# Ultilizando Servo Motor

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT). Introdução à ultilização de micro servo motor, onde foi criado um protótipo em que
a cada 2 segundos o servo motor gira 45°, este servo motor tinha limitação de 180°, 
ou seja, quando ele chegava em 180° ele parava.

## Componentes Usados

- 1 Arduíno Uno;
- 1 Placa de ensaio (Protoboard);
- 1 Micro Servo motor;
- 5 jumpers Macho/Macho;

## Montagem do Circuito 

![Imagem do circuito](/ServoMotor/ServoMotor.png)

## Explicação do Código
--Incluindo a biblioteca para a ultilização do servo motor

#include <Servo.h>

--Criando objeto do tipo Servo motor para poder usar as 
funções de controle do equipamento(servo motor)

Servo objetoServo;

--Variável para salvar a porta que servo motor está conectado

int servo = 0;

void setup()

{

  -- inicializando o servo na porta digital  

  objetoServo.attach(servo);

}

void loop()

{

  -- servo rotacionar a 45°

  objetoServo.write(45);

  delay(2000);

  -- servo rotacionar a 90°

  objetoServo.write(90);

  delay(2000);

  -- servo rotacionar a 135°

  objetoServo.write(135);

  delay(2000);

  -- servo rotacionar a 180°

  objetoServo.write(180);

  delay(2000);

  -- servo rotacionar a 45°

  objetoServo.write(135);

  delay(2000);

  -- servo rotacionar a 90°

  objetoServo.write(90);

  delay(2000);

  -- servo rotacionar a 135°

  objetoServo.write(45);

  delay(2000);

  --servo rotacionar a 0°

  objetoServo.write(0);

  delay(2000);

}
