#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Variables
byte RedYCounter = 0;
byte GreenYCounter = 0;
byte BlueYCounter = 0;


void setup(){
}


void loop(){
  //  these first two for loops will scan the screen from bottom left to top right 
  for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 5; NumberOfTimesThrough++){	// the initial run through is five times (0 to 4)
    RedYCounter = 0;
    GreenYCounter = 0;
    for (int x = 0; x < (4 +  NumberOfTimesThrough); x++){
      bitWrite(digiPixel.bufferRed[3 + NumberOfTimesThrough - x], x, 1);
      digiPixel.drawScreen();            // This is always required if you want to display anything on the DigiPixel's LED display.
    }
  }  
  for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 4; NumberOfTimesThrough++){	// this run through is four times (0 to 3)
    RedYCounter = 0;
    GreenYCounter = 0;
    for (int x = 0; x < (7 - NumberOfTimesThrough); x++){
      bitWrite(digiPixel.bufferRed[7 - x], (x + 1 + NumberOfTimesThrough), 1);
      digiPixel.drawScreen();            // This is always required if you want to display anything on the DigiPixel's LED display.
    }
  }
  //  these next two for loops will scan the screen from top left to bottom right 
  for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 5; NumberOfTimesThrough++){	// this run through is five times (0 to 4)
    RedYCounter = 0;
    GreenYCounter = 0;
    for (int x = 0; x < (4 + NumberOfTimesThrough); x++){
      bitWrite(digiPixel.bufferGreen[x], (x + 4 - NumberOfTimesThrough), 1);
      digiPixel.drawScreen();            // This is always required if you want to display anything on the DigiPixel's LED display.
    }
  } 
  for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 4; NumberOfTimesThrough++){	// this run through is four times (0 to 3)
    RedYCounter = 0;
    GreenYCounter = 0;
    for (int x = 0; x < (7 - NumberOfTimesThrough); x++){
      bitWrite(digiPixel.bufferGreen[x + 1 + NumberOfTimesThrough], (x), 1);
      digiPixel.drawScreen();            // This is always required if you want to display anything on the DigiPixel's LED display.
    }
  }
  digiPixel.clearScreen();
}



