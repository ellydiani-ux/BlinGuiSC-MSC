//#ifndef SoundSens_h
//#define SoundSens_h
#include "Arduino.h"

class SoundSens{

   public: 

    SoundSens();
    double getIntensityA();
    double getIntensityD();
    void pinSound();
    boolean noiseSound();
     
    public:
    
    double value_A0;
    double value_D;
    int pin_analogic;
    int pin_digital;
    double lastRead;
    double currentRead;
    double diff;
    double count;
    double buff;
    double ints;
    double mean;
    double intsd;
    double buffd;
    double meand;
};
