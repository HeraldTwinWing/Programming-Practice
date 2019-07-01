#pragma once

#include <SDL.h>
#include <deque>
#include "Window.h"
#include "Character.h"


bool operator==(SDL_Point p1, SDL_Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

class Item
{
protected:
    SDL_Rect pos;
    SDL_Point mapPos;
    SDL_Texture* texture;

public:
    bool effective;
    Item(SDL_Point mapPos);
    void broken();
    void pick(ItemEnum item);
    
    virtual void refresh() = 0;
    virtual ~Item() = 0;
};

class Potion : public Item
{
public:
    Potion(SDL_Point mapPos);
    void pick();
    void refresh() override;
    ~Potion();
};

class BombItem : public Item
{
public:
    BombItem(SDL_Point mapPos);
    void pick();
    void refresh() override;
    ~BombItem();
};

class Shoes : public  Item
{
public:
    Shoes(SDL_Point mapPos);
    void pick();
    void refresh() override;
    ~Shoes();
};

extern std::deque<Item*> items;