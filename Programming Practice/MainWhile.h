#pragma once
#include <SDL.h>
#include "GameEvent.h"
#include "Window.h"
#include "Character.h"

class MainWhile
{
public:
    MainWhile();
    void onExecute();
    void onUpdata();
    void bombsUpdata();

    ~MainWhile();

private:
    bool running;
    double thisTime;    //��ǰ֡ʱ���
    double lastTime;    //��һ֡ʱ���
    double deltaTime;
};

extern MainWhile* mainWhile;