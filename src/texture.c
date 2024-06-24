#include "../headers/window.h"
#include "../headers/player.h"

/**
 * loadTexture - Loads a texture from a BMP file.
 * @filename: The name of the BMP file.
 * @renderer: A pointer to the SDL_Renderer structure.
 * Return: A pointer to the texture.
 */
color *loadTexture(const char *file)
{
    SDL_Surface *surface = SDL_LoadBMP(file);
    if (!surface)
    {
        fprintf(stderr, "Could not load texture '%s': %s\n", file, SDL_GetError());
        return NULL;
    }

    color *texture = malloc(TEX_WIDTH * TEX_HEIGHT * sizeof(color));
    if (!texture)
    {
        fprintf(stderr, "Could not allocate memory for texture '%s'\n", file);
        SDL_FreeSurface(surface);
        return NULL;
    }
    memcpy(texture, surface->pixels, TEX_WIDTH * TEX_HEIGHT * sizeof(color));
    SDL_FreeSurface(surface);
    return texture;
}

/**
 * destroyTexture - Frees the memory allocated for a texture.
 * @texture: A pointer to the texture to free.
 */
void destroyTexture(SDL_Instance *instance)
{
    for (int i = 0; i < NUM_TEXTURES; i++)
    {
        free(instance->textures[i]);
    }
}

/**
 * initTextures - Initializes the textures.
 * @instance: A pointer to the SDL_Instance structure.
 */
int initTextures(SDL_Instance *instance)
{
    const char *textureFiles[NUM_TEXTURES] = {
        "/home/mo5tar/Github/alx/the_maze/textures/eagle.bmp",
        "/home/mo5tar/Github/alx/the_maze/textures/redbrick.bmp",
        "/home/mo5tar/Github/alx/the_maze/textures/graystone.bmp",
        "/home/mo5tar/Github/alx/the_maze/textures/wood.bmp",
        "/home/mo5tar/Github/alx/the_maze/textures/colorstone.bmp"
    };
    for (int i = 0; i < NUM_TEXTURES; i++)
    {
        instance->textures[i] = loadTexture(textureFiles[i]);
        if (!instance->textures[i])
        {
            fprintf(stderr, "Failed to load texture %d: '%s'\n", i, textureFiles[i]);
            return 1;
        }
    }
    return 0;
}