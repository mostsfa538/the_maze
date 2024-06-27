#include "../headers/player.h"
#include "../headers/window.h"

/**
 * handleEvents - Handles events.
 * @event: The event to handle.
 * @player: A pointer to the player structure.
 * @quit: A pointer to the quit flag.
 * @instance: A pointer to the SDL_Instance structure.
 * @isFullscreen: A pointer to the fullscreen flag.
 */
void handleKeyEvent(SDL_Event event, Player *player, bool *quit,
					SDL_Instance *instance, bool *isFullscreen)
{
	if (event.key.keysym.sym == SDLK_SLASH)
	{
		player->mapEnabled = !player->mapEnabled;
	}
	else if (event.key.keysym.sym == SDLK_ESCAPE)
	{
		*quit = true;
	}
	else if (event.key.keysym.sym == SDLK_f)
	{
		if (*isFullscreen)
		{
			SDL_SetWindowFullscreen(instance->window, 0);
			SCREEN_WIDTH = 800;
			SCREEN_HEIGHT = 600;
			SDL_SetWindowSize(instance->window, SCREEN_WIDTH, SCREEN_HEIGHT);
			*isFullscreen = false;
		}
		else
		{
			SDL_SetWindowFullscreen(instance->window,
									SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_DisplayMode displayMode;

			SDL_GetCurrentDisplayMode(0, &displayMode);
			SCREEN_WIDTH = displayMode.w;
			SCREEN_HEIGHT = displayMode.h;
			SDL_SetWindowSize(instance->window, SCREEN_WIDTH, SCREEN_HEIGHT);
			*isFullscreen = true;
		}

		int width, height;

		SDL_GetWindowSize(instance->window, &width, &height);
		SDL_RenderSetLogicalSize(instance->renderer, width, height);
	}
}

/**
 * handleWindowEvent - Handles window events.
 * @event: The SDL_Event to handle.
 * @instance: A pointer to the SDL_Instance structure.
 */
void handleWindowEvent(SDL_Event event, SDL_Instance *instance)
{
	if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		int width, height;

		SDL_GetWindowSize(instance->window, &width, &height);
		SDL_RenderSetLogicalSize(instance->renderer, width, height);
	}
}

/**
 * handleGameEvents - Handles game events.
 * @event: The event to handle.
 * @player: A pointer to the player structure.
 * @quit: A pointer to the quit flag.
 * @instance: A pointer to the SDL_Instance structure.
 * @isFullscreen: A pointer to the fullscreen flag.
 */
void handleGameEvents(SDL_Event event, Player *player, bool *quit,
					  SDL_Instance *instance, bool *isFullscreen)
{
	while (SDL_PollEvent(&event))
	{
		handleEvents(event);
		if (event.type == SDL_KEYDOWN)
		{
			handleKeyEvent(event, player, quit, instance, isFullscreen);
		}
		else if (event.type == SDL_WINDOWEVENT)
		{
			handleWindowEvent(event, instance);
		}
	}
}
