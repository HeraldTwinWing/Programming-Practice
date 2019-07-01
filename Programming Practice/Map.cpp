#include "Map.h"
#include <iostream>


Map* map = new Map();

Map::Map() :map(), timeBuff() {}

std::array<std::array<BlockTypeEnum, 15>, 13> & Map::getMap()
{
    return map;
}

BlockTypeEnum Map::judgeBlockType(int x, int y)
{
    if (x >= 15 || x < 0 || y >= 13 || y < 0)
        return OUTRANGE;

    return map[y][x];
}

BlockTypeEnum& Map::getBlockReference(int x, int y)
{
    return map[y][x];
}

void Map::setBombBlock(int x, int y)
{
    map[y][x] = BOMB;
}

void Map::setDangerBlock(int x, int y)
{
    map[y][x] = DANGER;
    timeBuff[y][x] = SDL_GetTicks();
}

bool Map::destruct(int x, int y)
{
    switch (judgeBlockType(x, y))
    {
    default:
        return false;
        break;
    case OUTRANGE:
        return false;
    case EMPTY:
        return true;
    case DESTRUCTIBLE:
        return false;
    case UNDESTRUCTIBLE:
        return false;
    case DANGER:
        return true;
    case BOMB:
        return true;
    }
    return false;
}

void Map::destructBlock(int x, int y)
{
    if (judgeBlockType(x, y) == DESTRUCTIBLE)
    {
        map[y][x] = EMPTY;
    }
}




//���ļ����ص�ͼ*/
void Map::loadMap()
{
    std::fstream file("./data/map", std::ios::in);
    if (file.fail()) {
        std::cout << "Cannot open the file\n";
        exit(2);
    }
    char ch;
    for (int i = 0; i < 13; i++) {
        std::string line;
        file >> line;
        for (int j = 0; j < line.size(); j++) {
            switch (line[j])
            {
            case '0':map[i][j] = DESTRUCTIBLE;
                break;
            case '1':map[i][j] = UNDESTRUCTIBLE;
                break;
            case '2':map[i][j] = EMPTY;
                break;
            case '3':map[i][j] = DANGER;
                break;
            case '4':map[i][j] = BOMB;
                break;
            default:
                break;
            }
        }
    }
    file.close();
    return;
}


//�������Խ������Լ�ը����Χ�ĵ�ͼ�仯���
bool Map::Judge(int x, int y) {
    if (!(x >= 0 && x < 13 && y >= 0 && y < 15))
        return false;
    if (map[x][y] == DESTRUCTIBLE) {
        timeBuff[x][y] = SDL_GetTicks();//��¼ʱ����
        map[x][y] = DANGER;
        double lastime = SDL_GetTicks();
        if (lastime - timeBuff[x][y] > 500) {
            map[x][y] = EMPTY;
        }
        return true;
    }
    else return false;
}
//ը��λ�õĵ�ͼ�仯
void Map::Bomb_change(int x, int y) {
    timeBuff[x][y] = SDL_GetTicks();
    map[x][y] = BOMB;
    double last_time = SDL_GetTicks();
    if (last_time - timeBuff[x][y] > 3000) {
        map[x][y] = EMPTY;
    }
}

//ˢ�µ�ͼͼ��
void Map::refresh(double deltaTime)
{
    for (unsigned int i = 0; i < map.max_size(); i++)
    {
        for (unsigned int j = 0; j < map[i].max_size(); j++)
        {
            if (map[i][j] == DANGER)        //��ը�������0.5���ؿտ�
            {
                if (SDL_GetTicks() - timeBuff[i][j] > 500)
                {
                    map[i][j] = EMPTY;
                }
            }

            SDL_Rect emptyTexturePos = { j * 40, (i + 1) * 40, 40, 40 };
            SDL_Rect destructibleTexturePos = { j * 40 , (i + 1) * 40 - 11, 40, 51 };
            SDL_Rect undestructibleTexturePos = { j * 40 , (i + 1) * 40 - 40, 40, 80 };
            SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("empty.png"), nullptr, &emptyTexturePos);
            switch (map[i][j])
            {
            default:
                break;
            case DESTRUCTIBLE:
                SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("destructible.png"), nullptr, &destructibleTexturePos);
                break;
            case UNDESTRUCTIBLE:
                SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("undestructible.png"), nullptr, &undestructibleTexturePos);
                break;
            case DANGER:
                SDL_RenderCopy(mainWindow->getRender(), mainWindow->loadPicture("danger.png"), nullptr, &emptyTexturePos);
                break;
            }
        }
    }
}

/*
Map date in the mapdate.txt

*/

