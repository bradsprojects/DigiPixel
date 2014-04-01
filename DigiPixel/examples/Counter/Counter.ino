// Press button B to increment the counter

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte numberTable[30]PROGMEM={0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};


// Variables
byte mSD = 0;
byte lSD = 0;
boolean buttonIsPressed = false;


void setup(){
}


void loop(){  
  saveGraphics();                   
  digiPixel.saveButtonStates();    
  digiPixel.drawScreen();          
  checkForButtonPress();
}

void checkForButtonPress()
{
  if (digiPixel.buttonBPressed == true & buttonIsPressed == false)
  {
    buttonIsPressed = true;
    lSD++;
    if (lSD == 10)
    {
      lSD = 0;
      mSD++;
      if (mSD == 10)
      {
        mSD = 0;
      }
    }
  }
  else if (digiPixel.buttonBPressed == false)
  {
    buttonIsPressed = false;
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 2; index++)
  {
   digiPixel.bufferGreen[index] = pgm_read_dword(&numberTable[(index) + (mSD * 3)]);
  }
  for (byte index = 4; index <= 6; index++)
  {
   digiPixel.bufferGreen[index] = pgm_read_dword(&numberTable[(index - 4) + (lSD * 3)]);
  }
}




