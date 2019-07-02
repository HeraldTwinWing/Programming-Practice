#pragma once
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <SDL_image.h>
#include "Map.h"
#include "Bomb.h"
#include "Window.h"

class Character
{
private:
    static int playerNum;

    SDL_Point pos;
    SDL_Point mapPos;
    SDL_Texture* texture;
    SDL_Texture* deadTexture;
    SDL_Rect texturePos;
    int speed;
    double moveTemp[2]; //����λ�Ƶ�С������ [x,y]
    bool moving[4];     //[�ϣ��ң��£���]
    bool dead;

    int bombPower;
    int maxBombPower;
    int bombNum;        //�ɷ���ը����������
    int maxBombNum;
public:
    Character();

    void move(double deltaTime);
    void setMoving(int direction);
    void placeBomb(SDL_Point pos);
    bool isNotDead();
    bool isDead();
    void p1KeyDownEvent(SDL_Keycode sym);
    void p2KeyDownEvent(SDL_Keycode sym);
    void p1KeyUpEvent(SDL_Keycode sym);
    void p2KeyUpEvent(SDL_Keycode sym);
    //��ȡ��ɫ���ڵ�ͼ����
    SDL_Point getMapPos();

    void refresh(double deltaTime);
    ~Character();
};

extern Character* player1;
extern Character* player2;