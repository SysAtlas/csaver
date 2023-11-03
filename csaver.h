#pragma once

#include "raylib/src/raylib.h"
#include <math.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

typedef struct Angle {
	double value;
	double sine;
	double cosine;
	double tangent;
} Angle;

// Convert an angle from degrees to radians
double convertToRadian(double angleDegrees);
// Generate a random color
Color randomColor(void);
// Draw a line from the bottom part of the screen under the specified angle
void botLine(int offset, Angle angle, Color color); 
// Draw a line from the bottom part of the screen with randomized parameters
void randomBotLine(void); 
//
void scaledLine(int offset, Angle angle, double length, int step, Color color); 

void animatedLine(int offset, Angle angle, double length, int step, Color color);
