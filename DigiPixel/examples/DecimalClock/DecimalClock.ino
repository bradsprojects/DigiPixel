// please note this code is not perfect and I would not recommend using this as an actual clock since it will reset itself approximately every 23 days!
// This code is designed as a proof of concept as to something you might like to implement properly into the DigiPixel

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte const numberTable[30]PROGMEM={0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};


// Variables
byte timeGraphics[29];
byte hoursMSD = 2;
byte hoursLSD = 1;
byte minutesMSD = 4;
byte minutesLSD = 9;
byte secondsMSD = 2;
byte secondsLSD = 0;
long millisOld = 0;
byte screenXOffset = 0;
byte screenScrollDelay = 5;
boolean screenIsScrollingRight = true;


void setup(){
}


void loop(){  
  saveGraphics();                    
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();        
  updateTime();
  saveTimeGraphics();
  scrollScreen();
}

void scrollScreen()
{
  if (screenScrollDelay != 0)
  {
    screenScrollDelay--;
  }
  else
  {
    screenScrollDelay = 7;
    if (screenIsScrollingRight == true)
    {
      screenXOffset++;
      if (screenXOffset == (sizeof(timeGraphics) - 8))
      {
        screenIsScrollingRight = false;   
      }
    }
    else
    {
      screenXOffset--;
      if (screenXOffset == 0)
      {
        screenIsScrollingRight = true;   
      }
    }
  } 
}

void saveTimeGraphics()
{
  timeGraphics[0] = 0;
  timeGraphics[1] = pgm_read_dword(&numberTable[hoursMSD * 3]);
  timeGraphics[2] = pgm_read_dword(&numberTable[hoursMSD * 3 + 1]);
  timeGraphics[3] = pgm_read_dword(&numberTable[hoursMSD * 3 + 2]);
  timeGraphics[4] = 0;
  timeGraphics[5] = pgm_read_dword(&numberTable[hoursLSD * 3]);
  timeGraphics[6] = pgm_read_dword(&numberTable[hoursLSD * 3 + 1]);
  timeGraphics[7] = pgm_read_dword(&numberTable[hoursLSD* 3 + 2]);
  timeGraphics[8] = 0;
  timeGraphics[9] = 0b00100100;
  timeGraphics[10] = 0;
  timeGraphics[11] = pgm_read_dword(&numberTable[minutesMSD * 3]);
  timeGraphics[12] = pgm_read_dword(&numberTable[minutesMSD * 3 + 1]);
  timeGraphics[13] = pgm_read_dword(&numberTable[minutesMSD* 3 + 2]);
  timeGraphics[14] = 0;
  timeGraphics[15] = pgm_read_dword(&numberTable[minutesLSD * 3]);
  timeGraphics[16] = pgm_read_dword(&numberTable[minutesLSD * 3 + 1]);
  timeGraphics[17] = pgm_read_dword(&numberTable[minutesLSD* 3 + 2]);
  timeGraphics[18] = 0;
  timeGraphics[19] = 0b00100100;
  timeGraphics[20] = 0;
  timeGraphics[21] = pgm_read_dword(&numberTable[secondsMSD * 3]);
  timeGraphics[22] = pgm_read_dword(&numberTable[secondsMSD * 3 + 1]);
  timeGraphics[23] = pgm_read_dword(&numberTable[secondsMSD* 3 + 2]);
  timeGraphics[24] = 0;
  timeGraphics[25] = pgm_read_dword(&numberTable[secondsLSD * 3]);
  timeGraphics[26] = pgm_read_dword(&numberTable[secondsLSD * 3 + 1]);
  timeGraphics[27] = pgm_read_dword(&numberTable[secondsLSD* 3 + 2]);
  timeGraphics[28] = 0;
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
  for (int index = 0; index <= 7; index++)
  {
    digiPixel.bufferGreen[index] = timeGraphics[index + screenXOffset];
  }
}




