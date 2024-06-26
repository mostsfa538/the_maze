#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "player.h"
#include <stdbool.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define mapWidth 24
#define mapHeight 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define NUM_TEXTURES 5

typedef Uint32 color;
typedef Uint8 key;

extern int worldMap[mapWidth][mapHeight];

/**
 * struct SDL_Instance - A structure to hold the SDL window and renderer.
 * @window: A pointer to the SDL_Window structure.
 * @renderer: A pointer to the SDL_Renderer structure.
 * @textures: An array of pointers to the textures.
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	color * textures[NUM_TEXTURES];
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

void parseMap(void);
void drawMap(SDL_Instance *instance, Player player);
void drawPlayerDirection(SDL_Instance *instance, Player *player);
bool enableMap(Player *player);
color *loadTexture(const char *file);
int initTextures(SDL_Instance *instance);
void destroyTexture(SDL_Instance *instance);
void routeMap(void);
#endif