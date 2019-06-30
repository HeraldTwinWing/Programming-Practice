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
        mainWindow->refresh();
    }
}

MainWhile::~MainWhile()
{
}