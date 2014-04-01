

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Variables
int lightCounter = 0;


void setup(){
  
}


void loop(){  
  saveGraphics();                   
  digiPixel.drawScreen();           
  updateLightCounter();
}

void updateLightCounter()
{
  lightCounter++;
  if (lightCounter > 700)
  {
    lightCounter = 0;
  }
}

void saveGraphics()
{
  digiPixel.clearScreen();
  if (lightCounter < 300)
  {
    digiPixel.drawBox(2, 0, 5, 1, green);
  }
  if (lightCounter > 299 & lightCounter < 400)
  {
    digiPixel.drawBox(2, 3, 5, 4, yellow);
  }
  if (lightCounter > 399)
  {
    digiPixel.drawBox(2, 6, 5, 7, red);
  }
}




