

#include "Arduino.h"
#include "DigiPixel.h"

// Variable declaration and initialisation
byte DigiPixel::columnData[8] = {B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001};
byte DigiPixel::bufferRed[8];
byte DigiPixel::bufferGreen[8];
byte DigiPixel::bufferBlue[8];
byte DigiPixel::bufferBarriers[8];
byte DigiPixel::tempByte;
byte DigiPixel::index1;
byte DigiPixel::index2;
byte DigiPixel::buttonStatus;
boolean DigiPixel::buttonAPressed;
boolean DigiPixel::buttonBPressed;
boolean DigiPixel::buttonUpPressed;
boolean DigiPixel::buttonDownPressed;
boolean DigiPixel::buttonLeftPressed;
boolean DigiPixel::buttonRightPressed;
byte DigiPixel::latchShiftNotLoadPin;
byte DigiPixel::clockPin;
byte DigiPixel::lEDDataPin;
byte DigiPixel::outputEnablePin;
byte DigiPixel::buttonDataPin;

DigiPixel::DigiPixel(byte setLatchAndShiftNotLoadPin, byte setClockPin, byte setLEDDataPin, byte setOutputEnablePin, byte setButtonDataPin){
	latchShiftNotLoadPin = setLatchAndShiftNotLoadPin;
	clockPin = setClockPin;
	lEDDataPin = setLEDDataPin;
	outputEnablePin = setOutputEnablePin;
	buttonDataPin = setButtonDataPin;
	pinMode(latchShiftNotLoadPin, OUTPUT);	
	pinMode(clockPin, OUTPUT);	
	pinMode(lEDDataPin, OUTPUT);
	pinMode(outputEnablePin, OUTPUT);
	pinMode(buttonDataPin, INPUT);
}

void DigiPixel::drawScreen(){
  for (index1=0; index1<=7; index1++){
    digitalWrite(latchShiftNotLoadPin, LOW);
    DigiPixel::shiftOut(columnData[index1]);
    DigiPixel::shiftOut(~bufferBlue[index1]);    
    DigiPixel::shiftOut(~bufferRed[index1]);     
    DigiPixel::shiftOut(~bufferGreen[index1]);	
    digitalWrite(latchShiftNotLoadPin, HIGH);
    digitalWrite(outputEnablePin,LOW);
    delay(1);  // delay for 1mS
    digitalWrite(outputEnablePin,HIGH);
  }
}

void DigiPixel::airWrite(int flashDelay){
    digitalWrite(latchShiftNotLoadPin, LOW);
    DigiPixel::shiftOut(columnData[0]);
    DigiPixel::shiftOut(~bufferBlue[0]);    
    DigiPixel::shiftOut(~bufferRed[0]);
    DigiPixel::shiftOut(~bufferGreen[0]);
    digitalWrite(latchShiftNotLoadPin, HIGH);
    digitalWrite(outputEnablePin,LOW);
    delay(flashDelay);  
    digitalWrite(outputEnablePin,HIGH);
}

void DigiPixel::clearScreen(){
  for (index1 = 0; index1 <= 7; index1++){
   bufferRed[index1] = 0; 
   bufferGreen[index1] = 0; 
   bufferBlue[index1] = 0; 
   bufferBarriers[index1] = 0; 
  }
}

void DigiPixel::drawBox(byte fromX, byte fromY, byte toX, byte toY, byte color){
	if (toX < fromX){
		tempByte = fromX;
		fromX = toX;
		toX = tempByte;
	}
	if (toY < fromY){
		tempByte = fromY;
		fromY = toY;
		toY = tempByte;
	}
  for (index1 = 0; index1 <= (toX - fromX); index1++){
    for (index2 = 0; index2 <= (toY - fromY); index2++){
      setPixel(fromX + index1, fromY + index2, color);
    }
  }
}

void DigiPixel::drawVerticalLine(byte xLocation, byte fromY, byte toY, byte color){
	if (toY < fromY){
		tempByte = fromY;
		fromY = toY;
		toY = tempByte;
	}
  for (index1 = 0; index1 <= (toY - fromY); index1++){
    setPixel(xLocation, fromY + index1, color);
  }
}

void DigiPixel::drawHorizontalLine(byte yLocation, byte fromX, byte toX, byte color){
	if (toX < fromX){
		tempByte = fromX;
		fromX = toX;
		toX = tempByte;
	}
  for (index1 = 0; index1 <= (toX - fromX); index1++){
    setPixel(fromX + index1, yLocation, color);
  }
}

void DigiPixel::fillScreen(byte color){
  for (index1 = 0; index1 <= 7; index1++){
  	bufferRed[index1] = 0;
  	bufferGreen[index1] = 0;
  	bufferBlue[index1] = 0;
  	bufferBarriers[index1] = 0;
  	if (bitRead(color, 0) == 1){
		bufferRed[index1] = 255;
	}
  	if (bitRead(color, 1) == 1){
		bufferGreen[index1] = 255;
	}
  	if (bitRead(color, 2) == 1){
		bufferBlue[index1] = 255;
	}
  	if (bitRead(color, 3) == 1){
		bufferBarriers[index1] = 255;
	}
  }
}

