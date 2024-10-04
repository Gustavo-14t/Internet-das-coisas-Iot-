//Incluindo a biblioteca para a ultilização do servo motor
#include <Servo.h>

/*Criando objeto do tipo Servo motor para poder usar as 
funções de controle do equipamento(servo motor)*/
Servo objetoServo;

//variável para salvar a porta que servo motor está conectado
int servo = 0;

//variável para a porta do botão
int botao1 = 1;
int botao2 = 2;

//variável para posição do motor
int posicao = 0;


void setup()
{
  // inicializando o servo na porta digital  
  objetoServo.attach(servo);
  
  //definir botão como entrada
  pinMode(botao1,INPUT);

  pinMode(botao2,INPUT);

  posicao = 0;
  objetoServo.write(posicao);
}

void loop()
{
  /*SE BOTÃO FOR PRESSIONADO E POSIÇÃO DO SERVO MOTOR ESTIVER
   MENOR QUE 180º*/
  if(digitalRead(botao1)==HIGH && posicao<180 ){
  //MANDE O MOTOR PARA A NOVA POSIÇÃO
     posicao = posicao +20;
    objetoServo.write(posicao);
    delay(1000);
   
  }
  if(digitalRead(botao2)== HIGH && posicao > 0){
   //MANDE O MOTOR PARA A NOVA POSIÇÃO
        posicao = posicao - 20;
    objetoServo.write(posicao);
    delay(1000);
  
  }
}