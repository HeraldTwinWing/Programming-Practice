#include "Map.h"

Map* map = new Map();

Map::Map() :map(), timeBuff(){}

std::array<std::array<BlockTypeEnum, 15>, 13> & Map::getMap()
{
    return map;
}

BlockTypeEnum Map::judgeBlockType(int x, int y)
{
    if (x > 13 || x < 0 || y> 15 || y < 0)
        return OUTRANGE;

    return map[x][y];
}

void Map::loadMap()
{
    std::fstream input("data/map");
    for (int i = 0; i < map.max_size(); i++)
    {
        std::string lineData;
        input >> lineData;
        for (int j = 0; j < map[i].max_size(); j++)
        {
            switch (lineData[j])
            {
            case 0:
                map[i][j] = DESTRUCTIBLE;
                break;
            case 1:
                map[i][j] = UNDESTRUCTIBLE;
                break;
            case 2:
                map[i][j] = EMPTY;
                break;
            case 3:
                map[i][j] = DANGER;
                break;
            case 4:
                map[i][j] = BOMB;
                break;
            default:
                break;
            }
        }
    }
}
