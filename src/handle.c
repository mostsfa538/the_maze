#include "../headers/player.h"
#include "../headers/window.h"

/**
 * handleGameEvents - Handles game events.
 * @event: The event to handle.
 * @player: A pointer to the player structure.
 * @quit: A pointer to the quit flag.
 */
void handleGameEvents(SDL_Event event, Player *player, bool *quit)
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
			else if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				*quit = true;
			}
		}
	}
}

/**
 * updateFrameTime - Updates the frame time.
 * @lastTime: A pointer to the last time.
 * Return: The frame time.
 */
double updateFrameTime(Uint32 *lastTime)
{
	Uint32 currentTime = SDL_GetTicks();
	double frameTime = (currentTime - *lastTime) / 1000.0;

	*lastTime = currentTime;
	return (frameTime);
}

/**
 * updatePlayerState - Updates the player's state.
 * @player: A pointer to the player structure.
 * @frameTime: The frame time.
 */
void updatePlayerState(Player *player, double frameTime)
{
	updatePlayerPosition(player, frameTime);
	updatePlayerRotation(player, frameTime);
}

/**
 * renderFrame - Renders the frame.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void renderFrame(SDL_Instance *instance, Player *player)
{
	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
	SDL_RenderClear(instance->renderer);

	render(instance, player);

	drawMap(instance, *player);

	SDL_RenderPresent(instance->renderer);
}
