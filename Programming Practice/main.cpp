#include <iostream>
#include <SDL.h>

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << SDL_GetError() << std::endl;
    }

     

    SDL_Quit();

    return 0;
}