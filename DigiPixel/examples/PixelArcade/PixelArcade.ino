
/*
 * PixelArcade - Provide a menu of games to play
 *
 * This is an example of how to import multiple games into a single image, 
 * and provides a way to choose which game to play next.
 * 
 * Play:
 *   Press Left/Right to choose a game
 *   A to start the game of choice
 *   Left and A at any point will bring you back to the "menu"
 *
 * Merging separate C programs in this manner is not ideal, but it works for the simple case.
 * merge-games script takes care of the #merge tag below and also renames conflicting globals (ick, I know)
 * 
 * Todo:
 * Add an alpha table to provide scrolling names
 * Provide still shots of games?
 */

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


/* #merge is handled by the merge-games perl script, the games are added in order listed below to the games[] array */

// --- Merged in ../TheGreatRace/TheGreatRace.ino ----------------------------



// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte TitleRed[67]PROGMEM={B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00111110, B00100010, B00100110, B00000000, B00111110, B00101000, B00110110, B00000000, B00111110, B00101010, B00100010, B00000000, B00111110, B00101000, B00111110, B00000000, B00100000, B00111110, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte TitleGreen[67]PROGMEM={B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00100000, B00111110, B00100000, B00000000, B00111110, B00001000, B00111110, B00000000, B00111110, B00101010, B00100010, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte TitleBlue[67]PROGMEM={B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00111110, B00101000, B00110110, B00000000, B00111110, B00101000, B00111110, B00000000, B00111110, B00100010, B00100010, B00000000, B00111110, B00101010, B00100010, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
 
byte Track2Red[128]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000, 0b00010000, 0b00010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte Track2Green[128]PROGMEM={0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000001, 0b11000001, 0b11000001, 0b11000001, 0b11000001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11110001, 0b11110001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11000011, 0b11000011, 0b11000011, 0b11010011, 0b10010011, 0b10010011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000001, 0b11000001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11000001, 0b11000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000111, 0b10000111, 0b10000111, 0b10000111, 0b10000111, 0b11000111, 0b11000111, 0b11000111, 0b11000011, 0b11000011, 0b11000011, 0b11100011, 0b11100001, 0b11100001, 0b11101001, 0b11101001, 0b11001001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001};
byte Track2Blue[128]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte Track2Barriers[128]PROGMEM={0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000001, 0b11000001, 0b11000001, 0b11000001, 0b11000001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11110001, 0b11110001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11100011, 0b11000011, 0b11000011, 0b11000011, 0b11010011, 0b10010011, 0b10010011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10000011, 0b10010011, 0b10010011, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b10001001, 0b10001001, 0b10000001, 0b11000001, 0b11000001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100101, 0b11100101, 0b11100101, 0b11100101, 0b11100101, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11100001, 0b11101001, 0b11101001, 0b11101001, 0b11001001, 0b11000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10001001, 0b10001001, 0b10001001, 0b10001001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10100001, 0b10100001, 0b10100011, 0b10100011, 0b10000011, 0b10000011, 0b10000111, 0b10000111, 0b10000111, 0b10000111, 0b10000111, 0b11000111, 0b11000111, 0b11000111, 0b11000011, 0b11000011, 0b11000011, 0b11100011, 0b11100001, 0b11100001, 0b11101001, 0b11101001, 0b11001001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001};


// Constants
#define SteeringSpeedSave 8 // only jumps 1 LED instead of 2 (easier to steer)
#define ForwardSpeedSave 7
#define TitleScreen 0
#define PlayingGame 1
#define ScrollingSpeedSave 5

// Variables
byte CarX = 4;                          
byte CarY = 0;                          
byte CarColor = red;                     
byte SteeringSpeed = SteeringSpeedSave; 
byte ForwardSpeed = ForwardSpeedSave;  
int TrackOffset = 0;                  
byte GameMode = TitleScreen;
byte TitleOffset = 0;
byte ScrollingSpeed = ScrollingSpeedSave;


void setupTheGreatRace(){
  
  Serial.begin(9600);
}


void loopTheGreatRace(){ 
  checkModeChange();  
  updateGraphicsTheGreatRace();                  
  checkForCollision();               
  saveGraphicsTheGreatRace();               
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();         
}

void checkModeChange(){
  if (GameMode == TitleScreen & digiPixel.buttonAPressed){
   GameMode = PlayingGame;
   TrackOffset = 0;
   CarX = 4;
   CarY = 0;
  } 
}

void checkForCollision(){
   if (digiPixel.checkBarrier(CarX, CarY) == true){  
     GameMode = TitleScreen;
     TitleOffset = 0;
  }
}

void updateGraphicsTheGreatRace(){
  if (GameMode == TitleScreen){  
    if (ScrollingSpeed != 0){
     ScrollingSpeed--; 
    }
    else{
     ScrollingSpeed = ScrollingSpeedSave;
     TitleOffset++;
     if (TitleOffset == (sizeof(TitleGreen) - 8)){
      TitleOffset = 0;
     } 
    }
  }
  else if (GameMode == PlayingGame){
    if (SteeringSpeed != 0){
      SteeringSpeed--;
    }
    else{
      if (digiPixel.buttonUpPressed & CarY < 7){
        SteeringSpeed = SteeringSpeedSave;
        CarY++;    
      }
      if (digiPixel.buttonDownPressed & CarY > 0){
        SteeringSpeed = SteeringSpeedSave;
        CarY--;    
      }
      if (digiPixel.buttonLeftPressed & CarX > 0){
        SteeringSpeed = SteeringSpeedSave;
        CarX--;    
      }
      if (digiPixel.buttonRightPressed & CarX < 7){
        SteeringSpeed = SteeringSpeedSave;
        CarX++;    
      }
    }
    
    if (ForwardSpeed != 0){
     ForwardSpeed--; 
    }
    else{
     ForwardSpeed = ForwardSpeedSave;
     TrackOffset++;
     if (TrackOffset == (sizeof(Track2Barriers) - 8)){
      TrackOffset = 0;
     } 
    }
  }
}

