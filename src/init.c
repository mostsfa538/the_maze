#include "../headers/player.h"
#include "../headers/window.h"

/**
 * initGame - Initializes the game.
 * @instance: A pointer to the SDL_Instance structure.
 * Return: 0 on success, 1 on failure.
 */
int initGame(SDL_Instance *instance)
{
	if (init(instance) != 0)
	{
		fprintf(stderr, "Failed to initialize SDL\n");
		return (1);
	}
	return (0);
}

/**
 * cleanUp - Cleans up the game.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void cleanUp(SDL_Instance *instance, Player *player)
{
	destroyPlayer(player);
	destroy(instance);
	destroyTexture(instance);
}
