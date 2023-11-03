#include "csaver.h"
#include "raylib/src/raylib.h"
#include <math.h>
#include <stdlib.h>

const int windowWidth = 1440;
const int windowHeight = 900;

double angleInput = 15.0f;	
int offset = 200;
int length = 50;


int main(int argc, char* argv[]) {
    srandom(1337);
    // Angle angle = {convertToRadian(angleInput), sin(angleInput), cos(angleInput), tan(angleInput)};

    InitWindow(windowWidth, windowHeight, "CSaver");
    SetExitKey(KEY_CAPS_LOCK); // Apparently caps lock still sends caps lock signal

    while (!WindowShouldClose()) {
        double rangle = convertToRadian(random() % 180);
        Angle angle = {rangle, sin(rangle), cos(rangle), tan(rangle)};
        animatedLine(random() % windowWidth, angle, random() % 95, 1, randomColor());
    }

    CloseWindow();
    return 0;
}
