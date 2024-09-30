// C++ code
//
int ledVerde = 7;
int ledVermelho = 2;
int ledAmarelo = 4;

void setup()
{
  pinMode(ledVerde,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);
}

void loop()
{
  digitalWrite(ledVerde, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(ledVerde, LOW);
  
  digitalWrite(ledAmarelo, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(ledAmarelo, LOW);
  
  digitalWrite(ledVermelho, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(ledVermelho, LOW);
}