#pragma once

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT
};

class Map
{
private:
    BlockTypeEnum map[13][15];
public:
    Map();

    //从文件加载地图
    void loadMap();

    //刷新地图图像
    void refresh();
};

