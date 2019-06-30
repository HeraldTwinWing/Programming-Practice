#pragma once
#include <array>
#include <string>
#include <utility>
#include <fstream>

enum BlockTypeEnum
{
     OUTRANGE = -1, DESTRUCTIBLE, UNDESTRUCTIBLE, EMPTY, DANGER, BOMB
};

class Map
{
private:
    std::array<std::array<BlockTypeEnum, 15>, 13> map;
    std::array<std::array<double, 15>, 13> timeBuff;
public:
    Map();

    std::array<std::array<BlockTypeEnum, 15>, 13>& getMap();
    
    BlockTypeEnum judgeBlockType(int x, int y);

    //���ļ����ص�ͼ
    void loadMap();

    //ˢ�µ�ͼͼ��
    void refresh();
};

extern Map* map;