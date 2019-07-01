#include "Bomb.h"

std::deque<Bomb*> bombs;

Bomb::Bomb(int power, SDL_Point pos)
{
    this->power = power;
    this->placeTime = SDL_GetTicks();
    this->pos = { pos.x / 40 + 1, pos.y / 40 + 1 };
    this->texture = mainWindow->loadPicture("bomb.png");
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
                map->getBlockReference(pos.x, pos.y - j) = DANGER;
            }
            if (i == 1)
            {
                if (!map->destruct(pos.x + j, pos.y))
                {
                    break;
                }
                map->getBlockReference(pos.x + j, pos.y) = DANGER;
            }
            if (i == 2)
            {
                if (!map->destruct(pos.x, pos.y + j))
                {
                    break;
                }
                map->getBlockReference(pos.x, pos.y + j) = DANGER;
            } 
            if (i == 3)
            {
                if (!map->destruct(pos.x - j, pos.y))
                {
                    break;
                }
                map->getBlockReference(pos.x - j, pos.y) = DANGER;
            }
        }
    }
}

void Bomb::refresh()
{
    if (SDL_GetTicks() - placeTime > 4000)
    {
        boom();
    }

    SDL_Rect texturePos = { pos.x * 40 + 20, pos.y * 40 + 20, 38, 38 };
    SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &texturePos);
}