void saveGraphicsTheGreatRace(){
  digiPixel.clearScreen();
  if (GameMode == TitleScreen){
    for (byte index = 0; index <= 7; index++){
     digiPixel.bufferRed[index] = pgm_read_dword(&TitleRed[(index) + TitleOffset]);
     digiPixel.bufferGreen[index] = pgm_read_dword(&TitleGreen[(index) + TitleOffset]);
     digiPixel.bufferBlue[index] = pgm_read_dword(&TitleBlue[(index) + TitleOffset]);
    }
  }
  else if (GameMode == PlayingGame){
    for (byte index = 0; index <= 7; index++){
     digiPixel.bufferRed[index] = pgm_read_dword(&Track2Red[(index) + TrackOffset]);
     digiPixel.bufferGreen[index] = pgm_read_dword(&Track2Green[(index) + TrackOffset]);
     digiPixel.bufferBlue[index] = pgm_read_dword(&Track2Blue[(index) + TrackOffset]);
     digiPixel.bufferBarriers[index] = pgm_read_dword(&Track2Barriers[(index) + TrackOffset]);
    }
  digiPixel.rotateScreen(90);
  bitWrite(digiPixel.bufferRed[CarX],CarY,1);
  bitWrite(digiPixel.bufferGreen[CarX],CarY,0);
  bitWrite(digiPixel.bufferBlue[CarX],CarY,0);
  }
}




// --- END of Merge ../TheGreatRace/TheGreatRace.ino ----------------------------
// --- Merged in ../SnakePixel/SnakePixel.ino ----------------------------
//use left and right button to direct the snake to eat the red apple




#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5, 2, 6, 4, 3); // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// Program memory arrays
byte numberTable[30]PROGMEM = {0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};


byte snakeX = 6;
byte snakeY = 3;
byte snakeColor = 2;
byte snakeLength = 1;
byte snakeDirection = LEFT;
byte snakeHistoryX[64];
byte snakeHistoryY[64];
byte snakeDelay = 30;
bool snakeMoved = false;

byte appleX;
byte appleY;
byte appleColor = 1;
bool gameRunning = true;

bool wasPressedSnakePixel = false;
bool goLeftSnakePixel = false;

void setupSnakePixel()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
   
  clearHistory();
  
  appleX = random(0, 7);
  appleY = random(0, 7);
  
  
}

void loopSnakePixel()
{

  checkButtonsSnakePixel();
  moveSnake();
  bool gameOverSnakePixel = checkSnakeDeath();
  if (gameOverSnakePixel)
  {
    Serial.println("Dead");
    showDeath();


  } else
  {
    saveGraphicsSnakePixel();
  }
  checkEatApple();
  digiPixel.saveButtonStates();
  digiPixel.drawScreen();
}
void checkButtonsSnakePixel()
{

  if ( !snakeMoved )
  {
    //can't change direction untill the snake moves
    return;
  }
  if (digiPixel.buttonLeftPressed == true)
  {
    wasPressedSnakePixel = true;
    goLeftSnakePixel = true;

  } else if (digiPixel.buttonRightPressed == true)
  {
    wasPressedSnakePixel = true;
    goLeftSnakePixel = false;

  } else if (wasPressedSnakePixel)
  {
    changeDirection();
    wasPressedSnakePixel = false;

  }

}

void changeDirection()
{
  if (snakeDirection == RIGHT)
  {
    if (goLeftSnakePixel)
    {
      snakeMoved = false;
      snakeDirection = UP;
      return;
    } else
    {
      snakeMoved = false;
      snakeDirection = DOWN;
      return;
    }
  } else if (snakeDirection == LEFT)
  {
    if (goLeftSnakePixel)
    {
      snakeMoved = false;
      snakeDirection = DOWN;
      return;
    } else
    {
      snakeMoved = false;
      snakeDirection = UP;
      return;
    }

  } else if (snakeDirection == UP)
  {
    if (goLeftSnakePixel)
    {
      snakeMoved = false;
      snakeDirection = LEFT;
      return;
    } else
    {
      snakeMoved = false;
      snakeDirection = RIGHT;
      return;
    }
  } else if (snakeDirection == DOWN)
  {
    if (goLeftSnakePixel)
    {
      snakeMoved = false;
      snakeDirection = RIGHT;
      return;
    } else
    {
      snakeMoved = false;
      snakeDirection = LEFT;
      return;
    }
  }



}

void clearHistory()
{

  for (byte i = 0; i < 64; ++i)
  {
    snakeHistoryX[i] = 254;
    snakeHistoryY[i] = 254;

  }

}

void moveSnake()
{

  if (--snakeDelay != 0)return;

  snakeDelay = 50;
  snakeMoved = true;

  if (snakeDirection == RIGHT)
  {
    snakeX++;
  } else if (snakeDirection == LEFT)
  {
    snakeX--;
  } else if (snakeDirection == UP)
  {
    snakeY++;
  } else if (snakeDirection == DOWN)
  {
    snakeY--;
  }

  shiftHistory();

}
void shiftHistory()
{

  byte i;

  for (i = snakeLength - 1; i > 0; --i)
  {
    byte tempX = snakeHistoryX[i - 1];
    byte tempY = snakeHistoryY[i - 1];
    snakeHistoryX[i] = tempX;
    snakeHistoryY[i] = tempY;
  }

  snakeHistoryX[0] = snakeX;
  snakeHistoryY[0] = snakeY;
}
bool checkSnakeDeath()
{
  bool snakeAlive = true;
  if (snakeX < 0 || snakeX > 7 || snakeY < 0 || snakeY > 7)
  {
    snakeAlive = false;
  }

  for (byte i = 1; i < snakeLength; ++i)
  {
    if (snakeHistoryX[i] == snakeX && snakeHistoryY[i] == snakeY)
    {
      snakeAlive = false;
      break;
    }
  }

  return !snakeAlive;
}

