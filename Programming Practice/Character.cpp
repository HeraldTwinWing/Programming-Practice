#include "Character.h"

Character* player1;
Character* player2;




int Character::playerNum = 0;

Character::Character() :moving(), moveTemp()
{
    speed = 50;
    maxSpeed = 250;
    bombPower = 4;
    maxBombPower = 4;
    bombNum = 4;
    maxBombNum = 4;
    dead = false;
    if (playerNum == 0)
    {
        pos = { 20, 60 };
        mapPos = { 0, 0 };
        texture = mainWindow->loadPicture("player1.png");
        deadTexture = mainWindow->loadPicture("player1_dead.png");
        texturePos = { pos.x, pos.y , 44, 56 };
    }
    else
    {
        pos = { 580 , 520 };
        mapPos = { 14, 12 };
        texture = mainWindow->loadPicture("player2.png");
        deadTexture = mainWindow->loadPicture("player2_dead.png");
        texturePos = { pos.x, pos.y, 44, 56 };
    }

    for (auto& i : moving)
        i = false;
    for (auto& i : moveTemp)
        i = 0;

    ++playerNum;
    if (playerNum > 1)
    {
        playerNum = 0;
    }
}

SDL_Point Character::getMapPos()
{
    SDL_Point result = { 0, 0 };
    result.x = (int)(pos.x / 40);
    if (pos.y - 40 < 0)
    {
        result.y = -1;
    }
    else
    {
        result.y = (int)((pos.y - 40) / 40);
    }
    /*   if (pos.x % 40)
           ++result.x;
       if (pos.y % 40)
           ++result.y;
           */
    return result;
}

void Character::refresh(double deltaTime)
{
    move(deltaTime);
    mapPos = getMapPos();
    if (map->judgeBlockType(mapPos.x, mapPos.y) == DANGER)  //击败判定
    {
        dead = true;
    }

    texturePos.x = pos.x - 22;
    texturePos.y = pos.y - 50;
    //std::cout << pos.x << " " << pos.y << std::endl;
    //std::cout << "map pos:" << mapPos.x << " " << mapPos.y << std::endl;
    if (dead)
    {
        SDL_RenderCopy(mainWindow->getRender(), deadTexture, nullptr, &texturePos);
    }
    else
    {
        SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &texturePos);
    }
}

Character::~Character() = default;

void Character::move(double deltaTime)
{
    Map& mapObj = *map;
    SDL_Point mapPos = getMapPos();
    auto& map = mapObj.getMap();

    if (dead)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        double displacement = deltaTime * speed / 1000;
        int v1 = i + 1;
        if (v1 > 3)
            v1 = 0;

        int v2 = i - 1;
        if (v2 < 0)
            v1 = 3;

        if (moving[i])
        {
            switch (i)
            {

            case 0:
                if ((pos.y % 40 >= 20 ||
                    mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY) &&
                    pos.x % 40 == 20)
                    moveTemp[1] -= displacement;
                else if (pos.x % 40 < 20)   
                {
                    if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) >= EMPTY &&   //移动方向上有两个空格
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&      //移动方向上有两个空格
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY &&
                        pos.y % 40 > 20)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) >= EMPTY &&  //撞墙时垂直移动方向平移
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) < EMPTY &&   //撞墙时垂直移动方向平移
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }
                }
                else if (pos.x % 40 > 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY &&
                        pos.y % 40 > 20)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                }
                break;
            case 1:
                if ((pos.x % 40 <= 20 ||
                    mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY) &&
                    pos.y % 40 == 20)
                    moveTemp[0] += displacement;
                else if (pos.y % 40 < 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY &&
                        pos.x % 40 < 20)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y - 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                }


                else if (pos.y % 40 > 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY &&
                        pos.x % 40 < 20)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                }
                break;
            case 2:
                if ((pos.y % 40 <= 20 ||
                    mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY) &&
                    pos.x % 40 == 20)
                    moveTemp[1] += displacement;
                else if (pos.x % 40 < 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY &&
                        pos.y % 40 < 20)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }

                }
                else if (pos.x % 40 > 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY &&
                        pos.y % 40 < 20)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x + 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x + 1, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                }
                break;
            case 3:
                if ((pos.x % 40 >= 20 ||
                    mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY) &&
                    pos.y % 40 == 20)
                {
                    moveTemp[0] -= displacement;
                }
                else if (pos.y % 40 < 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY &&
                        pos.x % 40 > 20)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y - 1) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y - 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                }
                else if (pos.y % 40 > 20)
                {
                    if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x, mapPos.y) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY &&
                        pos.x % 40 > 20)
                    {
                        moveTemp[0] -= displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) >= EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x, mapPos.y + 1) >= EMPTY)
                    {
                        moveTemp[1] += displacement;
                    }
                    else if (mapObj.judgeBlockType(mapPos.x - 1, mapPos.y + 1) < EMPTY &&
                        mapObj.judgeBlockType(mapPos.x - 1, mapPos.y) >= EMPTY)
                    {
                        moveTemp[1] -= displacement;
                    }
                }
            }
        }
    }

    //取整移动缓存，加到坐标上
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
    case SDLK_RETURN:
        if (p2Bombs.size() < bombNum && map->judgeBlockType(mapPos.x, mapPos.y) != BOMB)
        {
            p2Bombs.push_back(new Bomb{ bombPower, mapPos });
            map->setBombBlock(mapPos.x, mapPos.y);
        }
        break;
    default:
        break;
    }
}

void Character::attributeUp(ItemEnum attri)
{
    switch (attri)
    {
    case POTION:
        bombPower += 1;
        break;
    case BOMBITEM:
        bombNum += 1;
        break;
    case SHOES:
        speed += 50;
        break;
    default:
        break;
    }
}

bool Character::isNotDead()
{
    return !dead;
}

bool Character::isDead()
{
    return dead;
}

bool Character::isAttributeReachesUpperLimit(ItemEnum attri)
{
    switch (attri)
    {
    case POTION:
        return bombPower < maxBombPower;
        break;
    case BOMBITEM:
        return bombNum < maxBombNum;
        break;
    case SHOES:
        return speed < maxSpeed;
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
        if (p1Bombs.size() < bombNum && map->judgeBlockType(mapPos.x, mapPos.y) != BOMB)
        {
            p1Bombs.push_back(new Bomb{ bombPower, mapPos });
            map->setBombBlock(mapPos.x, mapPos.y);
        }
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
        moving[2] = false;
        break;
    case SDLK_LEFT:
        moving[3] = false;
        break;
    case SDLK_RIGHT:
        moving[1] = false;
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
        moving[2] = false;
        break;
    case SDLK_a:
        moving[3] = false;
        break;
    case SDLK_d:
        moving[1] = false;
        break;
    default:
        break;
    }
}

