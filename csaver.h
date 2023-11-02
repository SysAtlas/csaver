#pragma once

#include "raylib/src/raylib.h"
#include <math.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

// Convert an angle from degrees to radians
double convertToRadian(double angle);
// Generate a random color
Color randomColor(void);
// Draw a line from the bottom part of the screen under the specified angle
void botLine(int offset, int angle, Color color); 
// Draw a line from the bottom part of the screen with randomized parameters
void randomBotLine(void); 
//
void animatedLine(int offset, double angle, double length, int step, int add, Color color);
