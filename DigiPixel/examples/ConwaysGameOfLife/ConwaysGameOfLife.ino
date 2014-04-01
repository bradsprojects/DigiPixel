/*

The following code was downloaded and then modified to suite the DigiPixel from https://gist.github.com/remcoder/6007361

here's a video: http://www.youtube.com/watch?v=Ee2hOaQ2RDI

To set a new game board, just press button A

*/

#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Variables
boolean cells[8][8];
int current[8][8] ={{0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}};
int next[8][8];
int mod(int a) { return (a+8)%8; }
byte UpdateDelay = 10;  // this can vary from 1 to 50
byte UpdateDelaySaved = 10;
byte ButtonDelay = 5;

void setup() {
  setRandomStuff();
}

void loop() {
  DoGameOfLife();
  CheckButtons();
  digiPixel.drawScreen();
  digiPixel.saveButtonStates();
}

void CheckButtons(){
  if (ButtonDelay != 0){
    ButtonDelay--;
  }
  else{
    if (digiPixel.buttonAPressed){
      ButtonDelay = 5;
      setRandomStuff();
    }
    if (digiPixel.buttonUpPressed){
      ButtonDelay = 5;
      if (UpdateDelaySaved > 1){
        UpdateDelaySaved--; 
      }
    }
    else if (digiPixel.buttonDownPressed){
      ButtonDelay = 5;
      if (UpdateDelaySaved < 20){
        UpdateDelaySaved++; 
      }
    }
  }
}

void setRandomStuff(){
  randomSeed(random(255)); 
  for (int r=0 ; r<8 ; r++) {
    for (int c=0 ; c<8 ; c++) {    
      if (random(2) >0)
        next[r][c] = 1;
        current[r][c] = random(2);
    }
 } 
}

void DoGameOfLife() {
  if (UpdateDelay != 0){
    UpdateDelay--;
  }
  else{
    UpdateDelay = UpdateDelaySaved;
    for (int r=0 ; r<8 ; r++) {
      for (int c=0 ; c<8 ; c++) {
        int color;
        if (next[r][c] == 0)
          color = 0;
        else if (next[r][c] == 1) 
          color = 1;
        else if (next[r][c] == 2)
          color = 2;
        else if (next[r][c] == 3)
          color = 3;
        else if (next[r][c] == 4)
          color = 4;
        else if (next[r][c] == 5)
          color = 5;
        else if (next[r][c] == 6)
          color = 6;
        else if (next[r][c] > 6)
          color = 7;
        //else
        //  color = 4;
        digiPixel.setPixel(c,r,color);
      }
    }
        
    // calc next state
    for (int r=0 ; r<8 ; r++) {
      for (int c=0 ; c<8 ; c++) {    
        // count alive neighbors
        int alive = 0;
        alive += current[mod(r+1)][mod(c)  ] != 0;
        alive += current[mod(r)  ][mod(c+1)] != 0;
        alive += current[mod(r-1)][mod(c)  ] != 0;
        alive += current[mod(r)  ][mod(c-1)] != 0;
        alive += current[mod(r+1)][mod(c+1)] != 0;
        alive += current[mod(r-1)][mod(c-1)] != 0;
        alive += current[mod(r+1)][mod(c-1)] != 0;
        alive += current[mod(r-1)][mod(c+1)] != 0;
        if (current[r][c])
          if (alive < 2 || alive > 3)
            next[r][c] = 0;
          else
            next[r][c] = current[r][c] + 1;
        else
          if (alive == 3)
            next[r][c] = 1;
      }
    }    
    
    for (int r=0 ; r<8 ; r++) {
      for (int c=0 ; c<8 ; c++) {    
        current[r][c] = next[r][c];
      }
    } 
  }
}




