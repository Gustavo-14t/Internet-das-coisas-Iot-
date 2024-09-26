// C++ code
//
int led = 4;
int sensorLuminosidade = A0;
int luz = 0;
//Variável para capturar a luminosidade.

void setup(){
 //Led é de saída
 //pinMode(led,OUTPUT);
  
 //sensorLuminosidade é de entrada 
 pinMode(sensorLuminosidade, INPUT);

}

void loop(){
  //Capturar o que o sensor leu no ambiente 
  //analogRead é usado para leitura analógica
  
  luz = analogRead(sensorLuminosidade);
  /* as portas analógicas capturam dados que variam  de
   0 até 1023 */
  if(luz<500){
    
    //digitalWrite(led, HIGH);//LIGAR LED
    
  }else{
    
    digitalWrite(led, LOW); // DESLIGAR LED

  }
  
}