void checkEatApple()
{
  if (snakeX == appleX & snakeY == appleY)
  {
    snakeLength++;
    bool looking = true;
    //need to find an open spot
    while (looking)
    {
      appleX = random(0, 7);
      appleY = random(0, 7);
      bool goodSpot = true;
      if (snakeX == appleX && snakeY == appleY)
      {
        goodSpot = false;
      }

      for (byte i = 0; i < snakeLength; ++i)
      {
        if (snakeHistoryX[i] == appleX && snakeHistoryY[i] == appleY)
        {
          goodSpot = false;
          break;
        }
      }
      looking = !goodSpot;
    }


  }


}

void saveGraphicsSnakePixel()
{
  /*

  */

  digiPixel.clearScreen();

  digiPixel.setPixel(appleX, appleY, appleColor);

  for (byte i = 0; i < snakeLength; ++i)
  {
    digiPixel.setPixel(snakeHistoryX[i], snakeHistoryY[i], snakeColor);
  }

}

void showDeath()
{
  snakeColor = 1;

  for (int i = 0; i < 3; i++)
  {
    saveGraphicsSnakePixel();
    
    for (int j = 0; j < 100; ++j)
    {
      digiPixel.drawScreen();
    }




    digiPixel.clearScreen();
    digiPixel.drawScreen();

    int scoreTens = snakeLength / 10;
    int scoreOnes = snakeLength - (scoreTens * 10);

    for (int index = 0; index < 3; index++)
    {
      digiPixel.bufferBlue[index] = pgm_read_dword(&numberTable[index + (3 * scoreTens)]);
      digiPixel.bufferBlue[index + 4] = pgm_read_dword(&numberTable[index + (3 * scoreOnes)]);
    }
    
   for (int j = 0; j < 100; ++j)
    {
      digiPixel.drawScreen();
    }
    
    delay(500);
  }

  //reset
  snakeX = 6;
  snakeY = 3;
  snakeColor = 2;
  snakeLength = 1;
  snakeDirection = LEFT;
  snakeDelay = 30;
  snakeMoved = false;

  appleX = random(0, 7);
  appleY = random(0, 7);
  gameRunning = true;

  clearHistory();

}
// --- END of Merge ../SnakePixel/SnakePixel.ino ----------------------------
// --- Merged in ../SuperPixelBros/SuperPixelBros.ino ----------------------------




// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


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
byte PlayerColorSuperPixelBros = red;                   
byte ScrollSpeed = ScrollSpeedSave;
byte BackgroundOffset = 0;                   
byte JumpSpeed = 4;
byte JumpHeight = 0;
byte HoverDelay = 0;
boolean IsJumping = false;
boolean IsHovering = false;
boolean IsFalling = true;


void setupSuperPixelBros(){
  
}


