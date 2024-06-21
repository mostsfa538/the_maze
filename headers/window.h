#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define mapWidth 24
#define mapHeight 24

extern int worldMap[mapWidth][mapHeight];

/**
 * struct SDL_Instance - A structure to hold the SDL window and renderer.
 * @window: A pointer to the SDL_Window structure.
 * @renderer: A pointer to the SDL_Renderer structure.
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init(SDL_Instance *instance);
void destroy(SDL_Instance *instance);
void handleEvents(SDL_Event event);
void calculateRayDirectionAndStep(int x, double *rayDirX, double *rayDirY,
								  int *stepX, int *stepY, double *sideDistX,
								  double *sideDistY, Player *player);
int performDDA(int *mapX, int *mapY, int *stepX, int *stepY, double *sideDistX,
			   double *sideDistY, double *deltaDistX, double *deltaDistY);
void calculateLineHeightAndDraw(int x, int side, int mapX, int mapY,
								double rayDirX, double rayDirY, int stepX,
								int stepY, SDL_Instance *instance,
								Player *player);
void render(SDL_Instance *instance, Player *player);

#endif
