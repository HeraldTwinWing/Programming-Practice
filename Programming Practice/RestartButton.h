#pragma once
#include <SDL.h>
#include "Map.h"
#include "Window.h"
#include "Character.h"

class RestartButton
{
private:
    SDL_Texture* texture;
    SDL_Rect pos;
    bool effective;
public:
    RestartButton();
    void click(int mX, int mY);
    void enable();
    void refresh();
};

extern RestartButton* restartButton;