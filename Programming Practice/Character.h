#pragma once
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <SDL_image.h>
#include "Map.h"
#include "Window.h"

class Character
{
private:
    SDL_Point pos;
    SDL_Texture* texture;
    SDL_Rect texturePos;
    int speed;
    double moveTemp[2]; //保存位移的小数部分 [x,y]
    bool moving[4];     //[上，右，下，左]

    int bombPower;
    int maxBombPower;
    int bombNum;        //可放置炸弹数量上限
    int maxBombNum;
public:
    Character();

    void move(double deltaTime);
    void setMoving(int direction);
    void placeBomb(SDL_Point pos);
    void p1KeyDownEvent(SDL_Keycode sym);
    void p2KeyDownEvent(SDL_Keycode sym);
    void p1KeyUpEvent(SDL_Keycode sym);
    void p2KeyUpEvent(SDL_Keycode sym);
    //获取角色所在地图格子
    SDL_Point getMapPos();

    void refresh(double deltaTime);
    ~Character();
};

extern Character* player1;
extern Character* player2;