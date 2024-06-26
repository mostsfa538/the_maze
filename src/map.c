#include "../headers/player.h"
#include "../headers/window.h"

int worldMap[mapWidth][mapWidth];
int rotatedMap[mapWidth][mapHeight];

/**
 * parseMap - Parses the map from the map file.
 */
void parseMap(void)
{
	FILE *file = fopen("src/map.txt", "r");

	if (file == NULL)
	{
		fprintf(stderr, "Failed to open map file\n");
		exit(1);
	}

	for (int i = 0; i < mapHeight; ++i)
	{
		for (int j = 0; j < mapWidth; ++j)
		{
			fscanf(file, "%d", &worldMap[i][j]);
		}
	}

	fclose(file);
}

/**
 * drawMap - Draws the 2D map.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: The player structure.
 */
void drawMap(SDL_Instance *instance, Player player)
{
	int tileSize = 10;
	SDL_Rect fillRect;

	if (!player.mapEnabled)
		return;
	for (int i = 0; i < mapHeight; ++i)
		for (int j = 0; j < mapWidth; ++j)
			rotatedMap[j][i] = worldMap[i][j];
	routeMap();
	routeMap();
	for (int i = 0; i < mapHeight; ++i)
	{
		for (int j = 0; j < mapWidth; ++j)
		{
			if (rotatedMap[i][j] >= 1)
				SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
			fillRect =
				(SDL_Rect){j * tileSize, i * tileSize, tileSize, tileSize};
			SDL_RenderFillRect(instance->renderer, &fillRect);
		}
	}
	SDL_SetRenderDrawColor(instance->renderer, 0, 255, 255, 255);
	fillRect = (SDL_Rect){(int) (player.posX * tileSize),
						  (int) (player.posY * tileSize), tileSize, tileSize};
	SDL_RenderFillRect(instance->renderer, &fillRect);
	drawPlayerDirection(instance, &player);
}

/**
 * drawPlayerDirection - Draws the player's direction.
 * @instance: A pointer to the SDL_Instance structure.
 * @player: The player structure.
 */

void drawPlayerDirection(SDL_Instance *instance, Player *player)
{
	int tileSize = 10;
	int lineLength = tileSize * 3;
	int startX = player->posX * tileSize;
	int startY = player->posY * tileSize;
	int endX = startX + player->dirX * lineLength;
	int endY = startY + player->dirY * lineLength;

	for (int i = 0; i < 5; i++)
	{
		SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 200 - i * 40);
		SDL_RenderDrawLine(instance->renderer, startX - i, startY - i, endX - i,
						   endY - i);
		SDL_RenderDrawLine(instance->renderer, startX + i, startY + i, endX + i,
						   endY + i);
	}
	SDL_SetRenderDrawBlendMode(instance->renderer, SDL_BLENDMODE_NONE);
}

/**
 * enableMap - Enables or disables the 2D map.
 * @player: The player structure.
 * Return: true if the map is enabled, false otherwise.
 */
bool enableMap(Player *player)
{
	player->mapEnabled = !player->mapEnabled;
	return (player->mapEnabled);
}


/**
 * routeMap - Rotates the map 90 degrees.
 */
void routeMap(void)
{
	int temp;

	for (int i = 0; i < mapHeight; ++i)
	{
		for (int j = 0; j < mapWidth / 2; ++j)
		{
			temp = rotatedMap[i][j];
			rotatedMap[i][j] = rotatedMap[i][mapWidth - j - 1];
			rotatedMap[i][mapWidth - j - 1] = temp;
		}
	}
}
