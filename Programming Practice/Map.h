#pragma once

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT
};

class Map
{
private:
    BlockTypeEnum map[13][15];
public:
    Map();

    //���ļ����ص�ͼ
    void loadMap();

    //ˢ�µ�ͼͼ��
    void refresh();
};

