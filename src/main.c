#include "../headers/player.h"
#include "../headers/window.h"

/**
 * main - The entry point of the program.
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	SDL_Instance instance;
	bool quit = false;
	SDL_Event event;
	Player *player;
	double frameTime;
	Uint32 lastTime = SDL_GetTicks();

	player = initializePlayer();

	if (initGame(&instance) != 0)
		return (1);

	parseMap();

	while (!quit)
	{
		handleGameEvents(event, player, &quit);
		frameTime = updateFrameTime(&lastTime);
		updatePlayerState(player, frameTime);
		renderFrame(&instance, player);
	}

	cleanUp(&instance, player);

	return (0);
}
