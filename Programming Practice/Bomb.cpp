#include "Bomb.h"

std::deque<Bomb*> p1Bombs;
std::deque<Bomb*> p2Bombs;

Bomb::Bomb(int power, SDL_Point mapPos)
{
    this->power = power;
    this->placeTime = SDL_GetTicks();
    this->pos = { mapPos.x , mapPos.y };
    this->texture = mainWindow->loadPicture("bomb.png");
    this->boomed = false;
}

void Bomb::boom()
{
    map->setDangerBlock(pos.x, pos.y);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= power; j++)
        {
            if (i == 0)
            {
                if (!map->destruct(pos.x, pos.y - j))
                {
                    map->destructBlock(pos.x, pos.y - j);
                    break;
                }
                map->setDangerBlock(pos.x, pos.y - j);
            }
            if (i == 1)
            {
                if (!map->destruct(pos.x + j, pos.y))
                {
                    map->destructBlock(pos.x + j, pos.y);
                    break;
                }
                map->setDangerBlock(pos.x + j, pos.y);
            }
            if (i == 2)
            {
                if (!map->destruct(pos.x, pos.y + j))
                {
                    map->destructBlock(pos.x, pos.y + j);
                    break;
                }
                map->setDangerBlock(pos.x, pos.y + j);
            } 
            if (i == 3)
            {
                if (!map->destruct(pos.x - j, pos.y))
                {
                    map->destructBlock(pos.x - j, pos.y);
                    break;
                }
                map->setDangerBlock(pos.x - j, pos.y);
            }
        }
    }
    boomed = true;
}

bool Bomb::isBoomed()
{
    return boomed;
}

void Bomb::refresh()
{
    if (SDL_GetTicks() - placeTime > 1000)
    {
        boom();
    }

    SDL_Rect texturePos = { pos.x * 40, pos.y * 40 + 21, 38, 38 };
    SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &texturePos);
}

