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
 * initializePlayer - Initializes a player structure with default values.
 * Return: A pointer to the new player structure.
 */
Player *initializePlayer()
{
	Player *player = createPlayer(22.0, 11.5, -1.0, 0.0, 0.0, 0.66);

	if (player == NULL)
	{
		fprintf(stderr, "Failed to create player\n");
		exit(1);
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
