#pragma once
#include <array>

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPTY, DANGER, BOMB
};

class Map
{
private:
    std::array<std::array<BlockTypeEnum, 15>, 13> map;
public:
    Map();

    std::array<std::array<BlockTypeEnum, 15>, 13>& getMap();
    
    //从文件加载地图
    void loadMap();

    //刷新地图图像
    void refresh();
};

