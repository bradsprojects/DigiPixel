#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Variables
byte BoxDelay = 2;


void setup(){
}


void loop(){ 
  drawRandomBoxes();
  digiPixel.drawScreen();      
}

void drawRandomBoxes(){
  if (BoxDelay != 0){
    BoxDelay--;
  }
  else{
    BoxDelay = 2;
    digiPixel.drawBox(random(8), random(8), random(8), random(8), random(8)); 
  }
}





