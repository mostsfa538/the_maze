#include "../headers/player.h"
#include "../headers/window.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
/**
 * main - The entry point of the program.
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	SDL_Instance instance;
	bool quit = false;
	bool isFullscreen = false;
	SDL_Event event;
	Player *player;
	double frameTime;
	Uint32 lastTime = SDL_GetTicks();

	player = initializePlayer();

	if (initGame(&instance) != 0)
		return (1);

	parseMap();

	SDL_SetWindowSize(instance.window, SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_RenderSetLogicalSize(instance.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	while (!quit)
	{
		handleGameEvents(event, player, &quit, &instance, &isFullscreen);
		frameTime = updateFrameTime(&lastTime);
		updatePlayerState(player, frameTime);
		renderFrame(&instance, player);
	}

	cleanUp(&instance, player);

	return (0);
}
