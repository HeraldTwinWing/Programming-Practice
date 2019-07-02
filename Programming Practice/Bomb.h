#pragma once
#include <SDL.h>
#include <deque>
#include "Map.h"
#include "Window.h"

/** Õ¨µ¯
 *  ¿ØÖÆÕ¨µ¯µÄÏÔÊ¾£¬±¬Õ¨
 */
class Bomb
{
private:
    int power;
    SDL_Point pos;
    SDL_Texture* texture;
    double placeTime;
    bool boomed;
public:
    explicit Bomb(int power, SDL_Point pos);

    void boom();
    void chainBoom();   //Õ¨µ¯Á¬Ëø±¬Õ¨
    bool isBoomed();

    void refresh();
};

extern std::deque<Bomb*> p1Bombs;
extern std::deque<Bomb*> p2Bombs;