#pragma once
#include <array>
#include <string>
#include "Map.h"
//written by imaginicleo

class AI
{
public:
	//�������Ա
	std::string textureName;//��¼��ͼ�ļ�·��
	bool map[13][15];//��ͼ���ݣ��Զ�ά������ʽ����
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
	AI(std::string textureName, int x, int y, int rad = 1, double speed = 20.0, int bombnum = 1);//���캯����������
	void moveAI();
	void detectPath();//������ͼ ����ͼ����ת���ɲ�����ά����
	void findWay();

};

