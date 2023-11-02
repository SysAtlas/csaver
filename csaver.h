#pragma once

#include "raylib/src/raylib.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <getopt.h>

// Draw a line from the bottom part of the screen under the specified angle
void botLine(int offset, int angle, Color color); 
// Draw a line from the bottom part of the screen with randomized parameters
void randomBotLine(); 
