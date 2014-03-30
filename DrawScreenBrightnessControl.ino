//--------------------------------------------------------
// Brightness control added to DigiPixel drawscreen code
// By Jan-Willem, Enschede, the Netherlands
// March 20, 2014


#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)
  




//JW: add this global variable to the DigiPixel library
byte bright;  //JW: controls the LED brightness of the screen, 0=off, 255=full (100%)

//JW: initialize bright with 255 (default), in the library (for example in the digiPixel pin assigment code
// bright = 255;  // 100% on





void setup() { 
     digiPixel.fillScreen(green);
} 



//JW: example program, update the global variable bright to control the screen
//JW: timing of the drawScreen code stays the same independed of the brightness
void loop(){  
byte i;
  for (i=0; i<255; i++) {bright=i; drawScreen();  }
  for (i=255; i>0; i--) {bright=i; drawScreen();  }
}







// ----------------------------------------------------------------------
// DrawSreen with brightness control
// parameter bright 0..255
//   0 = screen off
// 255 = 100% brighness
// the procedure timing is the same with reduced brightness so the software
// and the games will play on the same speed.
// By: Jan-Willem


void drawScreen() {
  byte index1;

  if (bright > 0) {                                             //JW: only show pixels if brightness >0
    for (index1=0; index1<=7; index1++){
      digitalWrite(digiPixel.latchShiftNotLoadPin, LOW);  
      digiPixel.shiftOut(digiPixel.columnData[index1]);
      digiPixel.shiftOut(~digiPixel.bufferBlue[index1]);    
      digiPixel.shiftOut(~digiPixel.bufferRed[index1]);     
      digiPixel.shiftOut(~digiPixel.bufferGreen[index1]);	
      digitalWrite(digiPixel.latchShiftNotLoadPin, HIGH);
      digitalWrite(digiPixel.outputEnablePin,LOW);

      delayMicroseconds(bright*4);                              //JW:  255*4 = 1020 uS is about the same as the original 1 mS delay

      digitalWrite(digiPixel.outputEnablePin,HIGH);
    }
  }
  if (bright < 255) delayMicroseconds(8*4*(255-bright));      //JW: add 8* missed loop delays to keep timing constant
}



