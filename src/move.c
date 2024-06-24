#include "../headers/player.h"
#include "../headers/window.h"

/**
 * updatePlayerPosition - Updates the player's position.
 * @player: A pointer to the player structure to update.
 * @frameTime: The time elapsed since the last frame.
 */
void updatePlayerPosition(Player *player, double frameTime)
{
	double moveSpeed = frameTime * 5.0;
	double oldX, oldY;
	const key *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_W])
	{
		if (worldMap[(int) (player->posX + player->dirX * moveSpeed)]
					[(int) player->posY] == 0)
			player->posX += player->dirX * moveSpeed;
		if (worldMap[(int) player->posX]
					[(int) (player->posY + player->dirY * moveSpeed)] == 0)
			player->posY += player->dirY * moveSpeed;
	}
	if (state[SDL_SCANCODE_S])
	{
		if (worldMap[(int) (player->posX - player->dirX * moveSpeed)]
					[(int) player->posY] == 0)
			player->posX -= player->dirX * moveSpeed;
		if (worldMap[(int) player->posX]
					[(int) (player->posY - player->dirY * moveSpeed)] == 0)
			player->posY -= player->dirY * moveSpeed;
	}
	oldX = player->posX;
	oldY = player->posY;

	if (worldMap[(int) player->posX][(int) player->posY] != 0)
	{
		player->posX = oldX;
		player->posY = oldY;
	}
}

/**
 * updatePlayerRotation - Updates the player's direction.
 * @player: A pointer to the player structure to update.
 * @frameTime: The time elapsed since the last frame.
 */
void updatePlayerRotation(Player *player, double frameTime)
{
	double rotSpeed = frameTime * 3.0;
	double oldDirX, oldPlaneX;
	double oldX, oldY;
	const key *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_D])
	{
		oldDirX = player->dirX;
		player->dirX =
			player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
		player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
		oldPlaneX = player->planeX;
		player->planeX =
			player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
		player->planeY =
			oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
	}
	if (state[SDL_SCANCODE_A])
	{
		oldDirX = player->dirX;
		player->dirX =
			player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
		player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
		oldPlaneX = player->planeX;
		player->planeX =
			player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
		player->planeY =
			oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
	}
	oldX = player->posX;
	oldY = player->posY;

	if (worldMap[(int) player->posX][(int) player->posY] != 0)
	{
		player->posX = oldX;
		player->posY = oldY;
	}
}
