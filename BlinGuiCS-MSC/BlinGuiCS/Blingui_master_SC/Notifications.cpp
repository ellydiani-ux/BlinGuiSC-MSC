#include "Arduino.h"
#include "Notifications.h"


 Notifications::Notifications (){
  pin_led_up = 42;
  pin_led_dow = 40;
  vib = 48;
  vib_up = 49;

  bip = 46;
  button = 44;
      // Pino ligado ao P-E (PLAYE) do modulo (5v)
  pino_playe = 9;
  button_press=0;
  button_states=0;
  
  
 }
 
 void Notifications:: pinNotification(){
   pinMode(vib, OUTPUT);  
   pinMode(vib_up, OUTPUT);  
   pinMode(bip, OUTPUT);  
   pinMode(pino_playe, OUTPUT);
   pinMode(button, INPUT); 
   pinMode(pin_led_up, OUTPUT); 
   pinMode(pin_led_dow, OUTPUT);
 }
 
 void Notifications::vibracallDow(){
  digitalWrite(vib, HIGH);   // turn the vibra on (HIGH is the voltage level)
  delay(200);               // wait for a secon    // wait for a second
  digitalWrite(vib, LOW);    // turn the vibra off by making the voltage LOW   

}

void Notifications::vibracallUp(){
  digitalWrite(vib_up, HIGH);   // turn the vibra on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(vib_up, HIGH);   // turn the vibra on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(vib_up, LOW);    // turn the vibra off by making the voltage LOW   
 
}

//bips
void Notifications:: bipDow(){
 tone(bip, 1440);
  delay(200);
  tone(bip, 1880);
  delay(200);
  noTone(bip);
   }


void Notifications:: bipUp(){ 
  tone(bip, 4000);
  delay(100);
  tone(bip, 4500);
  delay(200);
  noTone(bip);

  }

void Notifications::voice (){
  digitalWrite(pino_playe, HIGH);
  delay(100);
  digitalWrite(pino_playe, LOW);
}

void Notifications::light (){
  digitalWrite(pin_led_up, HIGH);
  delay(100);
  digitalWrite(pin_led_up, LOW);
  delay(200);
  
 }
 void Notifications::lightActivity (){
  digitalWrite(pin_led_dow, HIGH);
  delay(200);
  digitalWrite(pin_led_dow, LOW);
  delay(50);
 }
 
 void Notifications::alertObstacleRast (){
       vibracallDow();
       light();
       bipDow();
 }
 
 void Notifications::alertObstacleSusp (){
       vibracallUp();
       light();
       voice();       
   
 }


 //Para ambientes com ruídos obstaculo rasteiro /vibra e led
 void Notifications::alertPerNoiseRast(){
              vibracallUp();
              light();
           
 }

//Para ambientes com ruídos/obstaculo suspenso vibra, bip e led
 void Notifications::alertPerNoiseSusp(){
             vibracallUp();    
             bipUp();
             light();
        }


boolean Notifications::notificOff(){
  
if (buttonStates(button_states) == HIGH && button_states==LOW) { 
  button_press++;
  button_states = HIGH;
} 
  else if(buttonStates(button_states) == LOW && button_states==HIGH){
   button_states = LOW;
}

if (button_press == 2){
//  digitalWrite(pin_led_dow, HIGH);   // turn the vibra on (HIGH is the voltage level)
  return true;

 }

if (button_press > 2){
 button_press=0;
 //digitalWrite(pin_led_dow, LOW );   // turn the vibra on (HIGH is the voltage level)
 return false;
}

Serial.println(button_press);

}

boolean Notifications::buttonStates(boolean state){

  boolean stateNow =digitalRead (button);
  if (state!=stateNow){
  delay(2);
  stateNow = digitalRead(button);
  }
  return stateNow;
}
