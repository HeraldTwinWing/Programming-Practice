#include "Bomb.h"

Bomb::Bomb(int power, SDL_Point pos)
{
    this->power = power;
    this->placeTime = SDL_GetTicks();
    this->pos = { pos.x / 40 + 1, pos.y / 40 + 1 };
}

void Bomb::boom()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < power; j++)
        {
            if (i == 0)
            {
                if (!map->destruct(pos.x, pos.y - j))
                {
                    break;
                }
            }
            if (i == 1)
            {
                if (!map->destruct(pos.x + j, pos.y))
                {
                    break;
                }
            }
            if (i == 2)
            {
                if (!map->destruct(pos.x, pos.y + j))
                {
                    break;
                }
            } 
            if (i == 3)
            {
                if (!map->destruct(pos.x - j, pos.y))
                {
                    break;
                }
            }
        }
    }
}
