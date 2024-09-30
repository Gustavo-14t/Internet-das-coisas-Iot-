# Projeto de Tela LCD com sensor de distância

Este projeto foi desenvolvido dentro do Thinkercad, na disciplina de Internet das Coisas 
(IOT), onde foi criado um protótipo que simula um hardware qeu consegue ler a temperatura 
do ambiente e retorna na placa LCD uma mensagem informando a temperatura atual.

## Componentes Usados 

- 1 Arduíno Uno;
- 1 Protoboard (Placa de Ensaio);
- 1 LCD 16x2 (I2C);
- 1 Sensor de temperatura (TMP);
- 5 jumpers Macho/Macho;
- 4 Jumpers Macho/Fêmea;

  
## Montagem do Circuito

![Imagem do Circuito](/SensorTemperatura/SensordeTemperatura.png)

## Explicação do Código
// C++ code

// Biblioteca do LCD com Módulo 

#include <LiquidCrystal_I2C.h>

--INICIALIZAR LCD


LiquidCrystal_I2C telaLcd (0x20, 16,2);

-- variável do sensor de temperatura


int sensorTemp = A3;

int valorLido = 0;

void setup(){

 -- definir o sensor como entrada


  pinMode(sensorTemp, INPUT);}

  --ligar a tela lcd 


  telaLcd.init();

  --Limpar os dados que aparecem nela


  telaLcd.clear();  

}

void loop(){

  --capturar o valor da temperatura 


  valorLido = analogRead(sensorTemp);

  --converter valor da tensão recebido


  float tensao = (valorLido *5.0) /1024;

  -- converter a tensao em graus celsius


  float temperatura = (tensao-0.5)*100;

  --imprimir valor da temperatura


  telaLcd.setCursor(0,0);

  telaLcd.print("temp atual");

  telaLcd.setCursor(0,1);

  telaLcd.print(temperatura);  

}
