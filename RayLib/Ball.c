#pragma warning(disable : 4996)
#include "Ball.h"

/* Function to create ball */
Ball CreateBall(int x, int y, float radius, Color color, float speed)
{
	Vector2 ballPos = { x, y };
	Ball ball = {
		.BallPosition = ballPos,
		.radius = radius,
		.color = color,
		.speed = speed,
		.x_mov = 1,
		.y_mov = 1
	};
	return ball;
}

/* Function to draw ball */
void DrawBall(Ball* ball) 
{
	DrawCircleV(ball->BallPosition, ball->radius, ball->color);
}

/* Function to handle ball movement and collision */
void HandleBallMovementAndCollision(Ball* ball, Rectangle LeftRacket, Rectangle RightRacket, Rectangle LeftWall, Rectangle RightWall, Rectangle UpWall, Rectangle DownWall, Player* player1, Player* player2, Sound* hitSound)
{

	if (CheckCollisionCircleRec(ball->BallPosition, ball->radius, LeftRacket) || CheckCollisionCircleRec(ball->BallPosition, ball->radius, RightRacket)) {
		ball->x_mov *= -1;
		ball->speed++;
		PlaySound(*hitSound);
	}
	else {
		if (CheckCollisionCircleRec(ball->BallPosition, ball->radius, UpWall) || CheckCollisionCircleRec(ball->BallPosition, ball->radius, DownWall)) {
			ball->y_mov *= -1;
			ball->speed++;
		}
		else {
			if (ball->BallPosition.x <= 0) {
				player2->score++;
				player2->scored = 1;
				ball->BallPosition.x = GetScreenWidth() / 2;
				ball->BallPosition.y = GetScreenHeight() / 2;
				ball->speed = 4;
			}
			else if (ball->BallPosition.x >= GetScreenWidth()) {
				player1->score++;
				player1->scored = 1;
				ball->BallPosition.x = GetScreenWidth() / 2;
				ball->BallPosition.y = GetScreenHeight() / 2;
				ball->speed = 4;
			}
		}
	}
	ball->BallPosition.x += ball->speed * ball->x_mov;
	ball->BallPosition.y += ball->speed * ball->y_mov;
}