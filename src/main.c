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
	color lastTime = SDL_GetTicks();
	color currentTime;
	double frameTime;
	Player *player;

	if (init(&instance) != 0)
	{
		fprintf(stderr, "Failed to initialize SDL\n");
		return (1);
	}

	parseMap();
	player = createPlayer(22.0, 11.5, -1.0, 0.0, 0.0, 0.66);
	if (player == NULL)
	{
		fprintf(stderr, "Failed to create player\n");
		destroy(&instance);
		return (1);
	}

	while (!quit)
	{

		while (SDL_PollEvent(&event))
		{
			handleEvents(event);
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_SLASH)
				{
					player->mapEnabled = !player->mapEnabled;
				}
			}
		}
		currentTime = SDL_GetTicks();
		frameTime = (currentTime - lastTime) / 1000.0;
		lastTime = currentTime;
        updatePlayerPosition(player, frameTime);
        updatePlayerRotation(player, frameTime);

		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
		SDL_RenderClear(instance.renderer);

		render(&instance, player);

		drawMap(&instance, *player);

		SDL_RenderPresent(instance.renderer);
	}

	destroyPlayer(player);
	destroy(&instance);

	return (0);
}
