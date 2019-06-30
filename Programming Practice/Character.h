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
    bool moving[4];     //[�ϣ��ң��£���]

    int bombPower;
    int maxBombPower;
    int bombNum;        //�ɷ���ը����������
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
    //��ȡ��ɫ���ڵ�ͼ����
    SDL_Point getMapPos();
    
    void refresh(double deltaTime);
    ~Character();
};

