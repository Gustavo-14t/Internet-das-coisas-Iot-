
int R = 6;  //porta vermelha
int G = 3;  //porta verde
int B = 5;  //porta azul

int R2 = 9;  
int G2 = 10;  
int B2 = 11; 

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(B2, OUTPUT);
}

void loop()
{
  int v1 = random(0,255);
  int v2 = random(0,255);
  int v3 = random(0,255);
  
  analogWrite(R, v1);
  analogWrite(G, v2);
  analogWrite(B, v3);
  
  delay(0); // Wait for 1000 millisecond(s)
  
  analogWrite(R2, v1+v2);
  analogWrite(G2, v2+v3);
  analogWrite(B2, v3+v1);
  
  delay(0); // Wait for 1000 millisecond(s)
  
  
	
}
