#include <SDL.h>
#include "MainWhile.h"

MainWhile* mainWhile;

MainWhile::MainWhile()
{
    thisTime = SDL_GetTicks();
    lastTime = thisTime;
    deltaTime = 0;
    running = true;
    mainWindow = new Window();
    map = new Map();
    player1 = new Character();
    player2 = new Character();
    map->loadMap();
}

void MainWhile::onExecute()
{
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            eventHandler->OnEvent(event);
        }
        onUpdata();
    }
}

void MainWhile::onUpdata()
{
    player1->refresh(deltaTime);
    player2->refresh(deltaTime);
    mainWindow->refresh();
}

MainWhile::~MainWhile()
{
}