#include "Input.h"
#include "Player.h"


void HandleInput(Player* player, int game_mode, int WindowWidth, int WindowHeight) {
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
