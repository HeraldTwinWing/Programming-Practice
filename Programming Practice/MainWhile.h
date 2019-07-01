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
    double thisTime;    //当前帧时间戳
    double lastTime;    //上一帧时间戳
    double deltaTime;
};

extern MainWhile* mainWhile;