#pragma once
#include <SDL.h>
#include "GameEvent.h"
#include "Window.h"

class MainWhile
{
public:
    MainWhile();
    void onExecute();
    ~MainWhile();

private:
    bool running;
    double thisTime;    //��ǰ֡ʱ���
    double lastTime;    //��һ֡ʱ���
    double deltaTime;
};

extern MainWhile* mainWhile;