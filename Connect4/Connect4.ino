// Game Notes:
// use left and right buttons to move your piece, then press button A to drop. You can reset the game by pressing button B.

#include <DigiPixel.h>
#include <avr/pgmspace.h>

// leave the following line uncommented for use with a Digispark
//DigiPixel digiPixel(3,0,5,2,1);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

// leave the following line uncommented for use with an Arduino
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)


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
byte PlayerColor[2] = {1, 2};
boolean PlayerDroppingPiece = false;
boolean WhoHasWon[2] = {false, false};
byte DroppingPieceDelay = 2;
byte WinFlashDelay = 20;
boolean WinnerLEDsOn = false;
byte ButtonDelay = ButtonDelaySave;
byte WhosTurnIsIt = Player1;


void setup(){
}


void loop(){ 
  saveGraphics();                    
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

void saveGraphics(){
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
    digiPixel.setPixel(PlayerPosition[WhosTurnIsIt], 7, PlayerColor[WhosTurnIsIt]);
  }
  else{
    digiPixel.setPixel(DroppingPieceX, DroppingPieceY, PlayerColor[WhosTurnIsIt]);
  }
}




