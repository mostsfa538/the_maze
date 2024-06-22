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
