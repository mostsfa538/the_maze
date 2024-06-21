#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>

/**
 * struct Player - A structure to hold the player's position and direction.
 * @posX: The player's x position.
 * @posY: The player's y position.
 * @dirX: The player's x direction.
 * @dirY: The player's y direction.
 * @planeX: The player's x plane.
 * @planeY: The player's y plane.
 */
typedef struct Player
{
	double posX, posY;
	double dirX, dirY;
	double planeX, planeY;
} Player;

Player *createPlayer(double posX, double posY, double dirX, double dirY,
					 double planeX, double planeY);
void destroyPlayer(Player *player);
void updatePlayerPosition(Player *player, double newPosX, double newPosY);
void updatePlayerDirection(Player *player, double frameTime);

#endif
