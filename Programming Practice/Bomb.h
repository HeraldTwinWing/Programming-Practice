#pragma once
#include <SDL.h>
#include <deque>
#include "Map.h"
#include "Window.h"

class Bomb
{
private:
    int power;
    SDL_Point pos;
    SDL_Texture* texture;
    double placeTime;
public:
    explicit Bomb(int power, SDL_Point pos);

    void boom();

    void refresh();
};

extern std::deque<Bomb*> bombs;