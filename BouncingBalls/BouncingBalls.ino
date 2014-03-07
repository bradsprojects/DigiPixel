#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)
  
  
// Variable Arrays
byte BallX[7]={6, 4, 2, 6, 1, 3, 2};
byte BallY[7]={1, 2, 6, 3, 2, 2, 6};
byte BallColor[7]={1, 2, 3, 4, 5, 6, 7};
boolean BallRight[7]={true, true, true, true, true, true, true};
boolean BallUp[7]={true, true, true, true, true, true, true};
byte BallSpeedX[7]={3, 5, 6, 7, 8, 9, 10};
byte BallSpeedXSave[7]={3, 5, 6, 7, 8, 9, 10};
byte BallSpeedY[7]={4, 7, 3, 5, 6, 4, 8};
byte BallSpeedYSave[7]={4, 7, 3, 5, 6, 4, 8};


void setup(){
}


void loop(){  
  updateGraphics();                 
  saveGraphics();                   
  digiPixel.drawScreen();     
}

void updateGraphics(){
  for (int index = 0; index <= 6; index++){
    if (BallSpeedX[index] != 0){
      BallSpeedX[index]--;
    }
    else{
      BallSpeedX[index] = BallSpeedXSave[index];
      if (BallRight[index] == true){
        BallX[index]++;
        if (BallX[index] == 7){
          BallRight[index] = false;
        }
      }
      else{
        BallX[index]--;
        if (BallX[index] == 0){
          BallRight[index] = true;
        }
      }
    }
    
    if (BallSpeedY[index] != 0){
      BallSpeedY[index]--;
    }
    else{
      BallSpeedY[index] = BallSpeedYSave[index];
      if (BallUp[index] == true){
        BallY[index]++;
        if (BallY[index] == 7){
          BallUp[index] = false;
        }
      }
      else{
        BallY[index]--;
        if (BallY[index] == 0){
          BallUp[index] = true;
        }
      }
    }
  }
}

void saveGraphics(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 6; index++){
      digiPixel.setPixel(BallX[index], BallY[index], BallColor[index]);
  }
}




