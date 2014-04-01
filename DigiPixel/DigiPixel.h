

#ifndef DigiPixel_h
#define DigiPixel_h

#include "Arduino.h"

#define black 0
#define red 1
#define green 2
#define yellow 3
#define blue 4
#define magenta 5
#define cyan 6
#define white 7
#define blackbarrier 8
#define redbarrier 9
#define greenbarrier 10
#define yellowbarrier 11
#define bluebarrier 12
#define magentabarrier 13
#define cyanbarrier 14
#define whitebarrier 15

class DigiPixel{
  public:
  	// functions
  	DigiPixel(byte setLatchAndShiftNotLoadPin, byte setClockPin, byte setLEDDataPin, byte setOutputEnablePin, byte setButtonDataPin);		// constructor
  	void drawScreen();
  	void airWrite(int flashDelay);
  	void clearScreen();
  	void drawBox(byte fromX, byte fromY, byte toX, byte toY, byte color);
  	void drawVerticalLine(byte xLocation, byte fromY, byte toY, byte color);
  	void drawHorizontalLine(byte yLocation, byte fromX, byte toX, byte color);
  	void fillScreen(byte color);
  	void saveButtonStates();
  	void setPixel(byte pixelX, byte pixelY, byte color);
  	byte getPixel(byte pixelX, byte pixelY);
  	boolean checkBarrier(byte pixelX, byte pixelY);
  	void rotateScreen(int degrees);
  	void invertColors();
  	void shiftOut(byte myDataOut);
  	
  	// variable arrays
	static byte columnData[8];
	static byte bufferRed[8];
	static byte bufferGreen[8];
	static byte bufferBlue[8];
	static byte bufferBarriers[8];
	
	// variables
	static byte tempByte;
	static byte index1;
	static byte index2;
	static byte latchShiftNotLoadPin;
	static byte clockPin;
	static byte lEDDataPin;
	static byte outputEnablePin;
	static byte buttonDataPin;
	static byte buttonStatus;
	static boolean buttonAPressed;
	static boolean buttonBPressed;
	static boolean buttonUpPressed;
	static boolean buttonDownPressed;
	static boolean buttonLeftPressed;
	static boolean buttonRightPressed;
};

#endif