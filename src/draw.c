#include "../headers/window.h"


int worldMap[mapWidth][mapHeight] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


/**
 * calculateRayDirectionAndStep - Calculates the ray direction and step.
 * @x: The x coordinate of the screen.
 * @rayDirX: A pointer to the ray direction x.
 * @rayDirY: A pointer to the ray direction y.
 * @stepX: A pointer to the step x.
 * @stepY: A pointer to the step y.
 * @sideDistX: A pointer to the side distance x.
 * @sideDistY: A pointer to the side distance y.
 * @player: A pointer to the player structure.
 */
void calculateRayDirectionAndStep(int x, double *rayDirX, double *rayDirY,
								  int *stepX, int *stepY, double *sideDistX,
								  double *sideDistY, Player *player)
{
	double cameraX = 2 * x / (double) SCREEN_WIDTH - 1;

	*rayDirX = player->dirX + player->planeX * cameraX;
	*rayDirY = player->dirY + player->planeY * cameraX;

	if (*rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (player->posX - (int) player->posX) / *rayDirX;
	}
	else
	{
		*stepX = 1;
		*sideDistX = ((int) player->posX + 1.0 - player->posX) / *rayDirX;
	}
	if (*rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (player->posY - (int) player->posY) / *rayDirY;
	}
	else
	{
		*stepY = 1;
		*sideDistY = ((int) player->posY + 1.0 - player->posY) / *rayDirY;
	}
}

/**
 * performDDA - Performs the DDA algorithm to calculate the distance to the
 * wall.
 * @mapX: A pointer to the map x coordinate.
 * @mapY: A pointer to the map y coordinate.
 * @stepX: A pointer to the step x.
 * @stepY: A pointer to the step y.
 * @sideDistX: A pointer to the side distance x.
 * @sideDistY: A pointer to the side distance y.
 * @deltaDistX: A pointer to the delta distance x.
 * @deltaDistY: A pointer to the delta distance y.
 *
 * Return: The side of the wall hit.
 */

int performDDA(int *mapX, int *mapY, int *stepX, int *stepY, double *sideDistX,
			   double *sideDistY, double *deltaDistX, double *deltaDistY)
{
	int hit = 0, side;

	while (hit == 0)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += *deltaDistX;
			*mapX += *stepX;
			side = 0;
		}
		else
		{
			*sideDistY += *deltaDistY;
			*mapY += *stepY;
			side = 1;
		}
		if (worldMap[*mapX][*mapY] > 0)
			hit = 1;
	}

	return (side);
}

/**
 * calculateLineHeightAndDraw - Calculates the line height and draws the wall.
 * @x: The x coordinate of the screen.
 * @side: The side of the wall hit.
 * @mapX: The map x coordinate.
 * @mapY: The map y coordinate.
 * @rayDirX: The ray direction x.
 * @rayDirY: The ray direction y.
 * @stepX: The step x.
 * @stepY: The step y.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void calculateLineHeightAndDraw(int x, int side, int mapX, int mapY,
								double rayDirX, double rayDirY, int stepX,
								int stepY, SDL_Instance *instance,
								Player *player)
{
	double perpWallDist;
	int lineHeight, drawStart, drawEnd;

	if (side == 0)
		perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;

	lineHeight = (int) (SCREEN_HEIGHT / perpWallDist);
	drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;

	if (drawStart < 0)
		drawStart = 0;

	drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;

    SDL_SetRenderDrawColor(instance->renderer, 135, 206, 250, 255); // Sky blue color
    SDL_RenderDrawLine(instance->renderer, x, 0, x, drawStart);
    
    SDL_SetRenderDrawColor(instance->renderer, 139, 69, 19, 255); // Brown color
    SDL_RenderDrawLine(instance->renderer, x, drawEnd, x, SCREEN_HEIGHT - 1);
    
    if (worldMap[mapX][mapY] == 1)
        SDL_SetRenderDrawColor(instance->renderer, 0, 255, 0, 255); // Green color for walls
    else
        SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255); // Black color for empty space
    
    // Render walls
    SDL_RenderDrawLine(instance->renderer, x, drawStart, x, drawEnd);
}

/**
 * render - Renders the walls to the screen.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void render(SDL_Instance *instance, Player *player)
{
	int side;
	int mapX, mapY;
	int stepX, stepY;
	double rayDirX, rayDirY, sideDistX, sideDistY;
	double deltaDistX, deltaDistY;

	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		mapX = (int) player->posX;
		mapY = (int) player->posY;


		calculateRayDirectionAndStep(x, &rayDirX, &rayDirY, &stepX, &stepY,
									 &sideDistX, &sideDistY, player);

		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);

		side = performDDA(&mapX, &mapY, &stepX, &stepY, &sideDistX, &sideDistY,
						  &deltaDistX, &deltaDistY);

		calculateLineHeightAndDraw(x, side, mapX, mapY, rayDirX, rayDirY, stepX,
								   stepY, instance, player);
	}
}