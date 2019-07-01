#include "RestartButton.h"

 RestartButton* restartButton;

RestartButton::RestartButton()
{
    pos = { 508, 503, 92, 97 };
    texture = mainWindow->loadPicture("RestartButton.png");
    effective = false;
}

void RestartButton::click(int mX, int mY)
{
    SDL_Point clickPoint = { mX, mY };
    if (SDL_PointInRect(&clickPoint, &pos))
    {
        delete player1;
        player1 = new Character();
        delete player2;
        player2 = new Character();
        map->loadMap();
        effective = false;
    }
    else
    {
        return;
    }
}

void RestartButton::enable()
{
    effective = true;
}

void RestartButton::refresh()
{
    if (effective)
    {
        SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &pos);
    }
}
