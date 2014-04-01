#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte colorDiagBarsRed[22]PROGMEM={0b10011011, 0b00110110, 0b01101100, 0b11011001, 0b10110011, 0b01100110, 0b11001101, 0b10011011, 0b00110110, 0b01101100, 0b11011001, 0b10110011, 0b01100110, 0b11001101, 0b10011011, 0b00110110, 0b01101100, 0b11011001, 0b10110011, 0b01100110, 0b11001101, 0b10011011};
byte colorDiagBarsGreen[22]PROGMEM={0b01010110, 0b10101101, 0b01011010, 0b10110101, 0b01101010, 0b11010101, 0b10101011, 0b01010110, 0b10101101, 0b01011010, 0b10110101, 0b01101010, 0b11010101, 0b10101011, 0b01010110, 0b10101101, 0b01011010, 0b10110101, 0b01101010, 0b11010101, 0b10101011, 0b01010110};
byte colorDiagBarsBlue[22]PROGMEM={0b00101110, 0b01011100, 0b10111001, 0b01110010, 0b11100101, 0b11001011, 0b10010111, 0b00101110, 0b01011100, 0b10111001, 0b01110010, 0b11100101, 0b11001011, 0b10010111, 0b00101110, 0b01011100, 0b10111001, 0b01110010, 0b11100101, 0b11001011, 0b10010111, 0b00101110};


// Constants
#define ScrollSpeedSave 6

// Variables
byte ScrollSpeed = ScrollSpeedSave; 
byte Offset = 0;


void setup(){
  
}


void loop(){  
  updateGraphics();                  
  saveGraphics();                   
  digiPixel.saveButtonStates();    
  digiPixel.drawScreen();          
}

void updateGraphics(){
  if (ScrollSpeed != 0){
    ScrollSpeed--;
  }
  else{
      ScrollSpeed = ScrollSpeedSave;
      Offset++; 
     if (Offset == sizeof(colorDiagBarsRed) - 8){
      Offset = 0;
     } 
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 7; index++){
   digiPixel.bufferRed[index] = pgm_read_dword(&colorDiagBarsRed[(index) + Offset]);
   digiPixel.bufferGreen[index] = pgm_read_dword(&colorDiagBarsGreen[(index) + Offset]);
   digiPixel.bufferBlue[index] = pgm_read_dword(&colorDiagBarsBlue[(index) + Offset]);
  }
}




