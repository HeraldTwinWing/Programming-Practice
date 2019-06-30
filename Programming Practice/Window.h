#pragma once
#include <SDL.h>
class Window
{
private:
    SDL_Window* window;
    SDL_Renderer* render;
public:
    Window();

    void createWindow();

    SDL_Window* getWindow();
    SDL_Renderer* getRender();

    void refresh();

    ~Window();
};

extern Window* mainWindow;