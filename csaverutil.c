#include "csaverutil.h" 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double convertToRadian(double angleDegrees) {
    return angleDegrees * PI / 180.0f;
}

Color randomColor() {
    Color randomColor = {random() % 255, random() % 255, random() % 255, 255}; 
    return randomColor;
}

Side randomSide() {
    Side randomSide = {random() % 4};
    return randomSide;
}

Angle generateAngle(double degrees) {
	double rads = convertToRadian(degrees);
	Angle res = {degrees, rads, sin(rads), cos(rads), tan(rads)};
	return res;
}
