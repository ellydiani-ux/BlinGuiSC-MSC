 #include "UltrasonicSensor.h"
 #include "Arduino.h"

  UltrasonicSensor::UltrasonicSensor (){
      lastTime=0;
      currentTime=0;
      speeds=0;
      }
      
      
    void UltrasonicSensor::pinSonar(){
        Serial.begin(9600); 
        pinMode(trigPin1, OUTPUT);
        pinMode(echoPin1, INPUT);
        pinMode(trigPin2, OUTPUT);
        pinMode(echoPin2, INPUT);
        pinMode(trigPin3, OUTPUT);
        pinMode(echoPin3, INPUT);
        pinMode(trigPin4, OUTPUT);
        pinMode(echoPin4, INPUT);


        }
        
     double UltrasonicSensor::sonarCalcDistance(int trigPin,int echoPin){
          digitalWrite(trigPin, LOW);
          delayMicroseconds(1);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(1);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          distance = duration /29.4 / 2 ; 
       //   Serial.println(distance);
    //   if (distance< 500){
          return distance;
      // }
       //return sonarCalcDistance(trigPin, echoPin);
          }
  
      void UltrasonicSensor::sonarDistPerDirection(){    
          frontSensor = sonarCalcDistance(trigPin1, echoPin1);
          dowSensor = sonarCalcDistance(trigPin2, echoPin2);
          upSensor = sonarCalcDistance(trigPin3, echoPin3);
          upSensor_aux = sonarCalcDistance(trigPin4, echoPin4);

        }
        
        /* //possíveis tipos de obstaculos
        void UltrasonicSensor::obstacleType(){
        sonarDistPerDirection();
          //1-obstaculo rasteiro total ex: parede, porta //classificaçao, já tem na base de dados
         //2- obstaculo rasteiro parcial
         //3- obstaculo rasteiro
          if ((dowSensor < upSensor) & (frontSensor <upSensor){
          
          }
          //4- obstáculo supenso
          if ((upSensor<dowSensor) & (frontSensor <dowSensor)){
          
          }     
          
        }*/

  void UltrasonicSensor::sonarCalcSpeed(){
    Serial.print("distance1: ");        
    lastDistFront = sonarCalcDistance(trigPin1, echoPin1);
    Serial.println(lastDistFront);
    
    Serial.print("Tempo1: ");
    lastTime = millis();
    Serial.println(lastTime);
    
    Serial.print("distance2:"); 
    currentDistFront = sonarCalcDistance(trigPin1, echoPin1);
    Serial.println(currentDistFront);
    
    Serial.print("Tempo2:");  
    currentTime = millis();
    Serial.println(currentTime);

    variatDist = abs(lastDistFront - currentDistFront); 
    Serial.print("Deslocamento:");
    Serial.println(variatDist);
    
    variatTime = abs(currentTime-lastTime);
    Serial.print("Tempo variacao::");
    Serial.println(abs(currentTime-lastTime));
     
    Serial.print("Velocidade::");
    speeds = (variatDist)/ (variatTime);
    Serial.println(speeds);
   
  }
  
