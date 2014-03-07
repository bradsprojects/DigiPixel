// please note this code is not perfect and I would not recommend using this as an actual clock since it will reset itself approximately every 23 days!
// This code is designed as a proof of concept as to something you might like to implement properly into the DigiPixel

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte numberTable[30]PROGMEM={0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};

// Variables
byte hoursMSD = 2;
byte hoursLSD = 3;
byte minutesMSD = 5;
byte minutesLSD = 9;
byte secondsMSD = 4;
byte secondsLSD = 0;
boolean buttonIsPressed = false;
long millisOld = 0;


void setup(){

}


void loop(){  
  saveGraphics();                   
  digiPixel.saveButtonStates(); 
  digiPixel.drawScreen();         
  updateTime();
}

void updateTime()
{
  if ((millisOld + 1000) < millis())
  {
    millisOld = millis(); 
    secondsLSD++;
      if (secondsLSD == 10)
      {
        secondsLSD = 0;
        secondsMSD++;
        if (secondsMSD == 6)
        {
          secondsMSD = 0;
          minutesLSD++;
          if (minutesLSD == 10)
          {
            minutesLSD = 0;
            minutesMSD++;
            if (minutesMSD == 6)
            {
              minutesMSD = 0;
              hoursLSD++;
              if (hoursMSD < 2)
              {
                if (hoursLSD == 10)
                {
                  hoursLSD = 0;
                  hoursMSD++;  
                }
              }
              if (hoursMSD == 2)
              {
                if (hoursLSD == 4)
               {
                 hoursLSD = 0;
                 hoursMSD = 0;
               } 
              }
            }  
          }
        }
      }  
    } 
}

void saveGraphics(){
  digiPixel.clearScreen();
  digiPixel.bufferRed[0] = hoursMSD;
  digiPixel.bufferRed[1] = hoursLSD;
  digiPixel.bufferGreen[3] = minutesMSD;
  digiPixel.bufferGreen[4] = minutesLSD;
  digiPixel.bufferBlue[6] = secondsMSD;
  digiPixel.bufferBlue[7] = secondsLSD;
}




