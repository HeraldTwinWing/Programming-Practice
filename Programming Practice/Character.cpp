#include "Character.h"

Character::Character():moving(),moveTemp()
{
    //std::ifstream input("data/characterData");
    pos = { 20, 20 };
    speed = 40;
    bombPower = 1;
    maxBombPower = 1;
    bombNum = 1;
    maxBombNum = 1;

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

void Character::refresh(double deltaTime)
{
    move(deltaTime);
}

void Character::move(double deltaTime)
{
    Map& mapObj = *map;
    SDL_Point mapPos = getMapPos();
    auto& map = mapObj.getMap();

    for (int i = 0; i < 4; i++)
    {
        double displacement = deltaTime * speed;
        int v1 = i + 1;
        if (v1 > 3)
            v1 = 0;

        int v2 = i - 1;
        if (v2 < 0)
            v1 = 3;
        
        switch (i)
        {
        case 0:
            if ((pos.x % 40) < 15)
                moveTemp[0] -= displacement;
            else if ((pos.x % 40) > 25)
                moveTemp[0] += displacement;
            else
                moveTemp[1] -= displacement;
        case 1:
            if ((pos.y % 40) < 15)
                moveTemp[1] -= displacement;
            else if ((pos.y % 40) > 25)
                moveTemp[1] += displacement;
            else
                moveTemp[0] += displacement;
        case 2:
            if ((pos.x % 40) < 15)
                moveTemp[0] -= displacement;
            else if ((pos.x % 40) > 25)
                moveTemp[0] += displacement;
            else
                moveTemp[1] += displacement;
        case 3:
            if ((pos.y % 40) < 15)
                moveTemp[1] -= displacement;
            else if ((pos.y % 40) > 25)
                moveTemp[1] += displacement;
            else
                moveTemp[0] -= displacement;
        }
    }

    if (std::abs(moveTemp[0]) > 1)
    {
        pos.x += (int)std::trunc(moveTemp[0]);
        moveTemp[0] -= std::trunc(moveTemp[0]);
    }
    if (std::abs(moveTemp[1]) > 1)
    {
        pos.y += (int)std::trunc(moveTemp[1]);
        moveTemp[1] -= std::trunc(moveTemp[1]);
    }
}

void Character::p2KeyDownEvent(SDL_Keycode sym)
{
    switch (sym)
    {
    case SDLK_UP:
        moving[0] = true;
        moving[1] = false;
        moving[2] = false;
        moving[3] = false;
        break;
    case SDLK_DOWN:
        moving[0] = false;
        moving[1] = false;
        moving[2] = true;
        moving[3] = false;
        break;
    case SDLK_LEFT:
        moving[0] = false;
        moving[1] = false;
        moving[2] = false;
        moving[3] = true;
        break;
    case SDLK_RIGHT:
        moving[0] = false;
        moving[1] = true;
        moving[2] = false;
        moving[3] = false;
        break;
    case SDLK_KP_ENTER:
        break;
    default:
        break;
    }
}

void Character::p1KeyDownEvent(SDL_Keycode sym)
{
    switch (sym)
    {
    case SDLK_w:
        moving[0] = true;
        moving[1] = false;
        moving[2] = false;
        moving[3] = false;
        break;
    case SDLK_s:
        moving[0] = false;
        moving[1] = false;
        moving[2] = true;
        moving[3] = false;
        break;
    case SDLK_a:
        moving[0] = false;
        moving[1] = false;
        moving[2] = false;
        moving[3] = true;
        break;
    case SDLK_d:
        moving[0] = false;
        moving[1] = true;
        moving[2] = false;
        moving[3] = false;
        break;
    case SDLK_SPACE:
        break;
    default:
        break;
    }
}

void Character::p2KeyUpEvent(SDL_Keycode sym)
{
    switch (sym)
    {
    case SDLK_UP:
        moving[0] = false;
        break;
    case SDLK_DOWN:
        moving[1] = false;
        break;
    case SDLK_LEFT:
        moving[2] = false;
        break;
    case SDLK_RIGHT:
        moving[3] = false;
        break;
    default:
        break;
    }
}

void Character::p1KeyUpEvent(SDL_Keycode sym)
{
    switch (sym)
    {
    case SDLK_w:
        moving[0] = false;
        break;
    case SDLK_s:
        moving[1] = false;
        break;
    case SDLK_a:
        moving[2] = false;
        break;
    case SDLK_d:
        moving[3] = false;
        break;
    default:
        break;
    }
}
