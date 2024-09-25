// C++ code
//
#include <LiquidCrystal.h>

// criar variável do lcd
LiquidCrystal lcd = {2,3,4,9,10,11,12};

//Método para capturar a distância
//retorna número quebrado longo
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

int ledLcd = 13;
char z [20] = "Manter Distancia";
char x [12] = "ALERTA";
void setup()
{
   
 pinMode (ledLcd, OUTPUT);
  pinMode (ledLcd,OUTPUT); //DEFINIR LEDLCD SAIDA
  digitalWrite(ledLcd,HIGH);//Ligar os LEDs do LCD
  lcd.begin(16,2);//informar que po lcd tem 16 colunas e 2 linhas
  lcd.clear();//informar o lcd limpo
}


void loop()
{
 
  //Transformar o valor recebido em centímetros
  int cm = 0.01723 * distancia (8, 8);
  
  if (cm<100){//se menor que 1 metro/100cm
  
  
  
  lcd.setCursor(0,0);// iniciar a escrita na linha 0 coluna 0
  lcd.print(x);
  lcd.setCursor(0,1);
  lcd.print(z);
    delay(50);
	lcd.clear();

 ;
  }else{
    lcd.clear();
  };
  
 
  
  
}