#include "../headers/window.h"

/**
 * init - Initializes the SDL instance with a window and renderer.
 * @instance: A pointer to an SDL_Instance structure.
 *
 * Return: 0 on success, 1 on failure.
 */
int init(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	instance->window = SDL_CreateWindow("The Maze", SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
										SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
											SDL_RENDERER_ACCELERATED |
												SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	return (0);
}

/**
 * destroy - Destroys the SDL window and renderer.
 * @instance: A pointer to an SDL_Instance structure.
 */
void destroy(SDL_Instance *instance)
{
	SDL_DestroyRenderer(instance->renderer);
	SDL_DestroyWindow(instance->window);
	SDL_Quit();
}

/**
 * handleEvents - Handles SDL events.
 * @event: The SDL event to handle.
 */

void handleEvents(SDL_Event event)
{
    if (event.type == SDL_QUIT)
    {
        SDL_Quit();
        exit(0);
    }
}