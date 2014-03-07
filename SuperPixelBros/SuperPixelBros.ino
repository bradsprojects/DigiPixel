#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte Level1Red[120]PROGMEM={0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b01000000, 0b00000000, 0b00000000, 0b00001000, 0b00000000, 0b00001000, 0b00101000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000000, 0b11000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b11100000, 0b01000000, 0b00000000, 0b00000100, 0b00000100, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000, 0b00010100, 0b00000000, 0b00000000, 0b01001000, 0b11001000, 0b11000000, 0b10000000, 0b00001000, 0b00000000, 0b00101000, 0b00000000, 0b00001000, 0b00000000, 0b00000000, 0b00100000, 0b00100000, 0b00000000, 0b00000000, 0b00101000, 0b00100000, 0b00000000, 0b00000000, 0b00000010, 0b00000110, 0b00001110, 0b00000000, 0b00001110, 0b00000110, 0b01000010, 0b11000000, 0b01000000, 0b00000010, 0b00000110, 0b00001110, 0b00001110, 0b00000000, 0b00001110, 0b00000110, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000110, 0b00001110, 0b00011110, 0b00011110, 0b00000000, 0b01000000, 0b11100000, 0b11100010, 0b01000000, 0b00000000, 0b00001110, 0b00111110, 0b00011000, 0b00111110, 0b00001110};
byte Level1Green[120]PROGMEM={0b00000001, 0b00000001, 0b01000001, 0b11000001, 0b01000001, 0b00000001, 0b00000001, 0b00001001, 0b00000001, 0b00001001, 0b00101001, 0b00001001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b10000111, 0b11000111, 0b01000001, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001001, 0b00000001, 0b00000001, 0b01000001, 0b11000001, 0b11100000, 0b01000000, 0b00000001, 0b00000101, 0b00000101, 0b00010001, 0b00010001, 0b00010001, 0b00010001, 0b00000001, 0b00000001, 0b00000000, 0b00000000, 0b00000000, 0b00010001, 0b00010101, 0b00000001, 0b00000001, 0b01001001, 0b11001001, 0b11000001, 0b10000001, 0b00001001, 0b00000001, 0b00101001, 0b00000001, 0b00001001, 0b00000001, 0b00000001, 0b00100001, 0b00100001, 0b00000001, 0b00000001, 0b00101001, 0b00100001, 0b00000001, 0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00000001, 0b00001111, 0b00000111, 0b01000011, 0b11000001, 0b01000001, 0b00000011, 0b00000111, 0b00001111, 0b00001111, 0b00000000, 0b00001111, 0b00000111, 0b00000011, 0b00000001, 0b00000111, 0b00000111, 0b00000001, 0b00000001, 0b00001001, 0b00001001, 0b00000001, 0b00000001, 0b00000001, 0b00000111, 0b00000111, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00011111, 0b00000001, 0b01000001, 0b11100001, 0b11100011, 0b01000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001};
byte Level1Blue[120]PROGMEM={0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000000, 0b11000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b11100000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b11000000, 0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b11000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b11100000, 0b11100000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte Level1Barriers[120]PROGMEM={0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00001001, 0b00000001, 0b00001001, 0b00101001, 0b00001001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000111, 0b00000111, 0b00000001, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b00000001, 0b00000001, 0b00001001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000000, 0b00000000, 0b00000001, 0b00000101, 0b00000101, 0b00010001, 0b00010001, 0b00010001, 0b00010001, 0b00000001, 0b00000001, 0b00000000, 0b00000000, 0b00000000, 0b00010001, 0b00010101, 0b00000001, 0b00000001, 0b00001001, 0b00001001, 0b00000001, 0b00000001, 0b00001001, 0b00000001, 0b00101001, 0b00000001, 0b00001001, 0b00000001, 0b00000001, 0b00100001, 0b00100001, 0b00000001, 0b00000001, 0b00101001, 0b00100001, 0b00000001, 0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00000001, 0b00001111, 0b00000111, 0b00000011, 0b00000001, 0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00001111, 0b00000000, 0b00001111, 0b00000111, 0b00000011, 0b00000001, 0b00000111, 0b00000111, 0b00000001, 0b00000001, 0b00001001, 0b00001001, 0b00000001, 0b00000001, 0b00000001, 0b00000111, 0b00000111, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00011111, 0b00000001, 0b00000001, 0b00000001, 0b00000011, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001};


// Constants
#define ScrollSpeedSave 7
#define MaxJumpHeight 3

// Variables
byte PlayerX = 3;                         
byte PlayerY = 7;                         
byte PlayerColor = red;                   
byte ScrollSpeed = ScrollSpeedSave;
byte BackgroundOffset = 0;                   
byte JumpSpeed = 4;
byte JumpHeight = 0;
byte HoverDelay = 0;
boolean IsJumping = false;
boolean IsHovering = false;
boolean IsFalling = true;


void setup(){
  
}


void loop(){  
  updateGraphics();              
  saveGraphics();                 
  checkIfLostLife();
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();       
}

void checkIfLostLife(){
  if (PlayerY == 0){
    BackgroundOffset = 0;
    PlayerY = 7;
  } 
}

void updateGraphics(){
  // First we'll update the player moving to the left or right of screen
  if (ScrollSpeed != 0){
    ScrollSpeed--;
  }
  else{
    if (digiPixel.buttonLeftPressed & BackgroundOffset > 0 & digiPixel.checkBarrier((PlayerX - 1), PlayerY) == false){
      ScrollSpeed = ScrollSpeedSave;
      BackgroundOffset--;    
    }
    if (digiPixel.buttonRightPressed & BackgroundOffset < (sizeof(Level1Barriers) - 8) & digiPixel.checkBarrier((PlayerX + 1), PlayerY) == false){
      ScrollSpeed = ScrollSpeedSave;
      BackgroundOffset++;    
    }
  }
  
 // Then we'll see if the player is jumping, hovering or falling. This first bit is to see if we have pressed the jump button   
  if (digiPixel.buttonAPressed & digiPixel.checkBarrier(PlayerX, (PlayerY + 1)) == false & IsFalling == false & IsJumping == false & IsHovering == false){
    IsJumping = true; 
    JumpHeight = 0;     
  }
// If we have pressed the jump button, then run this code which will make the player move up  
  if (IsJumping == true){
    if (JumpSpeed != 0){
     JumpSpeed--;
    }
    else{
      JumpSpeed = 4;
      JumpHeight++;
      PlayerY++;
      if (JumpHeight == MaxJumpHeight || digiPixel.checkBarrier(PlayerX, (PlayerY + 1)) == true){
        IsJumping = false;
        IsHovering = true;
        HoverDelay = 3;
      } 
    }
  }
 // If the player reaches the peak of his jump OR we hit a block above us, then we hover for just a moment... 
  if (IsHovering == true){
    if (JumpSpeed != 0){
     JumpSpeed--;
    }
    else{
      JumpSpeed = 4;
      HoverDelay--;
      if (HoverDelay == 0){
        IsHovering = false;
        IsFalling = true; 
      }
    } 
  }
// Now the last part is if we are falling. We could be falling because we pressed jump OR we could have stepped off a block. Let's first see if we have a floor beneath us...
  if (digiPixel.checkBarrier(PlayerX, (PlayerY - 1)) == true){
     IsFalling = false;  // there is a floor - so let's not fall then!
  }
  else{
    if (IsJumping == false & IsHovering == false){  // if there ISNT a floor, then we had better check that we arent in the middle of a jump
      IsFalling = true;  // if we're not jumping, then we can start falling (because there's no floor)
    }
    if (IsFalling == true){  // if we are falling then lets run some code that will cause the player to drop down a pixel 
      if (JumpSpeed != 0){
        JumpSpeed--;
      }
      else{
        JumpSpeed = 4;
        PlayerY--;
      }
    }
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 7; index++){
   digiPixel.bufferRed[index] = pgm_read_dword(&Level1Red[(index) + BackgroundOffset]);
   digiPixel.bufferGreen[index] = pgm_read_dword(&Level1Green[(index) + BackgroundOffset]);
   digiPixel.bufferBlue[index] = pgm_read_dword(&Level1Blue[(index) + BackgroundOffset]);
   digiPixel.bufferBarriers[index] = pgm_read_dword(&Level1Barriers[(index) + BackgroundOffset]);
  }
  digiPixel.setPixel(PlayerX, PlayerY, PlayerColor);
}




