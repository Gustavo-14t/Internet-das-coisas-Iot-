int sensorPIR = 5;
int buzzer = 3;
int led = 2;

void setup(){

  pinMode(sensorPIR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop (){

  int detectarPresenca = digitalRead(sensorPIR);
  
  if (detectarPresenca == 1){
 	
    tone(buzzer,220);
    digitalWrite(led, HIGH);
    delay(10000);
  }else{
    digitalWrite(led, LOW);
  	noTone(buzzer);
  }
  
}