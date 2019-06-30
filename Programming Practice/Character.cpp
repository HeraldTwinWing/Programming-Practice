#include "Character.h"

Character::Character()
{
    //std::ifstream input("data/characterData");
    pos = { 20, 20 };
    speed = 40;
    bombPower = 1;
    maxBombPower = 1;
    bombNum = 1;
    maxBombNum = 1;
    moving = { false };

    for (auto& i : moving)
        i = false;
    for (auto& i : moveTemp)
        i = 0;
}

SDL_Point Character::getMapPos()
{
    SDL_Point result = { 0, 0 };
    result.x = (int)(pos.x / 40);
    result.y = (int)(pos.y / 40);
    if (pos.x % 40)
        ++result.x;
    if (pos.y % 40)
        ++result.y;
    return result;
}

void Character::move(Map map)
{
    SDL_Point mapPos = getMapPos();
    
}