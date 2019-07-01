#include <SDL.h>
#include "MainWhile.h"

MainWhile* mainWhile;
GameStatusEnmu gameStatus = PLAYING;

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
    restartButton = new RestartButton();
    map->loadMap();
}

void MainWhile::onExecute()
{
    SDL_Event event;

    while (running)
    {
        static int frame = 0;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            eventHandler->OnEvent(event);
        }
        onUpdata();
        //std::cout << "Frame: " << frame++ << std::endl;
    }
}

void MainWhile::onUpdata()
{
    lastTime = thisTime;
    thisTime = SDL_GetTicks();
    deltaTime = thisTime - lastTime;
    map->refresh(deltaTime);
    bombsUpdata();

    player1->refresh(deltaTime);
    player2->refresh(deltaTime);

    if (!(player1->isNotDead() && player2->isNotDead()))
    {
        restartButton->enable();
        SDL_Rect resultPos = { 204 , 204, 192, 192 };
        if (player1->isDead() && player2->isDead())
        {
            SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("draw.png"), nullptr, &resultPos);
        }
        else if (player1->isDead())
        {
            SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("p2win.png"), nullptr, &resultPos);
        }
        else if (player2->isDead())
        {
            SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("p1win.png"), nullptr, &resultPos);
        }
    }
    restartButton->refresh();


    mainWindow->refresh();
}

void MainWhile::bombsUpdata()
{
    for (auto& i : p1Bombs)
    {
        i->refresh();
        if (i->isBoomed())
        {
            delete i;
            i = nullptr;
        }
    }
    for (int i = 0; i < p1Bombs.size(); i++)
    {
        if (p1Bombs[i] == nullptr)
        {
            p1Bombs.erase(p1Bombs.begin() + i);
            --i;
        }
    }

    for (auto& i : p2Bombs)
    {
        i->refresh();
        if (i->isBoomed())
        {
            delete i;
            i = nullptr;
        }
    }
    for (int i = 0; i < p2Bombs.size(); i++)
    {
        if (p2Bombs[i] == nullptr)
        {
            p2Bombs.erase(p2Bombs.begin() + i);
            --i;
        }
    }
}

MainWhile::~MainWhile()
{
}