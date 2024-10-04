//Incluindo a biblioteca para a ultilização do servo motor
#include <Servo.h>

/*Criando objeto do tipo Servo motor para poder usar as 
funções de controle do equipamento(servo motor)*/
Servo objetoServo;

//variável para salvar a porta que servo motor está conectado
int servo = 0;

void setup()
{
  // inicializando o servo na porta digital  
  objetoServo.attach(servo);
}

void loop()
{
  // servo rotacionar a 45°
  objetoServo.write(45);
  delay(2000);
  // servo rotacionar a 90°
  objetoServo.write(90);
  delay(2000);
  // servo rotacionar a 135°
  objetoServo.write(135);
  delay(2000);
  // servo rotacionar a 180°
  objetoServo.write(180);
  delay(2000);
  // servo rotacionar a 45°
  objetoServo.write(135);
  delay(2000);
  // servo rotacionar a 90°
  objetoServo.write(90);
  delay(2000);
  // servo rotacionar a 135°
  objetoServo.write(45);
  delay(2000);
  //servo rotacionar a 0°
  objetoServo.write(0);
  delay(2000);
}