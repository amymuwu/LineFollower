void loop() {
  //Turns LED on/off
  LED(sread1, sread2, sread3, sread4, sread5);
  updatepos (senpos);
  // print the results to the Serial Monitor:
 //prototyping purposes only 
 //printr(sread1, sread2, sread3, sread4, sread5);//prints reading for protoyping purposes
 for (int i = 0; i < 5; i++){
  Serial.print(senpos[i]);
 }
 Serial.print("\n");
 
//modes
 
//no line mode [0 0 0 0 0]
if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = NOLINE;
}
 
//on line - no correction needed [0 0 1 0 0]
else if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 1)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = ONLINE;
}
//on line - correction through slight left [0 0 1 1 0] 
else if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 1)&&(senpos[3] == 1)&&(senpos[4] == 0)){
  mode = FOLLOWSR;
}
//on line - correction through slight right [0 1 1 0 0]
else if ((senpos[0] == 0)&& (senpos[1] == 1)&&(senpos[2] == 1)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = FOLLOWSL;
}

//on line - correction right [0 0 0 1 0] 
else if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 0)&&(senpos[3] == 1)&&(senpos[4] == 0)){
  mode = FOLLOWR;
}
//on line - correction through left [0 1 0 0 0]
else if ((senpos[0] == 0)&& (senpos[1] == 1)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = FOLLOWL;
}
//turn right [0 0 0 1 1] 
else if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 1)){
  mode = SR;
}
//turn left [1 1 0 0 0]
else if ((senpos[0] == 1)&& (senpos[1] == 1)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = SL;
}

//turn right [0 0 0 0 1]
else if ((senpos[0] == 0)&&(senpos[1] == 0)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 1)){
  mode = RIGHT;
}
//turn left [1 0 0 0 0]
else if ((senpos[0] == 1)&& (senpos[1] == 0)&&(senpos[2] == 0)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = LEFT;
}
//intersection [1 1 1 1 1]
else if ((senpos[0] == 1)&& (senpos[1] == 1)&&(senpos[2] == 1)&&(senpos[3] == 1)&&(senpos[4] == 1)){
  mode = INTERSECTION;
}
//intersection [0 1 1/0 1 0]
else if ((senpos[0] == 0)&& (senpos[1] == 1)&&(senpos[3] == 1)&&(senpos[4] == 0)){
  mode = INTERSECTION;  
}  
//intersection [1 1 1/0 1 1]
else if (((senpos[0] == 1)||(senpos[4] == 1))&& (senpos[1] == 1)&&(senpos[3] == 1)){
  mode = INTERSECTION;
}
//intersection [0 0 1 1 1]
else if ((senpos[0] == 0)&& (senpos[1] == 0)&&(senpos[2] == 1)&&(senpos[3] == 1)&&(senpos[4] == 1)){
  mode = INTERSECTION;  
}
//intersection [1 1 1 0 0]
else if ((senpos[0] == 1)&& (senpos[1] == 1)&&(senpos[2] == 1)&&(senpos[3] == 0)&&(senpos[4] == 0)){
  mode = INTERSECTION;  
}
else if ((senpos[0] == 1)&& (senpos[1] == 0)&&(senpos[2] == 1)&&(senpos[3] == 0)&&(senpos[4] == 1)){
  mode = GAP;
}
else {
  mode = STOP;
}

/*
//TESTING [1 1 1 1 1]
if ((senpos[0] == 1)&& (senpos[1] == 1)&&(senpos[2] == 1)&&(senpos[3] == 1)&&(senpos[4] == 1)){
  mode = STOP;
}
*/
Serial.print(mode);
Serial.print("\n");


//robot movements
switch (mode) {
    case NOLINE:
      digitalWrite(LMEn, HIGH);
      digitalWrite(RMEn, HIGH);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(DELAYTIME);
      break;
       
    case ONLINE:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 255;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(300);
      updatepos(senpos);
      if (((senpos[0] == 1)&&(senpos[4] == 1))||(((senpos[1] != 1)&&(senpos[3] != 1)))){
        mode = GAP;
        break;
      }
      break;

      case FOLLOWSR:
      RMSpeed = 200; //speed from 0 to 255
      LMSpeed = 255;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(DELAYTIME);
      break;
      
      case FOLLOWSL:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 200;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);      
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(DELAYTIME);
      break;

      case FOLLOWR:
      RMSpeed = 100; //speed from 0 to 255
      LMSpeed = 255;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(200);
      break;
      
      case FOLLOWL:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 100;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(200);
      break;
      
      case SR:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 255;
      while (senpos[2] != 1){
        analogWrite(LMEn, LMSpeed);
        analogWrite(RMEn, RMSpeed);
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, HIGH);
        digitalWrite(RM2, LOW);
        updatepos (senpos);
        delay (DELAYTIME);
      }

      
      break;
      
      case SL:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 255;
      while (senpos[2] !=1){
        analogWrite(LMEn, LMSpeed);
        analogWrite(RMEn, RMSpeed);
        digitalWrite(LM1, HIGH);
        digitalWrite(LM2, LOW);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, HIGH);
        updatepos (senpos);
        delay (DELAYTIME);      
      }
      break;
      
      case RIGHT:
      RMSpeed = 0; //speed from 0 to 255
      LMSpeed = 150;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      while (senpos[3] != 1){
        analogWrite(LMEn, LMSpeed);
        analogWrite(RMEn, RMSpeed);
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, HIGH);
        updatepos (senpos);
        delay (DELAYTIME);      
      }
      break;
      
      case LEFT:
      RMSpeed = 150; //speed from 0 to 255
      LMSpeed = 0;
      while (senpos[1] !=1){
        analogWrite(LMEn, LMSpeed);
        analogWrite(RMEn, RMSpeed);
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, HIGH);
        updatepos (senpos);
        delay (DELAYTIME);      
      }
      break;
      
      case INTERSECTION:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 255;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(500);
      break;
       
      case STOP: 
      digitalWrite(LMEn, LOW);
      digitalWrite(RMEn, LOW);
      break;

      case GAP:
      RMSpeed = 255; //speed from 0 to 255
      LMSpeed = 255;
      analogWrite(LMEn, LMSpeed);
      analogWrite(RMEn, RMSpeed);
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      delay(500);
      break;
  }
}
