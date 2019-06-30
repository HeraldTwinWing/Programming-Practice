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
    double thisTime;    //当前帧时间戳
    double lastTime;    //上一帧时间戳
    double deltaTime;
};

extern MainWhile* mainWhile;