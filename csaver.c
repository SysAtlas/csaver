#include "csaver.h"
#include "raylib/src/raylib.h"
#include <unistd.h>

#define MAXANGLE 180 

extern const int windowWidth;
extern const int windowHeight;

double convertToRadian(double angle) {
    return angle * PI / 180.0f;
}

Color randomColor() {
    Color randomColor = {random() % 255, random() % 255, random() % 255, 255}; 
    return randomColor;
}

void randomBotLine() {
    double randomAngle = random() % MAXANGLE;
    int randomStart = random() % windowWidth;
    int targetX = randomStart + (windowHeight / tan (convertToRadian(randomAngle)) ); // Calculate where we land on x axis.
    DrawLine(randomStart, windowHeight, targetX, 0, randomColor());
}

void botLine(int offset, int angle, Color color) { // Offset from 0 to windowWidth, angle from 0 to 180 in degrees.
    int targetX = offset + (windowHeight / tan(convertToRadian(angle)));
    DrawLine(offset, windowHeight, targetX, 0, color);
}

void animatedLine(int offset, double angle, double length, int step, int addedLength, Color color) { 
    for (int i = 0; i < addedLength; i += step) {
        BeginDrawing();    

        double xPos = cos(angle) * length + offset;
        double yPos = windowHeight - ((xPos - offset) * tan(angle));
        DrawLine(offset, windowHeight, xPos, yPos, color); 

        EndDrawing();
        length += step;
    }
}
