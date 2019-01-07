void updatepos (int senpos[]){
  //updates array
  sread1 = analogRead(S1);
  sread2 = analogRead(S2);
  sread3 = analogRead(S3);
  sread4 = analogRead(S4);
  sread5 = analogRead(S5);
  //updates array
  senpos[0] = (sread1 > THRESH);
  senpos[1] = (sread2 > THRESH);
  senpos[2] = (sread3 > THRESH);
  senpos[3] = (sread4 > THRESH);
  senpos[4] = (sread5 > THRESH);
  //updates LED
  LED(sread1, sread2, sread3, sread4, sread5);
}
void printr (int sen1, int sen2, int sen3, int sen4, int sen5){
  Serial.println("S1 = ");
  Serial.println(sen1);
  Serial.print('\n'); 
  Serial.println("S2 = ");
  Serial.print(sen2);
  Serial.print('\n'); 
  Serial.println("S3 = ");
  Serial.print(sen3);
  Serial.print('\n'); 
  Serial.println("S4 = ");
  Serial.print(sen4);
  Serial.print('\n'); 
  Serial.println("S5 = ");
  Serial.print(sen5);
  Serial.print('\n'); 
}

void LED(int sread1, int sread2, int sread3, int sread4, int sread5){
  if (sread1 > THRESH){
    analogWrite(LED1, 255);
  }
  else{
    analogWrite(LED1, 0);
  }
  if (sread2 > THRESH){
    analogWrite(LED2, 255);
  }
  else{
    analogWrite(LED2, 0);
  }
  if (sread3 > THRESH){
    analogWrite(LED3, 255);
  }
  else{
    analogWrite(LED3, 0);
  }
  if (sread4 > THRESH){
    analogWrite(LED4, 255);
  }
  else{
    analogWrite(LED4, 0);
  }
 if (sread5 > THRESH){
    analogWrite(LED5, 255);
  }
  else{
    analogWrite(LED5, 0);
  }
}
