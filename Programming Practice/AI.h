#pragma once
#include <array>
#include <vector>
#include <string>
#include "Map.h"
#include "Character.h"
//written by imaginicleo

class AI:public Character
{
public:
	//�������Ա
	std::string textureName;//��¼��ͼ�ļ�·��
	std::array<std::array<BlockTypeEnum, 13>, 15> currentMap;
	bool map[15][13];//��ͼ���ݣ��Զ�ά������ʽ����
	std::array<bool, 4> movingFlags = { false,false,false,false };
	/*
	*��¼�ƶ�״̬�ı�־
	*movingFlags[0] ����
	*movingFlags[1] ����
	*movingFlags[2] ����
	*movingFlags[3] ����
	*/
	int x_coordinate;//������
	int y_coordinate;//������
	int currentLine;//��¼��ǰ������
	int currentRow;//��¼��ǰ������
	int radiation;//��¼��ը�뾶����ʵ��ʮ���Σ�����ʼ����ʱ����Ĭ��ֵ1
	double moveSpeed;//��¼�ƶ��ٶȣ���ʼ����ʱ����Ĭ��ֵ20.0
	int restBombNum;//��¼ը����������ʼ����ʱ����Ĭ��ֵ1
	//������Ա����
	AI(std::string textureName, int x, int y, std::array<std::array<BlockTypeEnum, 15>, 13> & Map, int rad = 1, double speed = 20.0, int bombnum = 1);//���캯����������

	void controlAI();
	void moveAI();
	void moveByGrid(int gridnum);
	void detectPath();//������ͼ������ͼ����ת���ɲ�����ά���顣���ߵ�·��Ϊtrue�������ߵ�·��Ϊfalse��
	void findPath(std::string option);

};

