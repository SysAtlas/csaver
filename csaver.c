#include "csaver.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

#define MAXANGLE 180 

extern const int windowWidth;
extern const int windowHeight;

double convertToRadian(double angleDegrees) {
    return angleDegrees * PI / 180.0f;
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

void botLine(int offset, Angle angle, Color color) { // Offset from 0 to windowWidth, angle from 0 to 180 in degrees.
    int targetX = offset + (windowHeight / angle.tangent);
    DrawLine(offset, windowHeight, targetX, 0, color);
}

void scaledLine(int offset, Angle angle, double length, int step, Color color) {
}
void animatedLine(int offset, Angle angle, double length, int step, Color color) { 
    double xPos = offset; // Default positions for X and Y
    double yPos = windowHeight;
    double xPosTrace = offset;
    double yPosTrace = windowHeight;

    int origLength = length;
    int traceLineCounter = 0;
    int traceLength = 0;

    while (xPosTrace < windowWidth && xPosTrace > 0 && yPosTrace >= 0.0f) { 
        BeginDrawing();    

        xPos = angle.cosine * length + offset;
        yPos = windowHeight - ((xPos - offset) * angle.tangent);
        DrawLine(offset, windowHeight, xPos, yPos, color); 

        if (traceLineCounter >= origLength) { // trace line logic
            xPosTrace = angle.cosine * traceLength + offset;
            yPosTrace = windowHeight - ((xPosTrace - offset) * angle.tangent);
            DrawLine(offset, windowHeight, xPosTrace, yPosTrace, BLACK); 
            ++traceLength;
        }

        EndDrawing();

        length += step;
        ++traceLineCounter;
        // printf("X: %f, Y: %f\n", xPos, yPos); // logging
    }
}

void animatedLineWithTrace(int offset, double angle, double length, int step, int add, Color color) {
}
