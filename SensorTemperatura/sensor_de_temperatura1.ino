// C++ code
// Biblioteca do LCD com Módulo 
#include <LiquidCrystal_I2C.h>

//INICIALIZAR LCD
LiquidCrystal_I2C telaLcd (0x20, 16,2);

// variável do sensor de temperatura
int sensorTemp = A3;
int valorLido = 0;

void setup(){
 // definir o sensor como entrada
  pinMode(sensorTemp, INPUT);
  
  //ligara a tela lcd 
  telaLcd.init();
  
  //Limpar os dados que aparecem nela
  telaLcd.clear();
  
}

void loop(){
  
  //capturar o valor da temperatura 
  valorLido = analogRead(sensorTemp);
  
  //converter valor da tensão recebido
  float tensao = (valorLido *5.0) /1024;
  
  // converter a tensao em graus celsius
  float temperatura = (tensao-0.5)*100;
  
  //imprimir valor da temperatura
  telaLcd.setCursor(0,0);
  telaLcd.print("temp atual");
  telaLcd.setCursor(0,1);
  telaLcd.print(temperatura);
  
  
}