#pragma once
#include<SDL.h>
#include <array>
#include <string>
#include <utility>
#include <fstream>
#include "Window.h"

enum BlockTypeEnum
{
     OUTRANGE = -1,     //��ͼ��
     DESTRUCTIBLE,      //���ƻ�����
     UNDESTRUCTIBLE,    //�����ƻ�����
     BOMB,              //ը�� 
     EMPTY,             //�յ� 
     DANGER             //��ը����
};

class Map
{
private:
    std::array<std::array<BlockTypeEnum, 15>, 13> map;  //���ʷ�ʽmap[y][x]
    std::array<std::array<double, 15>, 13> timeBuff;
public:
	Map();
	bool Judge(int x, int y);

    std::array<std::array<BlockTypeEnum, 15>, 13>& getMap();
    
    BlockTypeEnum judgeBlockType(int x, int y);
    BlockTypeEnum& getBlockReference(int x, int y);     //��ֹ�����ķ��ʷ�ʽ
    void setBombBlock(int x, int y);
    void setDangerBlock(int x, int y);

    bool destruct(int x, int y);
    void destructBlock(int x, int y);

    //���ļ����ص�ͼ
    void loadMap();

	//ˢ�µ�ͼͼ��
	void refresh(double deltaTime);
	void Bomb_change(int x, int y);//

};

extern Map* map;