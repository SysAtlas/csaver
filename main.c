#include "csaver.h"
#include "csaverutil.h"
#include "raylib/src/raylib.h"

const int windowWidth = 800;
const int windowHeight = 800;

double angleInput = 15.0f;	
int offset = 200;
int length = 50;


int main(int argc, char* argv[]) {
    srandom(0xCA10ED);

    InitWindow(windowWidth, windowHeight, "CSaver");
    SetExitKey(KEY_CAPS_LOCK); // Apparently caps lock still sends caps lock signal

    while (!WindowShouldClose()) {
	Angle angle = generateAngle(random() % 180);
        animatedLine(400, angle, 20, 5, randomColor(), randomSide());
    }

    CloseWindow();
    return 0;
}
