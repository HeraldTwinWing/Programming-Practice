#pragma once

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPYT,DANGER,BOMB
};

class Map
{
private:
    BlockTypeEnum map[12][12];
public:
    Map();

    //���ļ����ص�ͼ
    void loadMap();

    //ˢ�µ�ͼͼ��
    void refresh();
};