void loopSuperPixelBros(){  
  updateGraphicsSuperPixelBros();              
  saveGraphicsSuperPixelBros();                 
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

void updateGraphicsSuperPixelBros(){
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

void saveGraphicsSuperPixelBros(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 7; index++){
   digiPixel.bufferRed[index] = pgm_read_dword(&Level1Red[(index) + BackgroundOffset]);
   digiPixel.bufferGreen[index] = pgm_read_dword(&Level1Green[(index) + BackgroundOffset]);
   digiPixel.bufferBlue[index] = pgm_read_dword(&Level1Blue[(index) + BackgroundOffset]);
   digiPixel.bufferBarriers[index] = pgm_read_dword(&Level1Barriers[(index) + BackgroundOffset]);
  }
  digiPixel.setPixel(PlayerX, PlayerY, PlayerColorSuperPixelBros);
}




// --- END of Merge ../SuperPixelBros/SuperPixelBros.ino ----------------------------
// --- Merged in ../BreakoutPixel/BreakoutPixel.ino ----------------------------
//Use left and right to move bar. Press B to restart after gameOverBreakoutPixel. 
//Red sad face when lose and Green Happy face when WIN :)
//TODO: Add bonus to make bar bigger and smaller...
//TODO: More Levels

// made for the digipixel http://www.bradsprojects.com/the-digipixel/
// Made by github.com/kostassite 2014


#define TARGETCOLOR 4 
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

int barX=0;
int barWidth = 3;
int moveDelay = 10;
bool barMoved = false;
bool wasPressedBreakoutPixel = false;
bool goLeftBreakoutPixel = false;

int ballDelay = 20;
bool ballGoesUp = true;
bool ballGoesRight = true;
int ballX=3;
int ballY=1;
bool ballHitted;

int targets[3][8];

bool gameOverBreakoutPixel = false;
bool gameWin = false;

void setupBreakoutPixel(){
	restartGame();
}

void restartGame(){
	ballGoesUp = true;
	ballGoesRight = true;
	ballX=3;
	ballY=1;
	barX = 2;
	
 	for (int i=0 ; i<3;i++){
		for (int j=0 ; j<8 ; j++){
			targets[i][j]=TARGETCOLOR;
		}
	}	
	gameOverBreakoutPixel = false;
	gameWin = false;
}

void updateGameBreakoutPixel(){

	moveBar();
	moveBall();
	checkTopCollision();
	checkBarCollision();
	checkWallCollisions();
	checkGameOver();
	checkWin();
	
	checkRestart();
}

void checkRestart(){
	if (gameOverBreakoutPixel==true && digiPixel.buttonBPressed==true){
		restartGame();
	}
}

void checkTopCollision(){
	if (ballHitted) return;

	if (ballGoesUp){
		for (int i=5 ; i<=7 ; i++){
			if (ballY==i-1){
				if (targets[7-i][ballX]==TARGETCOLOR){
					targets[7-i][ballX]=0;
					ballGoesUp = false;
					ballHitted = true;
				}else{
					if (ballGoesRight){
						if (targets[7-i][ballX+1]==TARGETCOLOR){
							targets[7-i][ballX+1]=0;
							ballGoesUp = false;
							ballGoesRight = false;
							ballHitted = true;
						}
					}else{
						if (targets[7-i][ballX-1]==TARGETCOLOR){
							targets[7-i][ballX-1]=0;
							ballGoesUp = false;
							ballGoesRight = true;
							ballHitted = true;
						}
					}
				}
			}
		}
	}else{
		for (int i = 7 ; i>=6 ; i--){
			if (ballY==i){
				if (ballGoesRight){
					if (targets[7-i+1][ballX+1]==TARGETCOLOR){
						targets[7-i+1][ballX+1] = 0;
						ballGoesUp = true;
						ballGoesRight = false;
						ballHitted = true;
					}
				}else{
					if (targets[7-i+1][ballX-1]==TARGETCOLOR){
						targets[7-i+1][ballX-1] = 0;
						ballGoesUp = true;
						ballGoesRight = true;
						ballHitted = true;
					}
				}
			}
		}
	}
	
	if (ballY==7){
		ballGoesUp = false;
	}
}

void checkWallCollisions(){
	if (ballX==0){
		ballGoesRight=true;
	}else if(ballX==7){
		ballGoesRight=false;
	}
}

void checkBarCollision(){
	if (ballY==1){
		if (ballX==barX-1){
			ballGoesUp=true;
			ballGoesRight=false;
		}else if(ballX==barX+barWidth){
			ballGoesUp=true;
			ballGoesRight = true;
		}else if (ballX>=barX && ballX<=barX+barWidth-1) {
			ballGoesUp=true;
		}
	}
}

void checkGameOver(){
	if (ballY==0){
		gameOverBreakoutPixel = true;
		gameWin = false;
	}
}

void checkWin(){
	for (int x=0 ; x<8;x++){
		for (int y=0 ; y<3 ; y++){
			if (targets[y][x]!=0){
				return;
			}
		}
	}
	gameOverBreakoutPixel = true;
	gameWin = true;
}

void moveBall(){
	if (--ballDelay != 0)return;
  	ballDelay = 30;
	
	if (ballGoesUp){
		ballY ++;
	}else{
		ballY --;
	}
	
	if (ballGoesRight){
		ballX++;
	}else{
		ballX--;
	}
	ballHitted=false;
}

void checkButtonsBreakoutPixel()
{

  if ( !barMoved )
  {
    //can't change position untill the bar moves
    return;
  }

  if (digiPixel.buttonLeftPressed == true)
  {
    wasPressedBreakoutPixel = true;
    goLeftBreakoutPixel = true;

  } else if (digiPixel.buttonRightPressed == true)
  {
    wasPressedBreakoutPixel = true;
    goLeftBreakoutPixel = false;

  } else if (wasPressedBreakoutPixel)
  {
    moveBar();
    wasPressedBreakoutPixel = false;

  }

}

void moveBar(){
	if (--moveDelay != 0) return;
  
	moveDelay = 5;
	barMoved = true;
	
	if (digiPixel.buttonRightPressed==true && barX+barWidth<8){
		barX ++;
	}
	if (digiPixel.buttonLeftPressed==true && barX>0){
		barX --;
	}
}

void updateGraphicsBreakoutPixel(){
	digiPixel.clearScreen();
  
	if (gameOverBreakoutPixel){
		if (gameWin){
			drawHappyFace();
		}else{
			drawSadFace();
		}
	}else{
	//draw bar
		for (int x=barX ; x<barWidth+barX; x++){
			digiPixel.setPixel(x,0,1);		
		}


	//draw targets
		for (int x=0 ; x<8;x++){
			for (int y=0 ; y<3 ; y++){
				digiPixel.setPixel(x,7-y,targets[y][x]);
			}
		}

	//draw ball
		digiPixel.setPixel(ballX,ballY,2);

	}

}

void drawHappyFace(){
	//  digiPixel.drawHorizontalLine(7,2,5,2);
	// 	digiPixel.drawHorizontalLine(0,2,5,2);
	// 	digiPixel.drawVerticalLine(0,2,5,2);
	// 	digiPixel.drawVerticalLine(7,2,5,2);
	// 	digiPixel.setPixel(1,1,2);
	// 	digiPixel.setPixel(1,6,2);
	// 	digiPixel.setPixel(6,1,2);
	// 	digiPixel.setPixel(6,6,2);	
	// 	digiPixel.setPixel(2,5,2);
	// 	digiPixel.setPixel(5,5,2);
	// 	digiPixel.setPixel(2,3,2);
	// 	digiPixel.setPixel(5,3,2);
	// 	digiPixel.setPixel(3,2,2);
	// 	digiPixel.setPixel(4,2,2);
	
	digiPixel.drawHorizontalLine(7,1,6,2);
	digiPixel.drawHorizontalLine(0,1,6,2);
	digiPixel.drawVerticalLine(0,1,6,2);
	digiPixel.drawVerticalLine(7,1,6,2);
	digiPixel.setPixel(2,5,2);
	digiPixel.setPixel(5,5,2);
	digiPixel.setPixel(2,3,2);
	digiPixel.setPixel(5,3,2);
	digiPixel.setPixel(3,2,2);
	digiPixel.setPixel(4,2,2);
}

void drawSadFace(){
	digiPixel.drawHorizontalLine(7,1,6,1);
	digiPixel.drawHorizontalLine(0,1,6,1);
	digiPixel.drawVerticalLine(0,1,6,1);
	digiPixel.drawVerticalLine(7,1,6,1);
	digiPixel.setPixel(2,5,1);
	digiPixel.setPixel(5,5,1);
	digiPixel.setPixel(2,2,1);
	digiPixel.setPixel(5,2,1);
	digiPixel.setPixel(3,3,1);
	digiPixel.setPixel(4,3,1);
}

void loopBreakoutPixel(){ 
  updateGameBreakoutPixel();
  updateGraphicsBreakoutPixel();

  digiPixel.saveButtonStates();
  digiPixel.drawScreen();          
}

// --- END of Merge ../BreakoutPixel/BreakoutPixel.ino ----------------------------
// --- Merged in ../Connect4/Connect4.ino ----------------------------
// Game Notes:
// use left and right buttons to move your piece, then press button A to drop. You can reset the game by pressing button B.




// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Constants
#define Player1Color 1
#define Player2Color 2
#define ButtonDelaySave 10
#define Player1 0
#define Player2 1


// Variables
byte GameArea[8] = {0,0,0,0,0,0,0,0};
byte GameAreaGreen[8] = {0,0,0,0,0,0,0,0};
byte GameAreaRed[8] = {0,0,0,0,0,0,0,0};
byte PlayerPosition[2] = {4, 4};
byte DroppingPieceX = 0;
byte DroppingPieceY = 0;
byte PlayerColorConnect4[2] = {1, 2};
boolean PlayerDroppingPiece = false;
boolean WhoHasWon[2] = {false, false};
byte DroppingPieceDelay = 2;
byte WinFlashDelay = 20;
boolean WinnerLEDsOn = false;
byte ButtonDelay = ButtonDelaySave;
byte WhosTurnIsIt = Player1;


void setupConnect4(){
}


void loopConnect4(){ 
  saveGraphicsConnect4();                    
  MovePlayers();
  CheckGameReset();
  DropPiece();
  CheckForWinner();
  WinnerFlash();
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();         
}

void WinnerFlash(){
  if (WhoHasWon[Player1] == true || WhoHasWon[Player2] == true){  // we only do stuff here if someone has won
    if (WinFlashDelay != 0){
      WinFlashDelay--;
    }
    else{
        WinFlashDelay = 20;
      if (WinnerLEDsOn == true){
        WinnerLEDsOn = false;
      }
      else{
        WinnerLEDsOn = true;
      }
    }
  }
}

void CheckForWinner(){
  if (PlayerDroppingPiece == false){  // we don't want to check to see if someone has won the game, while a piece is still dropping I.E. it needs to have dropped all the way down, then we check for a win.
    int RedYCounter = 0;
    int GreenYCounter = 0;
    int RedXCounter = 0;
    int GreenXCounter = 0;
    
    // First Check for a winner vertically
    for (int x = 0; x <= 7; x++){
      for (int y = 0; y <= 7; y++){
        if (bitRead(GameAreaRed[x], y) == 1){
          RedYCounter++;
        }
        else{
          RedYCounter = 0;
        }
        if (RedYCounter > 3){
          WhoHasWon[Player1] = true;
        }
        
        if (bitRead(GameAreaGreen[x], y) == 1){
          GreenYCounter++;
        }
        else{
          GreenYCounter = 0;
        }
        if (GreenYCounter > 3){
          WhoHasWon[Player2] = true;
        } 
      }
    }
    // Then check for a winner horizontally
    for (int x = 0; x <= 7; x++){
      RedXCounter = 0;
      GreenXCounter = 0;
      for (int y = 0; y <= 7; y++){
        if (bitRead(GameAreaGreen[y], x) == 1){    
          GreenXCounter++;
        }
        else{
          GreenXCounter = 0;
        }
        if (GreenXCounter > 3){
          WhoHasWon[Player2] = true;
        }
       
        if (bitRead(GameAreaRed[y], x) == 1){
          RedXCounter++;
        }
        else{
          RedXCounter = 0;
        }
        if (RedXCounter > 3){
          WhoHasWon[Player1] = true;
        } 
      }
    }
    // then check for a winner diagonally
    for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 5; NumberOfTimesThrough++){	// the initial run through is five times (0 to 4)
      RedYCounter = 0;
      GreenYCounter = 0;
      for (int x = 0; x < (4 +  NumberOfTimesThrough); x++){
        if (bitRead(digiPixel.bufferRed[3 + NumberOfTimesThrough - x], x) == 1){
          RedYCounter++;
        }
        else{
          RedYCounter = 0;
        }
        if (RedYCounter > 3){
          WhoHasWon[Player1] = true;
        }
        if (bitRead(digiPixel.bufferGreen[3 + NumberOfTimesThrough - x], x) == 1){
          GreenYCounter++;
        }
        else{
          GreenYCounter = 0;
        }
        if (GreenYCounter > 3){
          WhoHasWon[Player2] = true;
        }
      }
    }  
    for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 4; NumberOfTimesThrough++){	// this run through is four times (0 to 3)
      RedYCounter = 0;
      GreenYCounter = 0;
      for (int x = 0; x < (7 - NumberOfTimesThrough); x++){
        if (bitRead(digiPixel.bufferRed[7 - x], (x + 1 + NumberOfTimesThrough)) == 1){
          RedYCounter++;
        }
        else{
          RedYCounter = 0;
        }
        if (RedYCounter > 3){
          WhoHasWon[Player1] = true;
        }
        if (bitRead(digiPixel.bufferGreen[7 - x], (x + 1 + NumberOfTimesThrough)) == 1){
          GreenYCounter++;
        }
        else{
          GreenYCounter = 0;
        }
        if (GreenYCounter > 3){
          WhoHasWon[Player2] = true;
        }
      }
    }
    //  these next two for loops will scan the screen from top left to bottom right 
    for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 5; NumberOfTimesThrough++){	// this run through is five times (0 to 4)
      RedYCounter = 0;
      GreenYCounter = 0;
      for (int x = 0; x < (4 + NumberOfTimesThrough); x++){
        if (bitRead(digiPixel.bufferRed[x], (x + 4 - NumberOfTimesThrough)) == 1){
          RedYCounter++;
        }
        else{
          RedYCounter = 0;
        }
        if (RedYCounter > 3){
          WhoHasWon[Player1] = true;
        }
        if (bitRead(digiPixel.bufferGreen[x], (x + 4 - NumberOfTimesThrough)) == 1){
          GreenYCounter++;
        }
        else{
          GreenYCounter = 0;
        }
        if (GreenYCounter > 3){
          WhoHasWon[Player2] = true;
        }
      }
    } 
    for (int NumberOfTimesThrough = 0; NumberOfTimesThrough < 4; NumberOfTimesThrough++){	// this run through is four times (0 to 3)
      RedYCounter = 0;
      GreenYCounter = 0;
      for (int x = 0; x < (7 - NumberOfTimesThrough); x++){
        if (bitRead(digiPixel.bufferRed[x + 1 + NumberOfTimesThrough], (x)) == 1){
          RedYCounter++;
        }
        else{
          RedYCounter = 0;
        }
        if (RedYCounter > 3){
          WhoHasWon[Player1] = true;
        }
        if (bitRead(digiPixel.bufferGreen[x + 1 + NumberOfTimesThrough], (x)) == 1){
          GreenYCounter++;
        }
        else{
          GreenYCounter = 0;
        }
        if (GreenYCounter > 3){
          WhoHasWon[Player2] = true;
        }
      }
    }
  }
}

