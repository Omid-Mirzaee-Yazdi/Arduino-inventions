#include "Arduino.h"
int firstr=0;

void setup(){

 Serial.begin(115200);
 pinMode(4, OUTPUT);
 pinMode(9, OUTPUT);
}

void loop()
{
   if( Serial.available()>0) {
    firstr=1;
    int pin = Serial.parseInt();
    int par = Serial.parseInt();
    if (par==1){
       digitalWrite(pin, LOW); 
    }else if(par==0){
      digitalWrite(pin, HIGH); 
    }
    Serial.println(pin);
    Serial.println(par);

  }
      


}
