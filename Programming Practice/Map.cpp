#include "Map.h"

std::array<std::array<BlockTypeEnum, 15>, 13>& Map::getMap()
{
    return map;
}
