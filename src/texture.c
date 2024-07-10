#include "../headers/window.h"

/**
 * loadTexture - Loads a texture from a BMP file.
 * @file: The name of the BMP file.
 * Return: A pointer to the texture.
 */
color *loadTexture(const char *file)
{
	SDL_Surface *surface = SDL_LoadBMP(file);
	color *texture;

	if (!surface)
	{
		fprintf(stderr, "Could not load texture '%s': %s\n", file,
				SDL_GetError());
		return (NULL);
	}
	texture = malloc(TEX_WIDTH * TEX_HEIGHT * sizeof(color));
	if (!texture)
	{
		fprintf(stderr, "Could not allocate memory for texture '%s'\n", file);
		SDL_FreeSurface(surface);
		return (NULL);
	}
	memcpy(texture, surface->pixels, TEX_WIDTH * TEX_HEIGHT * sizeof(color));
	SDL_FreeSurface(surface);
	return (texture);
}

/**
 * destroyTexture - Frees the memory allocated for a texture.
 * @instance: A pointer to the texture to free.
 */
void destroyTexture(SDL_Instance *instance)
{
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		free(instance->textures[i]);
	}
	free(instance->floorTexture);
	free(instance->ceilingTexture);
}

/**
 * initTextures - Initializes the textures.
 * @instance: A pointer to the SDL_Instance structure.
 * Return: 0 on success, 1 on failure.
 */
int initTextures(SDL_Instance *instance)
{
	const char *textureFiles[NUM_TEXTURES] = {
		"textures/eagle.bmp",
		"textures/redbrick.bmp",
		"textures/graystone.bmp",
		"textures/wood.bmp",
		"textures/bluestone.bmp"};

	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		instance->textures[i] = loadTexture(textureFiles[i]);
		if (!instance->textures[i])
		{
			fprintf(stderr, "Failed to load texture %d: '%s'\n", i,
					textureFiles[i]);
			return (1);
		}
	}

	instance->floorTexture =
		loadTexture("textures/colorstone.bmp");
	if (!instance->floorTexture)
	{
		fprintf(stderr, "Failed to load floor texture\n");
		return (1);
	}
	instance->ceilingTexture = loadTexture(
		"textures/purplestone.bmp");
	if (!instance->ceilingTexture)
	{
		fprintf(stderr, "Failed to load ceiling texture\n");
		return (1);
	}

	return (0);
}
