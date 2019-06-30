#pragma once
#include <array>

enum BlockTypeEnum
{
     DESTRUCTIBLE, UNDESTRUCTIBLE, EMPTY, DANGER, BOMB, WATERWILLEXIST //"WATERWILLEXIST"��ը������ʱ��¼��ը�뾶������AI�ж���
};

class Map
{
private:
    std::array<std::array<BlockTypeEnum, 15>, 13> map;
public:
    Map();

    std::array<std::array<BlockTypeEnum, 15>, 13>& getMap();
    
    //���ļ����ص�ͼ
    void loadMap();

    //ˢ�µ�ͼͼ��
    void refresh();
};

