#include "AI.h"

AI::AI(std::string textureName, int x, int y, int rad, double speed, int bombnum)
{
	this->textureName = textureName;
	this->x_coordinate = x;
	this->y_coordinate = y;
	this->radiation = rad;
	this->moveSpeed = speed;
	this->restBombNum = bombnum;
	this->currentLine = x_coordinate % 40 + 1;
	this->currentRow = y_coordinate % 40 + 1;
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

void AI::detectBomb()
{

}

void AI::findWay()
{
	for 
}

