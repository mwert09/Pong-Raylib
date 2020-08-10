#include <raylib.h>
#include "Player.h"


/* WINDOW */
const int WindowWidth = 1920;
const int WindowHeight = 1080;


/*
----------- 1 - Single Player ---------------
----------- 2 - 2 Player Local Multiplayer --
----------- 3 - Online maybe later ----------
*/
int game_mode = 1;

void HandleInput(void);

int main() {
	

	InitWindow(WindowWidth, WindowHeight, "Deneme");

	SetTargetFPS(60);
	ToggleFullscreen();

	/* Player1 */
	Vector2 Player1Pos = {
			10,
			440
	};
	Player player1 = {
		.position = Player1Pos,
		.width = 20,
		.height = 200,
		.color = WHITE,
		.speed = 10
	};
	Rectangle playerRect = {
		.x = player1.position.x,
		.y = player1.position.y,
		.width = player1.width,
		.height = player1.height
	};
	player1.playerRect = playerRect;

	
	while (!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PONG", WindowWidth/2, 0, 20, WHITE);

		HandleInput(&player1);
		DrawPlayer(&player1);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


void HandleInput(Player *player) {
	if (game_mode == 1) {
		if (IsKeyDown(KEY_S)) {
			if (player->playerRect.y <= WindowHeight - 200) {
				player->playerRect.y += player->speed;
			}
		} // S

		if (IsKeyDown(KEY_W)) {
			if (player->playerRect.y <= WindowHeight && player->playerRect.y > 0) {
				player->playerRect.y -= player->speed;
			}
		} // W
		
	} // game mode
}
