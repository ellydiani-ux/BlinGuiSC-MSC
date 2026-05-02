#include "Arduino.h"
#include "SoundSens.h"


 SoundSens::SoundSens (){
   value_A0 = 0;
   value_D = 0;
   pin_analogic = A0;
   pin_digital = 10;
  lastRead = 0;
  currentRead =0;
  diff=0;
  count = 0;
  buff=0;
  ints=0;
  mean=0;
  intsd=0;
  buffd=0;
  meand=0;
 }
 void SoundSens::pinSound(){
 pinMode(pin_analogic, INPUT);
 pinMode(pin_digital, INPUT);
 Serial.begin(9600);
 } 
 
 double SoundSens:: getIntensityA(){  
   
  value_A0 = analogRead(pin_analogic);
  return value_A0;
  }


 double SoundSens:: getIntensityD(){
 value_D = digitalRead(pin_digital);
   return value_D;
   }

 boolean SoundSens:: noiseSound(){
   count++;
  ints = getIntensityA();
  intsd= getIntensityD();
       Serial.print("count:");  
      Serial.println(count);
      
  //  Serial.print("D:");  
   // Serial.println(getIntensityD()); 
    if(count<=100){   
 
  Serial.print("ints:");  
  Serial.print(ints);
  
  Serial.print("intsDg:");  
  Serial.println(intsd);

      buff= buff + ints;
      buffd= buffd + intsd;

      }
   if(count==10){    
      mean=buff/count;
      meand=(buffd/count)*10;
        Serial.print("****************************");   
      Serial.print("buff:");  
      Serial.println(buff);
     
      Serial.print("count:");  
      Serial.println(count);
      
       Serial.print("mean");
      Serial.println(mean);
  
  
     Serial.print("buffdigital:");  
      Serial.println(buffd);
     
  
       Serial.print("meanDigital::");
      Serial.println(meand);
     currentRead = mean;

     diff = abs(currentRead - lastRead);
     lastRead = currentRead;
      Serial.print("diff");
      Serial.println(diff);
      Serial.println("****************************");   

count = 0;    
buff= 0;
buffd= 0;
     
     }
      if((meand >=3) || (diff >= 1) ){
        Serial.println("**********barulho******************");   
       return true;
   }
   else{
   return false;
   }
   
 }
 
     
    
