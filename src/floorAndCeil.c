#include "../headers/window.h"
#include "../headers/player.h"

/**
 * drawFloor - Draws the floor to the screen.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void drawFloor(SDL_Instance *instance, Player *player)
{
	int yStep = 2;
	int xStep = 2;
	double rayDirX0, rayDirX1, rayDirY0, rayDirY1, posZ, rowDistance,
		floorStepX, floorStepY, floorX, floorY;
	int p, cellX, cellY, texX, texY;
	color floorColor;
	Uint8 r, g, b;

	for (int y = 0; y < SCREEN_HEIGHT / 2; y += yStep)
	{
		rayDirX0 = player->dirX - player->planeX;
		rayDirX1 = player->dirX + player->planeX;
		rayDirY0 = player->dirY - player->planeY;
		rayDirY1 = player->dirY + player->planeY;
		p = y - SCREEN_HEIGHT / 2;
		posZ = 0.5 * SCREEN_HEIGHT;
		rowDistance = posZ / p;
		floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
		floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;
		floorX = player->posX + rowDistance * rayDirX0;
		floorY = player->posY + rowDistance * rayDirY0;

		for (int x = 0; x < SCREEN_WIDTH; x += xStep)
		{
			cellX = (int) (floorX);
			cellY = (int) (floorY);
			texX = (int) (TEX_WIDTH * (floorX - cellX)) & (TEX_WIDTH - 1);
			texY = (int) (TEX_HEIGHT * (floorY - cellY)) & (TEX_HEIGHT - 1);
			floorX += floorStepX * xStep;
			floorY += floorStepY * xStep;
			floorColor = instance->floorTexture[TEX_WIDTH * texY + texX];
			r = (floorColor >> 16) & 0xFF;
			g = (floorColor >> 8) & 0xFF;
			b = floorColor & 0xFF;
			SDL_SetRenderDrawColor(instance->renderer, r, g, b, 255);
			SDL_RenderDrawPoint(instance->renderer, x, SCREEN_HEIGHT - y - 1);
		}
	}
}

/**
 * drawCeiling - Draws the ceiling to the screen.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: A pointer to the player structure.
 */
void drawCeiling(SDL_Instance *instance, Player *player)
{
	int yStep = 2;
	int xStep = 2;
	double rayDirX0, rayDirX1, rayDirY0, rayDirY1, posZ, rowDistance,
		ceilingStepX, ceilingStepY, ceilingX, ceilingY;
	int p, cellX, cellY, texX, texY;
	color ceilingColor;
	Uint8 r, g, b;

	for (int y = 0; y < SCREEN_HEIGHT / 2; y += yStep)
	{
		rayDirX0 = player->dirX - player->planeX;
		rayDirX1 = player->dirX + player->planeX;
		rayDirY0 = player->dirY - player->planeY;
		rayDirY1 = player->dirY + player->planeY;
		p = y - SCREEN_HEIGHT / 2;
		posZ = 0.5 * SCREEN_HEIGHT;
		rowDistance = posZ / p;
		ceilingStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
		ceilingStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;
		ceilingX = player->posX + rowDistance * rayDirX0;
		ceilingY = player->posY + rowDistance * rayDirY0;

		for (int x = 0; x < SCREEN_WIDTH; x += xStep)
		{
			cellX = (int) (ceilingX);
			cellY = (int) (ceilingY);
			texX = (int) (TEX_WIDTH * (ceilingX - cellX)) & (TEX_WIDTH - 1);
			texY = (int) (TEX_HEIGHT * (ceilingY - cellY)) & (TEX_HEIGHT - 1);
			ceilingX += ceilingStepX * xStep;
			ceilingY += ceilingStepY * xStep;
			ceilingColor = instance->ceilingTexture[TEX_WIDTH * texY + texX];
			r = (ceilingColor >> 16) & 0xFF;
			g = (ceilingColor >> 8) & 0xFF;
			b = ceilingColor & 0xFF;
			SDL_SetRenderDrawColor(instance->renderer, r, g, b, 255);
			SDL_RenderDrawPoint(instance->renderer, x, y);
		}
	}
}
