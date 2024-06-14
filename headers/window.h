#ifndef _WENDOW_H
#define _WENDOW_H

#include "SDL2/SDL.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/**
 * struct SDL_Instance - A structure to hold the SDL window and renderer.
 * @window: A pointer to the SDL_Window structure.
 * @renderer: A pointer to the SDL_Renderer structure.
 *
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init(SDL_Instance *);
void destroy(SDL_Instance *instance);