void CheckGameReset(){
  if (digiPixel.buttonBPressed){
    WhosTurnIsIt = Player1;
    WhoHasWon[Player1] = false;
    WhoHasWon[Player2] = false;
    for (int x = 0; x <= 7; x++){
      GameAreaGreen[x] = 0;
      GameAreaRed[x] = 0;
    } 
  }
}

void DropPiece(){
  if (PlayerDroppingPiece == true){
    if (DroppingPieceDelay != 0){
      DroppingPieceDelay--;
    }
    else{
      DroppingPieceDelay = 2;
      if ((DroppingPieceY == 0) || (bitRead(GameAreaRed[DroppingPieceX], DroppingPieceY - 1) == 1) || (bitRead(GameAreaGreen[DroppingPieceX], DroppingPieceY - 1) == 1)){
        PlayerDroppingPiece = false;
        if (WhosTurnIsIt == Player1){
          bitWrite(GameAreaRed[DroppingPieceX], DroppingPieceY, 1);
          WhosTurnIsIt = Player2;
        }
        else{
          bitWrite(GameAreaGreen[DroppingPieceX], DroppingPieceY, 1);
          WhosTurnIsIt = Player1;
        }
      }
      DroppingPieceY--;
    }
  }
}

void MovePlayers(){
  if (WhoHasWon[Player1] == false & WhoHasWon[Player2] == false){  // we need to make sure you can't keep playing once someone has won the game
    if (PlayerDroppingPiece == false){
      if (ButtonDelay != 0){
        ButtonDelay--;
      }
      else{
        if (digiPixel.buttonLeftPressed & PlayerPosition[WhosTurnIsIt] > 0){
          ButtonDelay = ButtonDelaySave;
          PlayerPosition[WhosTurnIsIt]--;    
        }
        if (digiPixel.buttonRightPressed & PlayerPosition[WhosTurnIsIt] < 7){
          ButtonDelay = ButtonDelaySave;
          PlayerPosition[WhosTurnIsIt]++;    
        }
        if (digiPixel.buttonAPressed & (bitRead(GameAreaRed[PlayerPosition[WhosTurnIsIt]], 6) != 1) & (bitRead(GameAreaGreen[PlayerPosition[WhosTurnIsIt]], 6) != 1)){  // Prevent us from dropping a piece if there is a piece directly under us.
          ButtonDelay = ButtonDelaySave;
          PlayerDroppingPiece = true;
          DroppingPieceX = PlayerPosition[WhosTurnIsIt];
          DroppingPieceY = 7; 
        }
        
        // uncomment this code to add in a very simple computer player
        /*if (WhosTurnIsIt == Player2 & (bitRead(GameAreaRed[PlayerPosition[WhosTurnIsIt]], 6) != 1) & (bitRead(GameAreaGreen[PlayerPosition[WhosTurnIsIt]], 6) != 1)){  // Prevent us from dropping a piece if there is a piece directly under us.
          PlayerDroppingPiece = true;
          DroppingPieceX = random(8);
          DroppingPieceY = 7; 
        }*/
      }
    }
  }
}

