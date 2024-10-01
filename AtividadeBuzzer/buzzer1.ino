int buzzer = 3;
  
#define doo 261.2
#define re 294
#define mi 330
#define fa 349

void setup()
{
}

void loop()
{
  //FUNÇÃO DE LIGAR tone()
  tone(buzzer,doo,500);
  delay(600); //Espera 6 segundos
  tone(buzzer,re,500);
  delay(600); //Espera 6 segundos
  tone(buzzer,mi,500);
  delay(600); //Espera 6 segundos
  tone(buzzer,fa,500);
  delay(600); //Espera 6 segundos
  
  //FUNÇÃO DE DESLIGAR noTone()
  noTone(buzzer);
  
}