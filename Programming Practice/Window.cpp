#include "Window.h"

Window::Window()
{
    window = SDL_CreateWindow("ргргрг", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::refresh()
{
    SDL_RenderPresent(render);
}

Window::~Window()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
