#pragma once
#include "csaverutil.h" 

// Draw a line from the bottom part of the screen under the specified angle
void botLine(int offset, Angle angle, Color color); 
// Draw a line from the bottom part of the screen with randomized parameters
void randomBotLine(void); 
//
void scaledLine(int offset, Angle angle, double length, int step, Color color); 

void animatedLine(int offset, Angle angle, double length, int step, Color color, Side side);
