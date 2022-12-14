#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Shepherd.h"
#include "constants.h"
#include <cstdio>

Shepherd::Shepherd(int x, int y, int velocity, SDL_Surface *surface_ptr) : Entity(x, y, velocity, surface_ptr, "./media/player.png")
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->lifeTime = rand() % 3000 + 10000000;
    this->birthTime = SDL_GetTicks();
}

Shepherd::~Shepherd()
{
}

void Shepherd::draw()
{
    SDL_Rect destR;

    destR.x = this->x;
    destR.y = this->y;
    destR.w = SHAPE_SIZE;
    destR.h = SHAPE_SIZE;

    SDL_BlitScaled(this->texture, NULL, this->surface, &destR);
}

void Shepherd::move(int direction)
{
    int speed = rand() % 3 + 1;
    switch (direction)
    {
    case 0:
        this->x += speed;
        break;
    case 1:
        this->x -= speed;
        break;
    case 2:
        this->y += speed;
        break;
    case 3:
        this->y -= speed;
        break;
    }
}

int Shepherd::isAlive()
{
    return SDL_GetTicks() - this->birthTime < this->lifeTime;
}