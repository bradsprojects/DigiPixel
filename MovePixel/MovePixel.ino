// use the directional buttons to move a single pixel around the screen. Use the A button to change the pixel color

#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

byte pixelX = 3;
byte pixelY = 3;
byte pixelColor = 1;
byte buttonDelay = 5;


void setup(){
  
}


void loop(){ 
  movePixel();
  saveGraphics();
  digiPixel.saveButtonStates();
  digiPixel.drawScreen();          
}

void movePixel(){
  if (buttonDelay != 0){
    buttonDelay--; 
  }
  else{
    if (digiPixel.buttonUpPressed == true & pixelY < 7){
      buttonDelay = 5;
      pixelY++;
    }
    if (digiPixel.buttonDownPressed == true & pixelY > 0){
      buttonDelay = 5;
      pixelY--;
    } 
    if (digiPixel.buttonLeftPressed == true & pixelX > 0){
      buttonDelay = 5;
      pixelX--;
    }
    if (digiPixel.buttonRightPressed == true & pixelX < 7){
      buttonDelay = 5;
      pixelX++;
    } 
    if (digiPixel.buttonAPressed == true){
      buttonDelay = 5;
      pixelColor++;
      if (pixelColor > 7){
        pixelColor = 1; 
      }
    }    
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  digiPixel.setPixel(pixelX, pixelY, pixelColor);
}