void saveGraphicsConnect4(){
  digiPixel.clearScreen();  
  for (byte index = 0; index <= 7; index++){
    if (WinnerLEDsOn == true | WhoHasWon[Player1] == false){
      digiPixel.bufferRed[index] = GameAreaRed[index];
    }
    if (WinnerLEDsOn == true | WhoHasWon[Player2] == false){
      digiPixel.bufferGreen[index] = GameAreaGreen[index];
    }
  }
  if (PlayerDroppingPiece == false){
    digiPixel.setPixel(PlayerPosition[WhosTurnIsIt], 7, PlayerColorConnect4[WhosTurnIsIt]);
  }
  else{
    digiPixel.setPixel(DroppingPieceX, DroppingPieceY, PlayerColorConnect4[WhosTurnIsIt]);
  }
}




// --- END of Merge ../Connect4/Connect4.ino ----------------------------
// --- Merged in ../PixelBird/PixelBird.ino ----------------------------


// DEFAULT CODE FROM EXAMPLE

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// PIXELBIRD CODE

// bird values
int birdX;
int birdY;
const byte birdColor = 3;
const int birdFallSpeed = 200; // bigger = slower
long birdFallUpdate; // millis() when bird falling should be updated
const int birdMoveSpeed = 400; // bigger = slower 
long birdMoveUpdate; // millis() when bird moving (pipes and background) should be updated
int score;
boolean birdIsHovering = false;
const int birdHoverDelayDefault = 30;
int birdHoverDelay = birdHoverDelayDefault;

