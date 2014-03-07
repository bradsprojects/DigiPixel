#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


void setup(){
  
}


void loop(){
  for (byte x = 0; x <= 7; x++){
    for (byte y = 0; y <= 7; y++){
      for (byte z = 0; z <= 7; z++){
        digiPixel.setPixel(y, z, x);
        digiPixel.drawScreen();
      }
    }
  }
}





