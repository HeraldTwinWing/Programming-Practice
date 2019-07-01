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
    for (int i = 0; i < 4; i++) //对应上下左右四个方向
    {
        for (int j = 1; j <= power; j++)    //直到被阻挡或达到范围上限为止，将对应方向上的方块设为爆炸区域
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

void Bomb::chainBoom()
{
    if (map->judgeBlockType(pos.x, pos.y) == DANGER && !boomed)
    {
        boom();
    }
}

bool Bomb::isBoomed()
{
    return boomed;
}

void Bomb::refresh()
{
    if (SDL_GetTicks() - placeTime > 4000 && !boomed)  //引信时间4000ms
    {
        boom();
    }
    chainBoom();

    SDL_Rect texturePos = { pos.x * 40, pos.y * 40 + 21, 38, 38 };
    SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &texturePos);
}

