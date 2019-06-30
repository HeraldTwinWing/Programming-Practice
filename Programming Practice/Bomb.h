#pragma once
#include <SDL.h>
#include "Map.h"

class Bomb
{
private:
    int power;
    SDL_Point pos;
    double placeTime;
public:
    explicit Bomb(int power, SDL_Point pos);

    void boom();
};

