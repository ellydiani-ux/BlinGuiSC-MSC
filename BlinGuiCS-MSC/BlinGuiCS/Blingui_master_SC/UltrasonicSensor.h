#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h
#include "Arduino.h"

#define trigPin1 3 //front 
#define echoPin1 2 //front
#define trigPin2 6 //dow 
#define echoPin2 5 //dow 
#define trigPin3 7 //up 
#define echoPin3 8 //up 
#define trigPin4 36//up 
#define echoPin4 38//up 


class UltrasonicSensor {
  
    public: 
    UltrasonicSensor();
    void pinSonar();
    double sonarCalcDistance(int trigPin,int echoPin);
    void sonarDistPerDirection();
    void sonarCalcSpeed();

    
    public:
    double duration, distance, frontSensor, dowSensor, upSensor,upSensor_aux,lastDistFront, lastTime, currentDistFront, currentTime,speeds,variatDist, variatTime;
   // double menorDistance;
    //String typeObstacle;


};

#endif 








