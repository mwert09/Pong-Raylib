#include <raylib.h>
#include "Player.h"
#include "Input.h"
#include "EnvironmentItem.h"


/* WINDOW */
const int WindowWidth = 1920;
const int WindowHeight = 1080;


/*
----------- 1 - Single Player ---------------
----------- 2 - 2 Player Local Multiplayer --
----------- 3 - Online maybe later ----------
*/
int game_mode = 1;

/* DIFFICULTY ------ Basically adjusts speed in single player game mode  I WILL IMPLEMENT THIS LATER */
float easy = 5.f;
float normal = 10.f;
float hard = 15.f;



int main() {
	
	// Initialize window
	InitWindow(WindowWidth, WindowHeight, "Deneme");

	// Limit Fps
	SetTargetFPS(60);
	// Make it fullscreen
	ToggleFullscreen();

	/* Player1 */
	Player player1 = CreatePlayer(10, 440, 20, 200, WHITE, 10.f);

	/* Player2 or AI */
	Player player2 = CreatePlayer(1890, 440, 20, 200, WHITE, 10.f);

	/* Environment */
	EnvItem envItems[] = {
		/* Middle */
		{{GetScreenWidth() / 2, 30, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 138, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 246, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 354, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 462, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 570, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 678, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 786, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 894, 7, 50}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 1002, 7, 50}, false, DARKGRAY},

		/* Left */
		{{0, 0, 3, GetScreenHeight()}, true, WHITE},

		/* Right*/
		{{GetScreenWidth() - 6, 0, 3, GetScreenHeight()}, true, WHITE},

		/* Top */
		{{0, 0, GetScreenWidth(), 3}, true, WHITE},

		/* Bottom */
		{{0, GetScreenHeight() - 6, GetScreenWidth(), 3}, true, WHITE}
	};

	/* Get envItems array length */
	int envItemsLength = sizeof(envItems) / (sizeof(envItems[0]));
	
	while (!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PONG", WindowWidth/2 - 20, 0, 20, WHITE);

		/* Update position and draw*/
		HandleInput(&player1, game_mode, GetScreenWidth(), GetScreenHeight());
		DrawPlayer(&player1);

		DrawEnvironment(envItems, envItemsLength);

		/* Check if it is single player */
		if (game_mode == 1) {
			DrawPlayer(&player2);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


