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
    double thisTime;    //��ǰ֡ʱ���
    double lastTime;    //��һ֡ʱ���
    double deltaTime;
};

extern MainWhile* mainWhile;