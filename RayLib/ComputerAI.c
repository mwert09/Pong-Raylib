#include "ComputerAI.h"



void HandleAIMovement(Player* ai_player, Ball* ball)
{
	if (ball->x_mov >= 1) {
		if (ball->BallPosition.y < ai_player->playerRect.y && ai_player->playerRect.y <= GetScreenHeight() && ai_player->playerRect.y > 0) {
			ai_player->playerRect.y -= ai_player->speed;
		}
		if (ball->BallPosition.y > ai_player->playerRect.y&& ai_player->playerRect.y <= GetScreenHeight() - 200) {
			ai_player->playerRect.y += ai_player->speed;
		}
	}
}