#include "Item.h"

std::deque<Item*> items;


Item::Item(SDL_Point mapPos)
{
    this->mapPos = mapPos;
    this->pos = { mapPos.x * 40 + 19, mapPos.y * 40 + 59, 38, 38 };
    this->effective = true;
    this->texture = nullptr;
}

void Item::broken()
{
    if (map->judgeBlockType(mapPos.x, mapPos.y) == DANGER)
    {
        effective = false;
    }
}

void Item::pick(ItemEnum item)
{
    if (player1->getMapPos() == mapPos && player1->isAttributeReachesUpperLimit(item))
    {
        player1->attributeUp(item);
    }
    else if (player2->getMapPos() == mapPos && player2->isAttributeReachesUpperLimit(item))
    {
        player2->attributeUp(item);
    }
    effective = false;
}

void Item::refresh()
{
    
}

Potion::Potion(SDL_Point mapPos) : Item(mapPos)
{
    texture = mainWindow->loadPicture("potion.png");
}


void Potion::pick()
{
    Item::pick(POTION);
}

void Potion::refresh()
{
    if (effective)
    {
        pick();
        Item::broken();
        SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &pos);
    }
}

Potion::~Potion() = default;

BombItem::BombItem(SDL_Point mapPos) : Item(mapPos)
{
    texture = mainWindow->loadPicture("bombItem.png");
}

void BombItem::pick()
{
    Item::pick(BOMBITEM);
}

void BombItem::refresh()
{
    if (effective)
    {
        pick();
        Item::broken();
        SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &pos);
    }
}

BombItem::~BombItem() = default;

Shoes::Shoes(SDL_Point mapPos) : Item(mapPos)
{
    texture = mainWindow->loadPicture("shoes.png");
}

void Shoes::pick()
{
    Item::pick(SHOES);
}

void Shoes::refresh()
{
    if (effective)
    {
        pick();
        Item::broken();
        SDL_RenderCopy(mainWindow->getRender(), texture, nullptr, &pos);
    }
}

Shoes::~Shoes() = default;
