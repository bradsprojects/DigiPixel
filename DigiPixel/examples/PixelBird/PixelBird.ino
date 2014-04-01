#include <DigiPixel.h>

// DEFAULT CODE FROM EXAMPLE

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


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

// states (buttons, gameOver)
boolean buttonPressed = false;
byte buttonCounter = 0;
boolean gameOver = false;

const byte scoreColor = 3;
const byte gameOverColor = 1;

void setup(){
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
  gameOver = false;
  buttonCounter = 0;
}


void loop(){ 
  updateGame();
  updateGraphics();

  digiPixel.saveButtonStates();
  digiPixel.drawScreen();          
}


void updateGame(){
  
  if (!gameOver)
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
          gameOver = true; 
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
          gameOver = true;
        }
      }

    }
  }
  else
  {
    waitForRestart();
  }  
}

void updateGraphics(){
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
  if (gameOver)
  {
    int scoreCounter = 0;
    for (int j = 0; j < 8; j++)
    {
      for (int i = 0; i < 8; i++)
      {
        digiPixel.setPixel(i, j, (scoreCounter < score ? scoreColor : gameOverColor));
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







