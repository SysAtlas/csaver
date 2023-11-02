#include "csaver.h"
#include "raylib/src/raylib.h"
#include <stdlib.h>
#include <unistd.h>

const int windowWidth = 800;
const int windowHeight = 800;

double angle = 30.0f;	
int offset = 0;
int length = 200;

int main(int argc, char* argv[]) {
	srandom(420);
	angle = convertToRadian(angle);
	
	InitWindow(windowWidth, windowHeight, "CSaver");
	SetExitKey(KEY_CAPS_LOCK); // Apparently caps lock still sends caps lock signal

	while (!WindowShouldClose()) {
            animatedLine(random() % 400, convertToRadian(random() % 90), 300, 1, random() % 500, randomColor());
	}

	CloseWindow();
	return 0;
}
