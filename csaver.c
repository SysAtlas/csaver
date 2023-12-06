#include "csaver.h"
#include "csaverutil.h"
#include <stdio.h>

extern const int windowWidth;
extern const int windowHeight;

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

void animatedLine(int offset, Angle angle, double length, int step, Color color, Side side) { 
    double xPosOriginal = offset; // Default positions for X and Y
    double yPosOriginal = windowHeight;
    switch (side) {
        case TOP:
            xPosOriginal = offset;
            yPosOriginal = 0;
            angle = generateAngle(180 + angle.degrees);
            break;
        case LEFT:
            xPosOriginal = 0;
            yPosOriginal = offset;
            break;
        case RIGHT:
            xPosOriginal = windowWidth;
            yPosOriginal = offset;
            angle = generateAngle(angle.degrees + 180);
            break;
        case BOTTOM:
            break;
    }
    double xPosTrace = xPosOriginal;
    double yPosTrace = yPosOriginal;

    double xPos = xPosOriginal;
    double yPos = yPosOriginal;

    int origLength = length;
    int traceLineCounter = 0;
    int traceLength = 0;

    printf("Angle: %f\n", angle.degrees);
    while (xPosTrace <= windowWidth && xPosTrace >= 0 && yPosTrace >= 0.0f && yPosTrace <= windowHeight) { 
        BeginDrawing();
	if (xPosOriginal == offset) { // Check if we are TOP or BOTTOM
	    xPos = angle.cosine * length + xPosOriginal;
	    yPos = yPosOriginal - ((xPos - xPosOriginal) * angle.tangent);
	} else { // LEFT or RIGHT
            yPos = angle.cosine * length + yPosOriginal;
            xPos = xPosOriginal + ((yPos - yPosOriginal) * angle.tangent);
	}
        DrawLine(xPosOriginal, yPosOriginal, xPos, yPos, color); 

        if (traceLineCounter >= origLength) { // trace line logic
            if (xPosOriginal == offset) {
                xPosTrace = angle.cosine * traceLength + xPosOriginal;
                yPosTrace = yPosOriginal - ((xPosTrace - xPosOriginal) * angle.tangent);
            } else {
                yPosTrace = angle.cosine * traceLength + yPosOriginal;
                xPosTrace = xPosOriginal + ((yPosTrace - yPosOriginal) * angle.tangent);
            }
            DrawLine(xPosOriginal, yPosOriginal, xPosTrace, yPosTrace, BLACK); 
            ++traceLength;
        }


	length += step;
        ++traceLineCounter;
        // printf("X: %f, Y: %f\n", xPos, yPos); // logging
        EndDrawing();
    }
}

void animatedLineWithTrace(int offset, double angle, double length, int step, int add, Color color) {
}
