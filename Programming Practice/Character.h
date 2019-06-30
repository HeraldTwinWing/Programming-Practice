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
	//移动速度，每秒移动的像素（每秒40个像素）
    int speed;        

	//上下左右移动状态
	bool moving[4] = { false,false,false,false };
	double lastMove;
	//保存左右、上下位移的小数部分
    std::pair<double,double> moveTemp;  

	//炸弹

	bool set;

	//击中判定

	//bool damage_amount;

	//坐标与大小
	SDL_Point Character_position;  //人物的位置
	SDL_Texture *texture = nullptr;
	SDL_Rect position;

	//人物所在渲染层
	Window *window = nullptr;
public:
	Character();

	//生成单位
	virtual void spaw();

	/*控制人物的移动
	 *该方法输入移动方向
	 *根据速度控制人物的坐标向该方向改变
	 * */
	virtual void move(Map &NowMap);

	////判断是否在炸弹范围内
	//bool Judge(Map& map);

	//被炸弹炸死
	//true则返回true，否则返回false
	virtual bool damage(bool damage_amount);

	/*拾取道具
	 *拾取道具后改变当前属性
	 * */
	void change_nature();                     //缺少道具？

	/*放置炸弹
	 **/
	virtual void setbomb();                   //?

	//刷新人物状态
	virtual void refresh();
	virtual void showImage();
	
	//处理与玩加人物相关事件
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

