#include "../headers/player.h"

/**
 * createPlayer - Creates a new player structure.
 * @posX: The player's x position.
 * @posY: The player's y position.
 * @dirX: The player's x direction.
 * @dirY: The player's y direction.
 * @planeX: The player's x plane.
 * @planeY: The player's y plane.
 *
 * Return: A pointer to the new player structure.
 */
Player *createPlayer(double posX, double posY, double dirX, double dirY,
					 double planeX, double planeY)
{
	Player *player = (Player *) malloc(sizeof(Player));

	if (player != NULL)
	{
		player->posX = posX;
		player->posY = posY;
		player->dirX = dirX;
		player->dirY = dirY;
		player->planeX = planeX;
		player->planeY = planeY;
	}
	return (player);
}

/**
 * destroyPlayer - Frees the memory allocated for a player structure.
 * @player: A pointer to the player structure to free.
 */
void destroyPlayer(Player *player)
{
	if (player != NULL)
	{
		free(player);
	}
}

/**
 * updatePlayerPosition - Updates the player's position.
 * @player: A pointer to the player structure to update.
 * @newPosX: The new x position for the player.
 * @newPosY: The new y position for the player.
 */
void updatePlayerPosition(Player *player, double newPosX, double newPosY)
{
	if (player != NULL)
	{
		player->posX = newPosX;
		player->posY = newPosY;
	}
}
