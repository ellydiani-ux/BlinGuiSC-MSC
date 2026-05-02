//#ifndef Notifications_h
//#define Notifications_h
#include "Arduino.h"

class Notifications{

   public: 

    Notifications();
    void pinNotification();
    void vibracallDow();
    void vibracallUp();
    void bipDow();
    void bipUp();
    void voice();
    void light();
    boolean notificOff(); 
    boolean buttonStates(boolean state);
    void alertObstacleRast();
    void alertObstacleSusp();
    void alertPerNoiseRast();
    void alertPerNoiseSusp();
    void lightActivity();
    public:

    int vib;
    int vib_up;
    int bip;
    int pino_playe;
    int button;
    int button_press;
    int button_states;
    int pin_led_up;
    int pin_led_dow;
    
};
