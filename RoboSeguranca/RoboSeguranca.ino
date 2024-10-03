#include <Servo.h>

Servo microServo;

int led = 5;
int servo = 2;

int posicao = 0;


long distancia(int trigger, int echo){ 
 // trigger porta de saída 
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);
  delay(5);//espera 5 milisegundos
  //mandando o sinal
  digitalWrite(trigger,HIGH);
  delay(10);//espere 10 milisegundos
  digitalWrite(trigger,LOW);
  
 // echo porta de entrada
  pinMode(echo,INPUT);
  
  return pulseIn(echo,HIGH);
  
}
void setup()
{
  // inicializando o servo na porta digital  
  microServo.attach(servo);
  
  pinMode(led, OUTPUT);
  
  microServo.write(posicao); 
}

void loop()
{
  int cm = 0.01723 * distancia (1, 1);

  if(cm<30){
  	
    //MANDE O MOTOR PARA A NOVA POSIÇÃO
     posicao = posicao +5;
    microServo.write(posicao);
    digitalWrite(led, HIGH);
    delay(100);
    
  }else{
  	digitalWrite(led, LOW);
  }
}