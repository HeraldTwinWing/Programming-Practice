#pragma once

#include <map>
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>

/*显示窗口与加载资源*/

class Window
{
private:
    SDL_Window* window;
    SDL_Renderer* render;
    std::map<std::string, SDL_Texture*> textures;
public:
    Window();


    SDL_Window* getWindow();
    SDL_Renderer* getRender();
    SDL_Texture* loadPicture(const std::string& filename);

    void refresh();

    ~Window();
};

extern Window* mainWindow;