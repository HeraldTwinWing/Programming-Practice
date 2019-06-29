#pragma once
#include <array>
#include <string>
//written by imaginicleo

class AI
{
public:
	//声明类成员
	std::string textureName;
	std::array<bool, 4> movingFlags = { false,false,false,false };
	/*
	*记录移动状态的标志
	*movingFlags[0] 向上
	*movingFlags[1] 向下
	*movingFlags[2] 向左
	*movingFlags[3] 向右
	*/
	int x_coordinate;
	int y_coordinate;
	int radiation;//记录爆炸半径（其实是十字形），初始化的时候传入默认值1
	double moveSpeed;//记录移动速度，初始化的时候传入默认值20.0
	int restBombNum;//记录炸弹数量，初始化的时候传入默认值1
	//声明成员函数
	AI(std::string textureName, int x, int y, int rad = 1, double speed = 20.0, int bombnum = 1);//构造函数，测试用
	void moveAI();
	

};

