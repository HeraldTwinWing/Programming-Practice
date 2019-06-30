#pragma once
#include<SDL.h>
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
    std::array<std::array<BlockTypeEnum, 15>, 13> map;  //访问方式map[y][x]
    std::array<std::array<double, 15>, 13> timeBuff;
public:
	Map();
	bool Judge(int x, int y);

    std::array<std::array<BlockTypeEnum, 15>, 13>& getMap();
    
    BlockTypeEnum judgeBlockType(int x, int y);

    bool destruct(int x, int y);

    //从文件加载地图
    void loadMap();

	//刷新地图图像
	void refresh(int x, int y, bool boom);
	void Bomb_change(int x, int y);//

};

extern Map* map;