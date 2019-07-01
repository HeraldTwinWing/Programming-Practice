#pragma once
#include<SDL.h>
#include <array>
#include <string>
#include <utility>
#include <fstream>
#include "Window.h"

enum BlockTypeEnum
{
     OUTRANGE = -1,     //地图外
     DESTRUCTIBLE,      //可破坏方块
     UNDESTRUCTIBLE,    //不可破坏方块
     BOMB,              //炸弹 
     EMPTY,             //空地 
     DANGER             //爆炸区域
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
    BlockTypeEnum& getBlockReference(int x, int y);     //防止混淆的访问方式
    void setBombBlock(int x, int y);
    void setDangerBlock(int x, int y);

    bool destruct(int x, int y);
    void destructBlock(int x, int y);

    //从文件加载地图
    void loadMap();

	//刷新地图图像
	void refresh(double deltaTime);
	void Bomb_change(int x, int y);//

};

extern Map* map;