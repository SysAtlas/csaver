#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include "raylib/src/raylib.h"

#define MAXANGLE 180 

typedef struct Angle {
	double degrees;
	double radians;
	double sine;
	double cosine;
	double tangent;
} Angle;

typedef enum Side {BOTTOM, TOP, LEFT, RIGHT} Side;

// Convert an angle from degrees to radians
double convertToRadian(double angleDegrees);

// Generate a random color
Color randomColor(void);

Side randomSide(void);

Angle generateAngle(double degrees);
