#pragma once
#include<SDL.h>
#include<string>
#include<utility>
#include<deque>
#include<memory>
#include<cmath>
#include"SDL_keyboard.h"
#include"Window.h"
#include"GameEvent.h"
#include"bomb.h"
#include"Map.h"
class Character
{
private:
	//�ƶ��ٶȣ�ÿ���ƶ������أ�ÿ��40�����أ�
    int speed;        

	//���������ƶ�״̬
	bool moving[4] = { false,false,false,false };
	double lastMove;
	//�������ҡ�����λ�Ƶ�С������
    std::pair<double,double> moveTemp;  

	//ը��

	bool set;

	//�����ж�

	//bool damage_amount;

	//�������С
	SDL_Point Character_position;  //�����λ��
	SDL_Texture *texture = nullptr;
	SDL_Rect position;

	//����������Ⱦ��
	Window *window = nullptr;
public:
	Character();

	//���ɵ�λ
	virtual void spaw();

	/*����������ƶ�
	 *�÷��������ƶ�����
	 *�����ٶȿ��������������÷���ı�
	 * */
	virtual void move(Map &NowMap);

	////�ж��Ƿ���ը����Χ��
	//bool Judge(Map& map);

	//��ը��ը��
	//true�򷵻�true�����򷵻�false
	virtual bool damage(bool damage_amount);

	/*ʰȡ����
	 *ʰȡ���ߺ�ı䵱ǰ����
	 * */
	void change_nature();                     //ȱ�ٵ��ߣ�

	/*����ը��
	 **/
	virtual void setbomb();                   //?

	//ˢ������״̬
	virtual void refresh();
	virtual void showImage();
	
	//�����������������¼�
	void keyDownEvent1(SDL_Keycode sym);
	void keyDownEvent2(SDL_Keycode sym);
	void keyUpEvent1(SDL_Keycode sym);
	void keyUpEvent2(SDL_Keycode sym);
	bool if_setBomb()
	{
		return set;
	}

	//virtual bool if_not_
    
};

