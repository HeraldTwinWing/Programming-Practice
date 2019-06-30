#include "AI.h"



AI::AI(std::string textureName, int x, int y, std::array<std::array<BlockTypeEnum, 13>, 15> & Map, int rad, double speed, int bombnum)
{
	this->textureName = textureName;
	this->x_coordinate = x;
	this->y_coordinate = y;
	this->radiation = rad;
	this->moveSpeed = speed;
	this->restBombNum = bombnum;
	this->currentLine = x_coordinate % 40 + 1;
	this->currentRow = y_coordinate % 40 + 1;
	this->currentMap = Map;
}

void AI::controlAI()
{
	detectPath();
}

void AI::moveAI()
{
	if (movingFlags[0])
	{
		y_coordinate -= moveSpeed;
	}
	if (movingFlags[1])
	{
		y_coordinate += moveSpeed;
	}
	if (movingFlags[2])
	{
		x_coordinate -= moveSpeed;
	}
	if (movingFlags[3])
	{
		x_coordinate += moveSpeed;
	}
}

void AI::moveByGrid(int gridnum)
{
	
}

void AI::detectPath()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13;j++)
		{
			if (currentMap[i][j] == UNDESTRUCTIBLE || currentMap[i][j] == DANGER || currentMap[i][j] == BOMB || currentMap[i][j] == WATERWILLEXIST)
			{
				map[i][j] = fals+e;
			}
		}
	}
}

void AI::judgeAvailable()
{
	if (grid.first == 0)
	{
		if()
	}
}

void AI::findPath(std::string option)
{
	/*
	*目的：使用BFS（宽度优先算法）来算出可移动路径
	*/
	
	std::pair<int, int> temp;
	if (grid.first == 0)
	{
		
	}
}


