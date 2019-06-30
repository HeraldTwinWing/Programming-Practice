#pragma once
#include<iostream>
#include<cstdio>
#include<fstream>
#include<array>
#include<SDL.h>
using namespace std;
enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT,DANGER,BOMB//DAGER 为爆炸波及范围，BOMB为炸弹位置
};

class Map
{
private:
	std::array<std::array<BlockTypeEnum, 15>, 13> map;
	std::array<std::array<double, 15>, 13>map_time;
public:
	Map();
	bool Judge(int x, int y);

	//从文件加载地图
	void loadMap();
	//时间间隔
	//Uint32 my_fun(Uint32 interval);

	//刷新地图图像
	void refresh(int x, int y, bool boom);
	void Bomb_change(int x, int y);//
	void Show() {
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 15; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;

		}
			

	}
};

