#pragma once
#include <array>
#include <string>
#include "Map.h"
//written by imaginicleo

class AI
{
public:
	//声明类成员
	std::string textureName;//记录贴图文件路径
	bool map[13][15];//地图数据，以二维数组形式储存
	std::array<bool, 4> movingFlags = { false,false,false,false };
	/*
	*记录移动状态的标志
	*movingFlags[0] 向上
	*movingFlags[1] 向下
	*movingFlags[2] 向左
	*movingFlags[3] 向右
	*/
	int x_coordinate;//横坐标
	int y_coordinate;//纵坐标
	int currentLine;//记录当前所在行
	int currentRow;//记录当前所在列
	int radiation;//记录爆炸半径（其实是十字形），初始化的时候传入默认值1
	double moveSpeed;//记录移动速度，初始化的时候传入默认值20.0
	int restBombNum;//记录炸弹数量，初始化的时候传入默认值1
	//声明成员函数
	AI(std::string textureName, int x, int y, int rad = 1, double speed = 20.0, int bombnum = 1);//构造函数，测试用
	void moveAI();
	void detectPath();//遍历地图 将地图数据转换成布尔二维数组
	void findWay();

};

