# Projeto Labirinto com Arduíno

Este projeto foi desenvolvido em sala de aula para a feira de Robótica, na disciplina de Internet das Coisas 
(IOT), onde buscamos inspiração em diversas fontes como: 
Vídeo do canal Vinícius Cotrim: https://www.youtube.com/watch?v=7VWGwW_tDhs
Esse vídeo serviu de base para o design visual do nosso projeto.
Site do Emerson Carvalho: https://www.youtube.com/watch?v=7VWGwW_tDhs
Site que nos pegamos o código e modificamos segundo as nossas necessidades.
O objetivo do jogo é sair de uma das entradas e chegar até a outra, controlado o labirinto com um
joystick, esse movimenta o labirinto para frente, trás e lados.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 Módulo Joystick analógico;
- 2 Micro servo motores 9g;
- 8 jumpers Macho/Macho;
- 4 jumpers Macho/Fêmea;

## Montagem do Circuito
![Imagem do Circuito](/Lab3dProjeto/Lab3d.jpeg)

## Explicação do Código

#include 

Servo myServoX; // define servo motor for X-axis 

Servo myServoY; // define servo motor for Y-axis 

int ServoXPin = 10; // define  X-axis pin

int ServoYPin = 9; // define  Y-axis pin

int ServoXHomePos =90; // set home position for servos

int ServoYHomePos =80; 

int ServoXPos =103;

int ServoYPos =135; 

int XAxlePin = A0; // define  X-axis pin control for joystick A0

int YAxlePin = A1; // define  Y-axis pin control for joystick A1

int XAxleValue = 0; // set start up value for joystick

int YAxleValue = 0;

int Direction = 0;

int range = 12; // output range of X or Y movement

int center = range/2; // resting position value

int threshold = range/4; // resting threshold

void setup()

{

myServoX.attach(ServoXPin); // attaching servo X 

myServoY.attach(ServoYPin); // attaching servo Y

ServoXPos = ServoXHomePos;  // update ServoXPos with home position as startup

ServoYPos = ServoYHomePos;  // update ServoYPos with home position as startup

myServoX.write(ServoXPos);

myServoY.write(ServoYPos);

Serial.begin(9600);

}

void loop()

{

XAxleValue = readAxis(XAxlePin);

YAxleValue = readAxis(YAxlePin);



Serial.print(XAxleValue,DEC);

Serial.print(" - ");

Serial.println(YAxleValue,DEC);



// check the values of joystick and move the servos smothly with delay of 100 millisecond

if (XAxleValue>0) { ServoXPos--; myServoX.write(ServoXPos); delay(100*(7-XAxleValue)); }

if (XAxleValue<0) { ServoXPos++; myServoX.write(ServoXPos); delay(100*(7+XAxleValue)); }

if (YAxleValue>0) { ServoYPos++; myServoY.write(ServoYPos); delay(100*(7-YAxleValue)); }

if (YAxleValue<0) { ServoYPos--; myServoY.write(ServoYPos); delay(100*(7+YAxleValue)); }





if (ServoXPos>ServoXHomePos+20) { ServoXPos=ServoXHomePos+20; }

if (ServoXPos<ServoXHomePos-20) { ServoXPos= ServoXHomePos-20; }

if (ServoYPos>ServoYHomePos+20) { ServoYPos=ServoYHomePos+20; }

if (ServoYPos<ServoYHomePos-20) { ServoYPos= ServoYHomePos-20; }

delay(10);

}

int readAxis(int thisAxis) {

// read the analog input:

int reading = analogRead(thisAxis);

// map the reading from the analog input range to the output range:

reading = map(reading, 0, 1023, 0, range);

// if the output reading is outside from the

// rest position threshold, use it:

int distance = reading - center;

if (abs(distance) < threshold) {

distance = 0;

}

// return the distance for this axis:

return distance;

}
