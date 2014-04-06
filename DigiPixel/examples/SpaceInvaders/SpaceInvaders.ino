//Use left and right to move bar. Press B to restart after gameOver. 
//Red sad face when lose and Green Happy face when WIN :)
//TODO: Add bonus to make bar bigger and smaller...
//TODO: More Levels

// made for the digipixel http://www.bradsprojects.com/the-digipixel/
// Made by github.com/kostassite 2014

#include <DigiPixel.h>
#define TARGETCOLOR 4 
DigiPixel digiPixel(5,2,6,4,3);  // LED Latch/Button Shift !load pin, LED/Button clock pin, LED Data Pin, LED Output Enable pin, Buttons data pin)

int barX=0;
int barWidth = 3;
int moveDelay = 10;
bool barMoved = false;
bool wasPressed = false;
bool goLeft = false;

int ballDelay = 20;
bool ballGoesUp = true;
bool ballGoesRight = true;
int ballX=3;
int ballY=1;
bool ballHitted;

int targets[3][8];

bool gameOver = false;
bool gameWin = false;

void setup(){
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
	gameOver = false;
	gameWin = false;
}

void updateGame(){

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
	if (gameOver==true && digiPixel.buttonBPressed==true){
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
		gameOver = true;
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
	gameOver = true;
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

void checkButtons()
{

  if ( !barMoved )
  {
    //can't change position untill the bar moves
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
    moveBar();
    wasPressed = false;

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

void updateGraphics(){
	digiPixel.clearScreen();
  
	if (gameOver){
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

void loop(){ 
  updateGame();
  updateGraphics();

  digiPixel.saveButtonStates();
  digiPixel.drawScreen();          
}

