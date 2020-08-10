#include "Player.h"

Player player1;

void DrawPlayer(Player *player) {
	DrawRectangleRec(player->playerRect, WHITE);
}