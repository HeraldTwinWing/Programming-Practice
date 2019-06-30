#pragma once

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT,DANGER,BOMB//DAGER 为爆炸波及范围，BOMB为炸弹位置
};

class Map
{
private:
    BlockTypeEnum map[13][15];
public:
    Map();
	Map(int a);
	static char MapDate[13][15];

    //从文件加载地图
    void loadMap();

    //刷新地图图像
    void refresh(int x,int y,bool boom);
};

