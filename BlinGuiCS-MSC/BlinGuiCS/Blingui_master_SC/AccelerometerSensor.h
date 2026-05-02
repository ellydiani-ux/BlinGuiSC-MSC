#ifndef AccelerometerSensor_h
#define AccelerometerSensor_h

#include "Arduino.h"
#include <Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050

class AccelerometerSensor{
  
    public: 
    AccelerometerSensor();
    void pinAccelerometer();
    void meanAcelerometro();
    
    public:
    int pin_;
    int mean_ax,mean_ay,mean_az,mean_gx,mean_gy,mean_gz,state;
    int buffersize;  
    int16_t ax, ay, az,gx, gy, gz;
    int ax_offset,ay_offset,az_offset, gx_offset, gy_offset, gz_offset;
    int acel_deadzone;    
   
    int lastRead_ax;
    int currentRead_ax;
    int diff_ax;
    int lastRead_ay;
    int currentRead_ay;
    int diff_ay;
    int lastRead_az;
    int currentRead_az;
    int diff_az;
    
    int lastRead_gx;
    int currentRead_gx;
    int diff_gx;
    int lastRead_gy;
    int currentRead_gy;
    int diff_gy;
    int lastRead_gz;
    int currentRead_gz;
    int diff_gz;


};

#endif 








