#include "Player.h"


Player CreatePlayer(int x, int y, int width, int height, Color color, float speed) {
	Vector2 PlayerPos = {
			x,
			y
	};
	Player player = {
		.position = PlayerPos,
		.width = width,
		.height = height,
		.color = color,
		.speed = speed,
		.score = 0,
		.scored = 0
	};
	Rectangle player1Rect = {
		.x = player.position.x,
		.y = player.position.y,
		.width = player.width,
		.height = player.height
	};
	player.playerRect = player1Rect;

	return player;
}

void DrawPlayer(Player *player) {
	DrawRectangleRec(player->playerRect, WHITE);
}