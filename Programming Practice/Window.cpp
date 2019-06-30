#include "Window.h"

Window* mainWindow;

Window::Window()
{
    window = SDL_CreateWindow("ргргрг", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Window* Window::getWindow()
{
    return window;
}

SDL_Renderer* Window::getRender()
{
    return render;
}

SDL_Texture* Window::loadPicture(const std::string& filename)
{
    if (textures.find(filename) != textures.end())
    {
        return textures[filename];
    }
    else
    {
        std::string path = "./picture/" + filename;
        SDL_Surface* loaded_image = nullptr;
        SDL_Texture* texture = nullptr;

        loaded_image = IMG_Load(path.c_str());
        if (loaded_image == nullptr)
        {
            std::cout << SDL_GetError() << std::endl;
            return nullptr;
        }
        texture = SDL_CreateTextureFromSurface(render, loaded_image);
        textures[filename] = texture;

        SDL_FreeSurface(loaded_image);

        return textures[filename];
    }
}

void Window::refresh()
{
    SDL_RenderPresent(render);
    SDL_RenderClear(render);
}

Window::~Window()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
