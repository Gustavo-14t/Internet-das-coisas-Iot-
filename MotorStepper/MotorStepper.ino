#include <AccelStepper.h>
#include <MultiStepper.h>

//Incluindo a biblioteca


// conversão de graus para steps
// 360º = 1024
// 180º = 512
// 90º = 256
// 60º = 170
// 45° = 128
// 30º = 85
// 15º = 28

//Variável para controlar as voltas do motor 
#define Voltas  1024
// criando objeto para 
AccelStepper motor (AccelStepper::FULL4WIRE, 8, 10, 9, 11);

void setup() {
 // definir a velocidade máxima do motor
 motor.setMaxSpeed(1000);
//definir a aceleração máxima do motor
motor.setAcceleration(2000);

}

void loop() {
 // habilitar as portas de controle do motor no arduino 
 motor.run();
 //fazer o motor se movimentar a 360º/1024
 motor.moveTo(Voltas);

 if(motor.distanceToGo() == 0){
 // girar no sentido contrário 
 motor.moveTo(-motor.currentPosition());
 
 }
}
