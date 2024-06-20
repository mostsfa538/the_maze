#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/window.h"
#include "../headers/player.h"

int main(void)
{
    SDL_Instance instance;
    if (init(&instance) != 0)
    {
        fprintf(stderr, "Failed to initialize SDL\n");
        return 1;
    }

    // Create the player instance
    Player *player = createPlayer(22.0, 11.5, -1.0, 0.0, 0.0, 0.66);
    if (player == NULL)
    {
        fprintf(stderr, "Failed to create player\n");
        destroy(&instance);
        return 1;
    }

    bool quit = false;
    // SDL_Event event;
    // Uint32 lastTime = SDL_GetTicks();

    while (!quit)
    {
        // while (SDL_PollEvent(&event))
        // {
        //     handleEvents(event);
        // }

        // Uint32 currentTime = SDL_GetTicks();
        // double frameTime = (currentTime - lastTime) / 1000.0;
        // lastTime = currentTime;

        // update(frameTime);

        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
        SDL_RenderClear(instance.renderer);

        render(&instance, player); // Pass player instance to render function

        SDL_RenderPresent(instance.renderer);
    }

    // Clean up
    destroyPlayer(player);
    destroy(&instance);

    return 0;
}