// pipe values (2 pipes)
const byte numberOfPipes = 2;
int pipeX[numberOfPipes];
int pipeY[numberOfPipes];
const byte pipeColor = 2;

// cloud values
int clouds[] = {0, 1, 1, 0, 1, 0, 1, 1};
const byte cloudColor = 7;

// states (buttons, gameOverPixelBird)
boolean buttonPressed = false;
byte buttonCounter = 0;
boolean gameOverPixelBird = false;

const byte scoreColor = 3;
const byte gameOverPixelBirdColor = 1;

void setupPixelBird(){
  restart();
}

void restart() {
  // start in middle
  birdX = 3;
  birdY = 3;
  
  score = 0;

  // set first move updates
  birdFallUpdate = millis() + birdFallSpeed;
  birdMoveUpdate = millis() + birdMoveSpeed;

  // set the first pipes
  for(int i = 0; i<numberOfPipes; i++)
  {
    pipeX[i] = 10 + (i*5);
    pipeY[i] = random(6);
  }

  // reset gameover
  gameOverPixelBird = false;
  buttonCounter = 0;
}


void loopPixelBird(){ 
  updateGamePixelBird();
  updateGraphicsPixelBird();

  digiPixel.saveButtonStates();
  digiPixel.drawScreen();          
}


void updateGamePixelBird(){
  
  if (!gameOverPixelBird)
  {
    // move bird
    if (millis() > birdFallUpdate)
    {
      if (birdHoverDelay != 0)
      {
        birdHoverDelay--;
      }
        else{
        birdFallUpdate = millis() + birdFallSpeed;
        birdY = birdY - 1;
        if ((birdY < 0) || (birdY > 200)) // game over if under screen
        {
          birdY = 0;
          gameOverPixelBird = true; 
        }
      }
    }

    // flap at keypress (keep state to avoid key hold)
    if (digiPixel.buttonAPressed == true){
      if (!buttonPressed)
      {
        birdY = birdY + 1; 
        buttonPressed = true;
        birdHoverDelay = birdHoverDelayDefault;
      }
    }
    else
    {
      buttonPressed = false;
    }    

    // move background and pipes
    if (millis() > birdMoveUpdate)
    {
      birdMoveUpdate = millis() + birdMoveSpeed;

      // move clouds
      for (int i = 0; i < 7; i ++)
      {
        clouds[i] = clouds[i+1];
      }
      clouds[7] = random(2); // 0 sky, 1 cloud

      // move pipes
      for(int i = 0; i<numberOfPipes; i++)
      {

        pipeX[i] = pipeX[i] - 1;
        
        if (pipeX[i] == birdX-1) // bird passes pipe
        {
          score++;
        }
        
        if (pipeX[i] < 0)
        {
          pipeY[i] = random(6);
          pipeX[i] = 9;
        }

      }

    } 

    // check for collision with pipes
    for(int i = 0; i<numberOfPipes; i++)
    {

      if (birdX == pipeX[i])
      {
        if ((birdY < pipeY[i]) || (birdY > pipeY[i] + 2))
        {
          gameOverPixelBird = true;
        }
      }

    }
  }
  else
  {
    waitForRestart();
  }  
}

void updateGraphicsPixelBird(){
  digiPixel.clearScreen();
  // draw clouds
  
  for (int i = 0; i < 8; i++)
  {
    if (clouds[i] == 1)
    {
      digiPixel.setPixel(i, 7, cloudColor);
    }
  }

  // draw pipes
  for (int i = 0; i < numberOfPipes; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (pipeX[i] < 8)
      {
        if ((j < pipeY[i]) or (j > pipeY[i] + 2))
        {
          digiPixel.setPixel(pipeX[i], j, pipeColor);
        }
      }

    }
  }

  
  // draw bird
  digiPixel.setPixel(birdX, birdY, birdColor);

  // draw game over
  if (gameOverPixelBird)
  {
    int scoreCounter = 0;
    for (int j = 0; j < 8; j++)
    {
      for (int i = 0; i < 8; i++)
      {
        digiPixel.setPixel(i, j, (scoreCounter < score ? scoreColor : gameOverPixelBirdColor));
        scoreCounter++;
      }
    }
  }
}


void waitForRestart()
{
  if (digiPixel.buttonAPressed == true){
    if (!buttonPressed)
    {
      buttonPressed = true;
    }
  }
  else
  {
    if (buttonPressed)
    {
      // only count button ups
      buttonCounter++;
    }
    buttonPressed = false;

  }    
  if (buttonCounter > 1)
  {
    // reset after two button ups (2 to avoid direct restart)
    restart();
  }
}







// --- END of Merge ../PixelBird/PixelBird.ino ----------------------------
// --- Merged in ../Dice2/Dice2.ino ----------------------------
// press button B to roll the dice.




// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
// DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


