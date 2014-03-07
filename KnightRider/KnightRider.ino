#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Variables
byte ScanDelay = 5;
byte ThisPixel = 0;
byte color = 1;
boolean GoingRight = true;

void setup(){
}


void loop(){ 
  digiPixel.setPixel(ThisPixel, 0, color);
  digiPixel.drawScreen();            
  digiPixel.setPixel(ThisPixel, 0, 0);
  MovePixel();
}


void MovePixel(){
  if (ScanDelay != 0){
    ScanDelay--;
  }
  else{
    ScanDelay = 3;
    if(GoingRight == true){
      ThisPixel++;
      if (ThisPixel == 8){
        ThisPixel = 6;
        GoingRight = false;
        color++;
        if (color > 7){
          color = 1;
        }
      }
    }
    else{
      ThisPixel--;
      if (ThisPixel == 255){
        ThisPixel = 1;
        GoingRight = true;
      }
    }
  }
}





