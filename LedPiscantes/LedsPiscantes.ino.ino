// C++ code
//
int ledVerde1 = 0;
int ledVerde2 = 1;
int ledVermelho1 = 2;
int ledVermelho2 = 3;
int ledAzul1 = 4;
int ledAzul2 = 5;

void setup()
{
 pinMode(ledVerde1, OUTPUT);
 pinMode(ledVerde2, OUTPUT);
  
 pinMode(ledVermelho1, OUTPUT);
 pinMode(ledVermelho2, OUTPUT);
  
 pinMode(ledAzul1, OUTPUT);
 pinMode(ledAzul2, OUTPUT);

}

void loop()
{
  digitalWrite(ledVerde1, HIGH);
  digitalWrite(ledVermelho1, HIGH);
  digitalWrite(ledAzul1, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
 
  digitalWrite(ledVermelho1,LOW);
  
  digitalWrite(ledVerde2, HIGH);
  digitalWrite(ledAzul2, HIGH);
  delay(3000);
  
  digitalWrite(ledVerde2,LOW);
  digitalWrite(ledAzul2,LOW);
  
  digitalWrite(ledVermelho1,HIGH);
  digitalWrite(ledVermelho2,HIGH);

  delay(3000);
  
  digitalWrite(ledVermelho2,LOW);
  
}