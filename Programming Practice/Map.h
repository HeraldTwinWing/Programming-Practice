#pragma once

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT,DANGER,BOMB//DAGER Ϊ��ը������Χ��BOMBΪը��λ��
};

class Map
{
private:
    BlockTypeEnum map[13][15];
public:
    Map();
	Map(int a);
	static char MapDate[13][15];

    //���ļ����ص�ͼ
    void loadMap();

    //ˢ�µ�ͼͼ��
    void refresh(int x,int y,bool boom);
};

