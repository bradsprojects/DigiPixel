// press button B to roll the dice.

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte DiceNumbersRed[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b01000000, 0b11111111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001100, 0b00010100, 0b01100100, 0b11111111, 0b00000100, 0b00000000, 0b00000000, 0b00000000, 0b11110010, 0b10010001, 0b10010001, 0b10010001, 0b10001110, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte DiceNumbersGreen[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000011, 0b10000101, 0b10001001, 0b10010001, 0b01100001, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001100, 0b00010100, 0b01100100, 0b11111111, 0b00000100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte DiceNumbersBlue[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000010, 0b10000001, 0b10001001, 0b10001001, 0b01110110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11110010, 0b10010001, 0b10010001, 0b10010001, 0b10001110, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};


// Variables
byte RollSpeedSave = 0;
byte RollSpeed = RollSpeedSave; 
byte TextOffset = 0;
boolean diceIsRolling = true;
byte numberToLandOn = 32;
byte randomNumberCounter = 1;


void setup(){
  
}

// We will run the following code over and over again in a constant loop for as long as power is applied.
void loop(){  
  updateGraphics();                  
  saveGraphics();                 
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();         
  checkForButtonPress();
  doRandomNumberCount();
  Serial.println(numberToLandOn);
}

void doRandomNumberCount()
{
  randomNumberCounter++;
  if (randomNumberCounter > 6)
  {
    randomNumberCounter = 1;
  }
}

void checkForButtonPress()
{
  if (digiPixel.buttonBPressed == true)
  {
    diceIsRolling = true;
    numberToLandOn = randomNumberCounter * 8;
    RollSpeedSave = 0;
  }  
}

void updateGraphics(){
  // First we'll update the player moving to the left or right of screen
  if (diceIsRolling == true)
  {
    if (RollSpeed != 0){
      RollSpeed--;
    }
    else{
       RollSpeed = RollSpeedSave;
       TextOffset++; 
       if (TextOffset == sizeof(DiceNumbersRed) - 8){
         TextOffset = 0;
         RollSpeedSave++; 
       }
    }
    if (RollSpeedSave == 2 & TextOffset == numberToLandOn)
    {
      diceIsRolling = false;
    }
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 7; index++){
   digiPixel.bufferRed[index] = pgm_read_dword(&DiceNumbersRed[(index) + TextOffset]);
   digiPixel.bufferGreen[index] = pgm_read_dword(&DiceNumbersGreen[(index) + TextOffset]);
   digiPixel.bufferBlue[index] = pgm_read_dword(&DiceNumbersBlue[(index) + TextOffset]);
   }
}