void DigiPixel::rotateScreen(int degrees){
  byte tempRed[8];
  byte tempGreen[8];
  byte tempBlue[8];
  byte tempBarriers[8];
  for (index1 = 0; index1 <= 7; index1++){
    tempRed[index1] = bufferRed[index1];
    tempGreen[index1] = bufferGreen[index1];
    tempBlue[index1] = bufferBlue[index1];
    tempBarriers[index1] = bufferBarriers[index1];
  }
  switch (degrees) {
    case 90:
      for (index1=0; index1<=7; index1++){
        for (index2=0; index2<=7; index2++){
          bitWrite(bufferRed[index1],index2,bitRead(tempRed[index2],(7 - index1)));
          bitWrite(bufferGreen[index1],index2,bitRead(tempGreen[index2],(7 - index1)));
          bitWrite(bufferBlue[index1],index2,bitRead(tempBlue[index2],(7 - index1)));
          bitWrite(bufferBarriers[index1],index2,bitRead(tempBarriers[index2],(7 - index1)));
        }
      }
      break;
    case 180:
      for (index1=0; index1<=7; index1++){
        for (index2=0; index2<=7; index2++){
        bitWrite(bufferRed[index1],index2,bitRead(tempRed[7 - index1],(7 - index2)));
        bitWrite(bufferGreen[index1],index2,bitRead(tempGreen[7 - index1],(7 - index2)));
        bitWrite(bufferBlue[index1],index2,bitRead(tempBlue[7 - index1],(7 - index2)));
        bitWrite(bufferBarriers[index1],index2,bitRead(tempBarriers[7 - index1],(7 - index2)));
        }
      }
      break;
    case 270: 
      for (index1=0; index1<=7; index1++){
        for (index2=0; index2<=7; index2++){
        bitWrite(bufferRed[index1],index2,bitRead(tempRed[7 - index2],(index1)));
        bitWrite(bufferGreen[index1],index2,bitRead(tempGreen[7 - index2],(index1)));
        bitWrite(bufferBlue[index1],index2,bitRead(tempBlue[7 - index2],(index1)));
        bitWrite(bufferBarriers[index1],index2,bitRead(tempBarriers[7 - index2],(index1)));
        }
      } 
      break;
  }
}

void DigiPixel::setPixel(byte pixelX, byte pixelY, byte color){
  bitWrite(bufferRed[pixelX], pixelY, bitRead(color, 0)); 
  bitWrite(bufferGreen[pixelX], pixelY, bitRead(color, 1)); 
  bitWrite(bufferBlue[pixelX], pixelY, bitRead(color, 2)); 
  bitWrite(bufferBarriers[pixelX], pixelY, bitRead(color, 3)); 
}

byte DigiPixel::getPixel(byte pixelX, byte pixelY){
	bitWrite(tempByte, 0, bitRead(bufferRed[pixelX], pixelY));
	bitWrite(tempByte, 1, bitRead(bufferGreen[pixelX], pixelY));
	bitWrite(tempByte, 2, bitRead(bufferBlue[pixelX], pixelY));
	bitWrite(tempByte, 3, bitRead(bufferBarriers[pixelX], pixelY));
	return tempByte;
}

boolean DigiPixel::checkBarrier(byte pixelX, byte pixelY){
	if (bitRead(bufferBarriers[pixelX], pixelY) == 1){
		return true;
	}
	else{
		return false;
	}
}

void DigiPixel::saveButtonStates(){
  digitalWrite(clockPin, LOW);          // start with the clock line low
  digitalWrite(latchShiftNotLoadPin, LOW);  // first load the parallel data and then
  digitalWrite(clockPin, HIGH);        // send a clock pulse to grab the parallel data
  digitalWrite(clockPin, LOW);
  digitalWrite(latchShiftNotLoadPin, HIGH);  // now that it's loaded we need to shift the data out to the microcontroller and save it.
  for(index1=0;index1<=7;index1++){                // the first two bits will always be logic 1's, the next six are A, B, R, L, D, U
    bitWrite(buttonStatus,index1,digitalRead(buttonDataPin));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
  digitalWrite(latchShiftNotLoadPin, LOW);  //Before we finish, inhibit the serial data from shifting by setting it back to LOAD.
  if (buttonStatus & B00000100) buttonAPressed = true;
  else buttonAPressed = false;
  if (buttonStatus & B00001000) buttonBPressed = true;
  else buttonBPressed = false;
  if (buttonStatus & B00010000) buttonRightPressed = true;
  else buttonRightPressed = false;
  if (buttonStatus & B00100000) buttonLeftPressed = true;
  else buttonLeftPressed = false;
  if (buttonStatus & B01000000) buttonDownPressed = true;
  else buttonDownPressed = false;
  if (buttonStatus & B10000000) buttonUpPressed = true;
  else buttonUpPressed = false;
}

void DigiPixel::invertColors(){  
	for (index1 = 0; index1 <= 7; index1++){
   		bufferRed[index1] = ~bufferRed[index1]; 
   		bufferGreen[index1] = ~bufferGreen[index1]; 
   		bufferBlue[index1] = ~bufferBlue[index1]; 
  	}
}

void DigiPixel::shiftOut(byte dataOut) {
  byte pinState;
  digitalWrite(lEDDataPin, 0);
  digitalWrite(clockPin, 0);
  for (index2=0; index2<=7; index2++)  {
    digitalWrite(clockPin, 0);
    if (dataOut & (1 << index2)) {
      pinState= 1;
    }
    else {
      pinState= 0;
    }
    digitalWrite(lEDDataPin, pinState);
    digitalWrite(clockPin, 1);
    digitalWrite(lEDDataPin, 0);
  }
  digitalWrite(clockPin, 0);
}