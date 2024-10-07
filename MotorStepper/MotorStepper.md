# Projeto Motor De Passo

Este projeto foi desenvolvido dentro do Tinkercad, na disciplina de Internet das Coisas 
(IOT). Foi criado um protótipo onde por meio de linha de comando conseguimos manipular 
o motor de passo fazendo ele sai da posição 0 para a posição 360° ou 1024 byts.

## Componentes Usados

- 1 Arduíno Uno;
- 1 Placa Drive;
- 1 Motor de passo;
- 6 jumpers Macho/Fêmea

## Montagem do Circuito 

![Imagem do circuito](/MotorStepper/MotorStepper.png)

## Explicação do Código

#include <AccelStepper.h>

#include <MultiStepper.h>


-- conversão de graus para steps

-- 360º = 1024

-- 180º = 512

-- 90º = 256

-- 60º = 170

-- 45° = 128

-- 30º = 85

-- 15º = 28

--Variável para controlar as voltas do motor 

#define Voltas  1024

-- criando objeto para 

AccelStepper motor (AccelStepper::FULL4WIRE, 8, 10, 9, 11);

void setup() {

 -- definir a velocidade máxima do motor

 motor.setMaxSpeed(1000);

-- definir a aceleração máxima do motor

motor.setAcceleration(2000);

}

void loop() {

 -- habilitar as portas de controle do motor no arduino 

 motor.run();

 --fazer o motor se movimentar a 360º/1024

 motor.moveTo(Voltas);

 if(motor.distanceToGo() == 0){

 -- girar no sentido contrário 

 motor.moveTo(-motor.currentPosition());

 }

}
