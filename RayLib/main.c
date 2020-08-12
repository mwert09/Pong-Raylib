#pragma warning(disable : 4996)
#include <raylib.h>
#include "Player.h"
#include "Input.h"
#include "EnvironmentItem.h"
#include "Ball.h"

/* TODO: 
			AI or Player2 Movement (First AI)
			Bug Fix
			Menus
			Publish itch io
			Github
*/


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

	/* Ball */
	Ball ball = CreateBall(GetScreenWidth() / 2, GetScreenHeight() / 2, 15, WHITE, 4.0f);

	/* Environment */
	EnvItem envItems[] = {
		/* Middle */
		{{GetScreenWidth() / 2, 30, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 138, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 246, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 354, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 462, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 570, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 678, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 786, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 894, 7, 30}, false, DARKGRAY},
		{{GetScreenWidth() / 2, 1002, 7, 30}, false, DARKGRAY},

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
		DrawText(FormatText("Player1 Score: %d", player1.score), GetScreenWidth() / 2 - 400, 30, 20, WHITE);
		DrawText(FormatText("Player2 Score: %d", player2.score), GetScreenWidth() / 2 + 400, 30, 20, WHITE);
		DrawText(FormatText("Ball Speed: %f", ball.speed), GetScreenWidth() / 2 - 80, GetScreenHeight() - 50, 20, WHITE);
		
		/* Update position and draw*/
		HandleInput(&player1, game_mode, GetScreenWidth(), GetScreenHeight());
		DrawPlayer(&player1);

		DrawPlayer(&player2);

		DrawEnvironment(envItems, envItemsLength);

		HandleBallMovementAndCollision(&ball, player1.playerRect, player2.playerRect, envItems[10].rect, envItems[11].rect, envItems[12].rect, envItems[13].rect, &player1, &player2);;
		DrawBall(&ball);

		if (player1.scored == 1) {
			DrawText("Player1 Scored!", GetScreenWidth() / 2 - 400, 100, 20, WHITE);
			player2.scored = 0;
			/*player1.scored = 0;*/
		}
		else if (player2.scored == 1) {
			DrawText("Player2 Scored!", GetScreenWidth() / 2 + 400, 100, 20, WHITE);
			player1.scored = 0;
			/*player2.scored = 0;*/
		}
			
		

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


