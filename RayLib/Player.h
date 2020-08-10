#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
	Vector2 position;
	int width;
	int height;
	Color color;
	float speed;
	Rectangle playerRect;
}Player;

extern Player player1;


void DrawPlayer(Player* player);



#endif