// use the L R buttons to move a single pixel across the screen. Use the A button to change the pixel color
// avoid the missiles for as long as possible, you have 10 lives.
// game completed sequence to be added
// made for the digipixel http://www.bradsprojects.com/the-digipixel/
// Crazyau 2014
#include <DigiPixel.h>
#include <avr/pgmspace.h>


// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// Program memory arrays
byte numberTable[30]PROGMEM={0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};
byte pixelX = 0;
byte pixelY = 0;
byte pixelColor = 4;
byte buttonDelay = 5;
boolean enemyRight = true;
byte enemyX = 0;
byte enemySpeed = 20;
byte bombSpeed = 20;
byte bombX =0;
byte bombY = 8;
byte bombDelay =15;
boolean bombLive = false;
byte mSD = 0;
byte lSD = 0;
int roundTime =0;
byte roundNumber = 1;
void setup(){
  Serial.begin(9600);
}


void loop(){ 
  timers();
  movePixel();

  moveBomb();
  moveEnemy();
  livesCheck();
  saveGraphics();
  digiPixel.saveButtonStates();
  digiPixel.drawScreen();
  Serial.println(roundNumber);
  Serial.println(roundTime);  
}

void livesCheck(){
  if (mSD ==1){
    for (int j = 0; j < 20; ++j){
      digiPixel.invertColors();
      digiPixel.drawScreen(); 
    }
    mSD =0;
    lSD =0;
    roundNumber = 0;
  }
  if (roundNumber == 20){ // yah, you win
    roundNumber = 0; 
  }
}

void timers(){
  bombDelay = random(21-roundNumber);
  if (roundTime == 1000){ //time needed to last per round
    roundTime = 0;
    roundNumber ++; //increase speed and frequency of bomb

  } 
  else roundTime ++;
}
void moveBomb(){
  if (bombLive == false & bombDelay == enemyX){ //random bomb drop
    bombLive = true;
    bombX = enemyX;
  }
  else if(bombSpeed != 0){
    bombSpeed --; // if bomb is not at 0 move down one row
  }
  else{
    bombSpeed = 1; // bomb speed
    if (bombY ==0){ //bomb hit ground
      bombLive = false;
      bombY = 8;
    }
    else if (bombLive == true){ // moves bomb down one row
      bombY --; 
    }
    if (bombX == pixelX & bombY == 0){  //if ship is hit

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
      score();
      bombLive = false;

    }
  }
}

void movePixel(){
  if (buttonDelay != 0){
    buttonDelay--; 
  }
  else{

    if (digiPixel.buttonLeftPressed == true & pixelX > 0){
      buttonDelay = 5;
      pixelX--;
    }
    if (digiPixel.buttonRightPressed == true & pixelX < 7){
      buttonDelay = 5;
      pixelX++;
    } 
    if (digiPixel.buttonAPressed == true){
      buttonDelay = 5;
      pixelColor++;
      if (pixelColor > 7){
        pixelColor = 1; 
      }
    }    
  }
}
void moveEnemy(){
  if (enemySpeed != 0){
    enemySpeed --; 
  }
  else{
    enemySpeed = 21-roundNumber;
    if(enemyRight == false & enemyX > 0) {
      enemyX --;
      if(enemyX == 0){
        enemyRight = true;

      }
    }
    else if(enemyRight == true & enemyX < 7){
      enemyX ++;
      if(enemyX == 7){
        enemyRight = false; 
      }
    }
  }
}
void saveGraphics(){
  digiPixel.clearScreen();
  digiPixel.setPixel(pixelX, pixelY, pixelColor);
  digiPixel.setPixel(enemyX,7,red);
  digiPixel.setPixel(bombX,bombY,white);
}
void score(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 2; index++)
  {
    digiPixel.bufferRed[index] = pgm_read_dword(&numberTable[(index) + (mSD * 3)]);
  }
  for (byte index = 4; index <= 6; index++)
  {
    digiPixel.bufferRed[index] = pgm_read_dword(&numberTable[(index - 4) + (lSD * 3)]);
  }
  for (int j = 0; j < 25; ++j){
    digiPixel.drawScreen();
  }
}

