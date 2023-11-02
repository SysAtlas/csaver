#include <getopt.h>
#include <unistd.h>
#include "csaver.h"

const int windowWidth = 800;
const int windowHeight = 800;

int main() {

    srandom(69);

    InitWindow(windowWidth, windowHeight, "Lines");
    SetExitKey(KEY_CAPS_LOCK); // Apparently caps lock still sends caps lock signal

    while (!WindowShouldClose()) {
        
        BeginDrawing();

        randomBotLine();
        usleep(10000);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}
