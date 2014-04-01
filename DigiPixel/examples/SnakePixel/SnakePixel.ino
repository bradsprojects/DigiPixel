//use left and right button to direct the snake to eat the red apple

#include <DigiPixel.h>
#include <avr/pgmspace.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5, 2, 6, 4, 3); // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

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

bool wasPressed = false;
bool goLeft = false;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
   
  clearHistory();
  
  appleX = random(0, 7);
  appleY = random(0, 7);
  
  
}

void loop()
{

  checkButtons();
  moveSnake();
  bool gameOver = checkSnakeDeath();
  if (gameOver)
  {
    Serial.println("Dead");
    showDeath();


  } else
  {
    saveGraphics();
  }
  checkEatApple();
  digiPixel.saveButtonStates();
  digiPixel.drawScreen();
}
void checkButtons()
{

  if ( !snakeMoved )
  {
    //can't change direction untill the snake moves
    return;
  }
  if (digiPixel.buttonLeftPressed == true)
  {
    wasPressed = true;
    goLeft = true;

  } else if (digiPixel.buttonRightPressed == true)
  {
    wasPressed = true;
    goLeft = false;

  } else if (wasPressed)
  {
    changeDirection();
    wasPressed = false;

  }

}

void changeDirection()
{
  if (snakeDirection == RIGHT)
  {
    if (goLeft)
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
    if (goLeft)
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
    if (goLeft)
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
    if (goLeft)
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

void saveGraphics()
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
    saveGraphics();
    
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
