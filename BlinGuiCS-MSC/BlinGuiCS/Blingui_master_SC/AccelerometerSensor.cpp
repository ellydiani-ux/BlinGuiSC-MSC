#include "Arduino.h"
#include "AccelerometerSensor.h"


 AccelerometerSensor::AccelerometerSensor(){
     buffersize=100;  
     ax=0;
     ay=0;
     az=0;
     gx=0;
     gy=0;
     gz=0;
     acel_deadzone=8;
   
     mean_ax=0;
     mean_ay=0;
     mean_az=0;
     mean_gx=0;
     mean_gy=0;
     mean_gz=0;
     state=0;
     
     lastRead_ax = 0;
     currentRead_ax=0;
     diff_ax=0;
     lastRead_ay = 0;
     currentRead_ay=0;
     diff_ay=0;
     lastRead_az = 0;
     currentRead_az=0;
     diff_az=0;
    
     lastRead_gx = 0;
     currentRead_gx=0;
     diff_gx=0;
     lastRead_gy = 0;
     currentRead_gy=0;
     diff_gy=0;
     lastRead_gz = 0;
     currentRead_gz=0;
     diff_gz=0;
     }
 
 
 void AccelerometerSensor::pinAccelerometer(){
 //setup porta 13
  Wire.begin();
  // initialize device
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  
}

void AccelerometerSensor:: meanAcelerometro(){
  long i=0,buff_ax=0,buff_ay=0,buff_az=0,buff_gx=0,buff_gy=0,buff_gz=0;

  while (i<(buffersize+11)){
    // read raw accel/gyro measurements from device
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
 Wire.endTransmission(false);
 Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
 ax=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
 ay=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
 az=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 gx=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
 gy=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
 gz=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
      
    if (i>10 && i<=(buffersize+100)){ //First 100 measures are discarded
      buff_ax=buff_ax+ax;
      buff_ay=buff_ay+ay;
      buff_az=buff_az+az;
      buff_gx=buff_gx+gx;
      buff_gy=buff_gy+gy;
      buff_gz=buff_gz+gz;  
  }
    if (i==(buffersize+10)){
    //  int ready=0;
      
      mean_ax=buff_ax/buffersize;
      mean_ay=buff_ay/buffersize;
      mean_az=buff_az/buffersize;
    
      mean_gx=buff_gx/buffersize;
      mean_gy=buff_gy/buffersize;
      mean_gz=buff_gz/buffersize;
       
      currentRead_ax = mean_ax;
      currentRead_ay = mean_ay;
      currentRead_az = mean_az;
      currentRead_gx = mean_gx;
      currentRead_gy = mean_gy;
      currentRead_gz = mean_gz;
      
      diff_ax = abs(currentRead_ax - lastRead_ax);
      diff_ay = abs(currentRead_ay - lastRead_ay);
      diff_az = abs(currentRead_az - lastRead_az);
      diff_gx = abs(currentRead_gx - lastRead_gx);
      diff_gy = abs(currentRead_gy - lastRead_gy);     
      diff_gz = abs(currentRead_gz - lastRead_gz);
      
      lastRead_ax = currentRead_ax;
      lastRead_ay = currentRead_ay;
      lastRead_az = currentRead_az;
      lastRead_gx = currentRead_gx;
      lastRead_gy = currentRead_gy;
      lastRead_gz = currentRead_gz;
   }
    i++;
    
   }
}


  
  
  