// Program memory arrays
byte DiceNumbersRed[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b01000000, 0b11111111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001100, 0b00010100, 0b01100100, 0b11111111, 0b00000100, 0b00000000, 0b00000000, 0b00000000, 0b11110010, 0b10010001, 0b10010001, 0b10010001, 0b10001110, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte DiceNumbersGreen[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000011, 0b10000101, 0b10001001, 0b10010001, 0b01100001, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001100, 0b00010100, 0b01100100, 0b11111111, 0b00000100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte DiceNumbersBlue[64]PROGMEM={0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01000010, 0b10000001, 0b10001001, 0b10001001, 0b01110110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11110010, 0b10010001, 0b10010001, 0b10010001, 0b10001110, 0b00000000, 0b00000000, 0b00000000, 0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};

// Variables
byte RollSpeedSave = 0;
byte RollSpeed = RollSpeedSave; 
byte TextOffset = 0;
boolean diceIsRolling = true;
byte randomNumberCounter = 1;
byte numberToLandOn = randomNumberCounter * 8;
byte RotateAngle = 0;


void setupDice2(){
}


void loopDice2(){  
  updateGraphicsDice2();                 
  saveGraphicsDice2();                
  digiPixel.saveButtonStates();     
  digiPixel.drawScreen();          
  checkForButtonPressDice2();
  doRandomNumberCountDice2();
}

void doRandomNumberCountDice2()
{
  randomNumberCounter++;
  if (randomNumberCounter > 6)
  {
    randomNumberCounter = 1;
  }
}

void checkForButtonPressDice2()
{
  if (digiPixel.buttonBPressed == true)
  {
    diceIsRolling = true;
    numberToLandOn = randomNumberCounter * 8;
    RollSpeedSave = 0;
  }  
}

void updateGraphicsDice2(){
  if (diceIsRolling == true)
  {
    if (RollSpeed != 0){
      RollSpeed--;
    }
    else{
       RollSpeed = RollSpeedSave;
       TextOffset += 8;  
       if (TextOffset == sizeof(DiceNumbersRed) - 8){
         TextOffset = 8;
         RollSpeedSave++; 
         RotateAngle++;
         if (RotateAngle > 3)
         {
           RotateAngle = 0;
         }
       }
    }
    if (RollSpeedSave == 5 & TextOffset == numberToLandOn)
    {
      diceIsRolling = false;
      RotateAngle = 0;
    }
  }
}

void saveGraphicsDice2(){
  digiPixel.clearScreen();
  for (byte index = 0; index <= 7; index++)
  {
   digiPixel.bufferRed[index] = pgm_read_dword(&DiceNumbersRed[(index) + TextOffset]);
   digiPixel.bufferGreen[index] = pgm_read_dword(&DiceNumbersGreen[(index) + TextOffset]);
   digiPixel.bufferBlue[index] = pgm_read_dword(&DiceNumbersBlue[(index) + TextOffset]);
  }
  digiPixel.rotateScreen(RotateAngle * 90);
}




// --- END of Merge ../Dice2/Dice2.ino ----------------------------

// Program memory arrays
byte numberTableArcade[30]PROGMEM={0b01111110, 0b01000010, 0b01111110, 0b00100010, 0b01111110, 0b00000010, 0b01001110, 0b01001010, 0b01111010, 0b01000010, 0b01001010, 0b01111110, 0b01111000, 0b00001000, 0b01111110, 0b01111010, 0b01001010, 0b01001110, 0b01111110, 0b01001010, 0b01001110, 0b01000000, 0b01000000, 0b01111110, 0b01111110, 0b01001010, 0b01111110, 0b01111010, 0b01001010, 0b01111110};

// Variables
byte playGame = 0;
byte chooseGame = 1;

typedef void (*FunctionCallback)();
struct game {
  char *title;
  FunctionCallback loop;
  FunctionCallback setup;
};

struct game games[] = {
  {"TheGreatRace", &loopTheGreatRace, &setupTheGreatRace},
  {"SnakePixel", &loopSnakePixel, &setupSnakePixel},
  {"SuperPixelBros", &loopSuperPixelBros, &setupSuperPixelBros},
  {"BreakoutPixel", &loopBreakoutPixel, &setupBreakoutPixel},
  {"Connect4", &loopConnect4, &setupConnect4},
  {"PixelBird", &loopPixelBird, &setupPixelBird},
  {"Dice2", &loopDice2, &setupDice2}
};
byte maxGames = sizeof(games)/sizeof(game);
boolean debounceButton = false;

byte checkForGameToPlay() {
  if (debounceButton == false) {
    if (digiPixel.buttonRightPressed == true) {
      debounceButton = true;
      chooseGame++;
      if (chooseGame > maxGames) {
	chooseGame = 1;
      }
    } else if (digiPixel.buttonLeftPressed == true) {
      debounceButton = true;
      chooseGame--;
      if (chooseGame == 0) {
	chooseGame = maxGames;
      }
    } else if (digiPixel.buttonAPressed) {
      if (chooseGame > 0) {
	return(chooseGame);
      }
    }
  } else {
    if (! digiPixel.buttonRightPressed && ! digiPixel.buttonLeftPressed) {
      debounceButton = false;
    }
  }

  return(0);
}

void showGameCounter() {
  digiPixel.clearScreen();
  byte mSD = chooseGame / 10;
  byte lSD = chooseGame % 10;
  if (mSD != 0) {
    for (byte index = 0; index <= 2; index++) {
      digiPixel.bufferGreen[index] = pgm_read_dword(&numberTableArcade[(index) + (mSD * 3)]);
    }
  }
  byte center = 4;
  if (maxGames < 10) {
    center = 3;
  }
  for (byte index = center; index <= center+2; index++) {
     digiPixel.bufferGreen[index] = pgm_read_dword(&numberTableArcade[(index - center) + (lSD * 3)]);
  }
}

void setup() {

}

void loop() {
   if (playGame == 0) {
     showGameCounter();                   
     digiPixel.saveButtonStates();    
     digiPixel.drawScreen();          

     playGame = checkForGameToPlay();

     if (playGame > 0) {
	games[playGame-1].setup();
     }
   } else {
     digiPixel.saveButtonStates();    
     if (digiPixel.buttonLeftPressed && digiPixel.buttonAPressed) {
       debounceButton = true;
       // This may not let each game start off again properly, unless their setup functions did the right thing
       playGame = 0;
     } else {
        games[playGame-1].loop();
     }
   }
}
