#include "csaver.h"
#include "raylib/src/raylib.h"

extern const int windowWidth;
extern const int windowHeight;

double convertToRadian(double angle) {
    return angle * PI / 180.0f;
}

void randomBotLine() { // Offset from 0 to windowWidth, angle from 0 to 180 in degrees.
    double randomAngle = random() % 180;
    int randomStart = random() % 800;
    int targetX = randomStart + (windowHeight / tan(convertToRadian(randomAngle))); // Calculate where we land on x axis.
    Color randomColor = {random() % 255, random() % 255, random() % 255, 255}; 
    DrawLine(randomStart, windowHeight, targetX, 0, randomColor);
}

void botLine(int offset, int angle, Color color) { // Offset from 0 to windowWidth, angle from 0 to 180 in degrees.
    int targetX = offset + (windowHeight / tan(convertToRadian(angle)));
}

