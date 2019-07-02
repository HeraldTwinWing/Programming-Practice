#pragma once
#include <SDL.h>
#include "Window.h"
#include "GameEvent.h"
#include "Character.h"
#include "RestartButton.h"

enum GameStatusEnmu
{
    STARTMENU,
    PLAYING,
    ENDMENU
};

extern GameStatusEnmu gameStatus;

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