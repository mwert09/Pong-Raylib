#include <raylib.h>
#include "Player.h"
#include "Input.h"


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
	Player player2 = CreatePlayer(1900, 440, 20, 200, WHITE, 10.f);
	
	
	while (!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PONG", WindowWidth/2, 0, 20, WHITE);

		/* Update position and draw*/
		HandleInput(&player1, game_mode, GetScreenWidth(), GetScreenHeight());
		DrawPlayer(&player1);

		/* Check if it is single player */
		if (game_mode == 1) {
			DrawPlayer(&player2);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


