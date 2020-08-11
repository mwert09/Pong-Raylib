#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

/* Type definition for player */
typedef struct {
	Vector2 position;
	int width;
	int height;
	Color color;
	float speed;
	Rectangle playerRect;
}Player;

/* Player 1 */
extern Player player1;

/* Function to create player */
Player CreatePlayer(int x, int y, int width, int height, Color color, float speed);
/* Function to draw player */
void DrawPlayer(Player* player);



#endif