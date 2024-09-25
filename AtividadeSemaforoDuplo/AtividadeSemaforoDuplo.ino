// C++ code
//
int ledVerde1 = 0;
int ledAmarelo1 = 1;
int ledVermelho1 = 2;

int verdePedestre1 = 6;
int vermelhoPedestre1 = 7;

int verdePedestre2 = 8;
int vermelhoPedestre2 = 9;

void setup()
{
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  
  pinMode(verdePedestre1, OUTPUT);
  pinMode(vermelhoPedestre1, OUTPUT);
  
  pinMode(verdePedestre2, OUTPUT);
  pinMode(vermelhoPedestre2, OUTPUT);
  
}
long distancia1(int trigger, int echo){ 
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
long distancia2(int trigger, int echo){ 
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


int x;
void loop()
{
  int cm1 = 0.01723 * distancia1 (10, 10);
  int cm2 = 0.01723 * distancia2 (11, 11);
  
  digitalWrite(ledVerde1, HIGH);
  
  if((cm1<50 || cm2<50)){x == 1;}
  if(x =1){ 
  digitalWrite(vermelhoPedestre1, LOW);
  digitalWrite(vermelhoPedestre2, LOW);
  digitalWrite(ledVerde1, LOW);
    
  delay(0);
  digitalWrite(ledAmarelo1,HIGH); 
  delay(2000);
  digitalWrite(ledAmarelo1,LOW);   
  digitalWrite(ledVermelho1,HIGH);
     
  digitalWrite(verdePedestre1,HIGH);
  digitalWrite(verdePedestre2,HIGH);
  delay(5000);
   
  digitalWrite(ledVermelho1,LOW);  
  }else {
    
  digitalWrite(ledVerde1, HIGH);
    
  digitalWrite(verdePedestre1,LOW);
  digitalWrite(vermelhoPedestre1, HIGH);
    
  digitalWrite(verdePedestre2,LOW);
  digitalWrite(vermelhoPedestre2, HIGH);
    delay(5000);
    x ==1;

  }
  
}