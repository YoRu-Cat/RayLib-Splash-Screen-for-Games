#include "raylib.h"
#include "YoRuSplScr.h"

using namespace std;
int main()
{
	// Initialization
	int displayWidth = GetMonitorWidth(0);
	int displayHeight = GetMonitorHeight(0);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_FULLSCREEN_MODE | FLAG_VSYNC_HINT);
	InitWindow(displayWidth, displayHeight, "YoRu Screen");
	SetTargetFPS(60);

	SplashScreen splash("resources/YoRu_n.gif", 10, 6.0f, 10.0f);

	// Main game loop
	while (!WindowShouldClose())
	{
		// Update splash screen
		if (splash.Update(GetFrameTime()))
		{
			splash.Reset(); // Reset splash screen when complete
		}

		BeginDrawing();
		ClearBackground(BLACK);
		// Draw the appropriate screen
		if (!splash.IsComplete())
		{
			splash.Draw();
		}
		else
		{
			// Whatever you want to do after the splash screen
			// For example, you can draw a message or load the main game
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
