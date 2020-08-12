#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "Player.h"

/* Type definition for ball */
typedef struct {
	Vector2 BallPosition;
	float radius;
	Color color;
	float speed;
	int x_mov;
	int y_mov;
}Ball;


/*Function to create the ball */
Ball CreateBall(int x, int y, float radius, Color color, float speed);

/* Function to draw ball */
void DrawBall(Ball* ball);

/* Function to handle ball movement */
void HandleBallMovementAndCollision(Ball* ball, Rectangle LeftRacket, Rectangle RightRacket, Rectangle LeftWall, Rectangle RightWall, Rectangle UpWall, Rectangle DownWall, Player* player1, Player* player2, Sound* hitSound);

#endif