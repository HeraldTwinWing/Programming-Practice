#include <iostream>
#include <SDL.h>
#include "MainWhile.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    mainWhile = new MainWhile();
    eventHandler = new GameEvent();
    mainWhile->onExecute();

    SDL_Quit();

    return 0;
}