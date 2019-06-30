#pragma once
#include <array>

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPTY, DANGER, BOMB, WATERWILLEXIST //"WATERWILLEXIST"在炸弹放下时记录爆炸半径，方便AI判定。
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

