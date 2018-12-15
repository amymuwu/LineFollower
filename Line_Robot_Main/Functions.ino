//Function: Average Sensor Reading
  int ASR (int SensorPin, int readings, int errortol){
    int sum = 0; //sum of the readings
    int sensorValue;//sensor reading
    int sread; //scaled sensor reading 
    int readstore = analogRead(SensorPin); //reference to compare readings  
        
    for (int i=0; i<readings; i++){
      sensorValue = analogRead(SensorPin);
      sread = map(sensorValue, 0, 1023, 0, 255); //idk if i should have this 
      
//PROTOTYPING USE ONLY
/*Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\t output = ");
Serial.println(sread);*/
//PROTOTYPING USE ONLY
  
      if (abs(readstore - sread) < errortol) {
        sum = sum + sread;
      }
      else{
        i--;
      }
    }
    return sum/readings;
//PROTOTYPING USE ONLY
/*Serial.print("average reading = ");
Serial.print(sum/readings);*/
///PROTOTYPING USE ONLY
}

//Function: Position Array Updater
int posArr (int sen1avg, int sen2avg, int sen3avg, int sen4avg, int sen5avg){
  int posArr [5] = {0,0,0,0,0};
  posArr[0] = sen1avg;
  posArr[1] = sen2avg;
  posArr[2] = sen3avg;
  posArr[3] = sen4avg;
  posArr[4] = sen5avg;
}
