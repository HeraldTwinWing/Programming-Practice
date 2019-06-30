#pragma once
#include <SDL.h>
#include <fstream>
#include "Map.h"

class Character
{
private:
    SDL_Point pos;
    int speed;
    double moveTemp[2]; //保存位移的小数部分 [x,y]
    bool moving[4];     //[上，下，左，右]

    int bombPower;
    int maxBombPower;
    int bombNum;        //可放置炸弹数量上限
    int maxBombNum;
public:
    Character();
    
    void move(Map map);
    void setMoving(int direction);
    void placeBomb(SDL_Point pos);
    SDL_Point getMapPos();
    
    ~Character();
};

