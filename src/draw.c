#include "../headers/window.h"

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
		*sideDistX = (player->posX - (int) player->posX) / fabs(*rayDirX);
	}
	else
	{
		*stepX = 1;
		*sideDistX = ((int) player->posX + 1.0 - player->posX) / fabs(*rayDirX);
	}
	if (*rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (player->posY - (int) player->posY) / fabs(*rayDirY);
	}
	else
	{
		*stepY = 1;
		*sideDistY = ((int) player->posY + 1.0 - player->posY) / fabs(*rayDirY);
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
	double perpWallDist, wallHeight, wallX;
	int drawStart, drawEnd, texNum, texX, texY, d;
	key r, g, b;
	color color;

	if (side == 0)
		perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;
	wallHeight = SCREEN_HEIGHT / perpWallDist;
	drawStart = -wallHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = wallHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
	texNum = worldMap[mapX][mapY] - 1;
	if (side == 0)
		wallX = player->posY + perpWallDist * rayDirY;
	else
		wallX = player->posX + perpWallDist * rayDirX;
	wallX -= floor(wallX);
	texX = (int) (wallX * (double) TEX_WIDTH);
	if (side == 0 && rayDirX > 0)
		texX = TEX_WIDTH - texX - 1;
	if (side == 1 && rayDirY < 0)
		texX = TEX_WIDTH - texX - 1;
	for (int y = drawStart; y < drawEnd; y++)
	{
		d = y * 256 - SCREEN_HEIGHT * 128 + wallHeight * 128;
		texY = ((d * TEX_HEIGHT) / wallHeight) / 256;
		color = instance->textures[texNum][TEX_HEIGHT * texY + texX];
		if (side == 1)
			color = (color >> 1) & 8355711;
		r = (color >> 16) & 0xFF;
		g = (color >> 8) & 0xFF;
		b = color & 0xFF;
		SDL_SetRenderDrawColor(instance->renderer, r, g, b, 255);
		SDL_RenderDrawPoint(instance->renderer, x, y);
	}
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
