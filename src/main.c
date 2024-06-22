#include "../headers/player.h"
#include "../headers/window.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	SDL_Instance instance;
	if (init(&instance) != 0)
	{
		fprintf(stderr, "Failed to initialize SDL\n");
		return 1;
	}

	// Create the player instance
	parseMap();
	Player *player = createPlayer(22.0, 11.5, -1.0, 0.0, 0.0, 0.66);
	if (player == NULL)
	{
		fprintf(stderr, "Failed to create player\n");
		destroy(&instance);
		return 1;
	}

	bool quit = false;
	// parseMap();
	SDL_Event event;
	Uint32 lastTime = SDL_GetTicks();

	while (!quit)
	{

		while (SDL_PollEvent(&event))
		{
			handleEvents(event);
		}

		Uint32 currentTime = SDL_GetTicks();
		double frameTime = (currentTime - lastTime) / 1000.0;
		lastTime = currentTime;

		updatePlayerDirection(player, frameTime);

		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255); // Clear screen
		SDL_RenderClear(instance.renderer);

		render(&instance, player); // Render the 3D scene

		drawMap(&instance, *player); // Render the 2D map

		SDL_RenderPresent(instance.renderer); // Update screen
	}

	// Clean up
	destroyPlayer(player);
	destroy(&instance);

	return 0;
}
