#pragma once
#include <SDL.h>
#include <fstream>
#include "Map.h"

class Character
{
private:
    SDL_Point pos;
    int speed;
    double moveTemp[2]; //����λ�Ƶ�С������ [x,y]
    bool moving[4];     //[�ϣ��£�����]

    int bombPower;
    int maxBombPower;
    int bombNum;        //�ɷ���ը����������
    int maxBombNum;
public:
    Character();
    
    void move(Map map);
    void setMoving(int direction);
    void placeBomb(SDL_Point pos);
    SDL_Point getMapPos();
    
    ~Character();
};

