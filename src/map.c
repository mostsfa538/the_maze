#include "../headers/player.h"
#include "../headers/window.h"

int worldMap[mapWidth][mapWidth];

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
	{
		for (int j = 0; j < mapWidth; ++j)
		{
			if (worldMap[i][j] == 1)
				SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
			else if (worldMap[i][j] == 2)
				SDL_SetRenderDrawColor(instance->renderer, 0, 255, 0, 255);
			else if (worldMap[i][j] == 3)
				SDL_SetRenderDrawColor(instance->renderer, 0, 0, 255, 255);
			else if (worldMap[i][j] == 4)
				SDL_SetRenderDrawColor(instance->renderer, 255, 255, 0, 255);
			else if (worldMap[i][j] == 5)
				SDL_SetRenderDrawColor(instance->renderer, 255, 0, 255, 255);
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
	int lineLength = tileSize;
	int startX = player->posX * tileSize;
	int startY = player->posY * tileSize;
	int endX = startX + player->dirX * lineLength;
	int endY = startY + player->dirY * lineLength;

	SDL_SetRenderDrawColor(instance->renderer, 0, 255, 255, 255);
	SDL_RenderDrawLine(instance->renderer, startX, startY, endX, endY);
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
