#include "Map.h"
Map:: Map():map(), map_time()
{
	for (auto &i : map)
	{
		for (auto &j : i)
		{
			j = EMPYT;
		}
   }
	for (auto& i : map_time)
	{
		for (auto& j : i)
		{
			j = 0;
		}
	}
}
/*Uint32 Map::my_fun(Uint32 interval) {
	return interval;
}


//从文件加载地图*/
void Map::loadMap() 
{
	fstream file("C:\\Users\\areswf\\source\\repos\\Programming-Practice\\Programming Practice\\mapdata.txt", ios::in);
	if (file.fail()){ 
		std::cout << "Cannot open the file\n";
		exit(2);
	}
	char ch;
	for (int i = 0; i < 13&&!file.eof(); i++) {
		for (int j = 0; j < 15; j++) {
			ch = file.get();
			switch (ch)
			{
			case '0':map[i][j] = DESTRUCTIBLE;
				break;
			case '1':map[i][j] = UNDESTRUCTIBLE;
				break;
			case '2':map[i][j] = EMPYT;
				break;
			case '3':map[i][j] = DANGER;
				break;
			case '4':map[i][j] = BOMB;
				break;
			default:
				break;
			}	
		}
	}
	file.close();
	return;
   
   
}


//检查数组越界情况以及炸弹周围的地图变化情况
bool Map::Judge(int x, int y) {
	if (!(x >= 0 && x < 13 && y >= 0 && y < 15))
		return false;
	if (map[x][y] == DESTRUCTIBLE) {
		map_time[x][y] = SDL_GetTicks();
		map[x][y] = DANGER;
		double lastime = SDL_GetTicks();
		if (lastime - map_time[x][y] > 500) {
			map[x][y] = EMPYT;
		}
		return true;
	}
	else return false;
}
//炸弹位置的地图变化
void Map::Bomb_change(int x, int y) {
	map_time[x][y] = SDL_GetTicks();
	map[x][y] =BOMB;
	double last_time = SDL_GetTicks();
	if (last_time - map_time[x][y] > 3000) {
		map[x][y] = EMPYT;
	}
}

//刷新地图图像
void Map::refresh(int x, int y, bool boom) {
	if (boom)
	{
		Bomb_change(x, y);
		if (Judge(x - 1, y)) {
			bool a=Judge(x - 2, y);
		}
		else if (Judge(x + 1, y)) {
			bool a = Judge(x + 2, y);
		}
		else if (Judge(x, y - 1)) {
			bool a = Judge(x, y - 2);
		}
		else if (Judge(x, y + 1)) {
			bool a = Judge(x, y + 2);
		}
		
	}
	else {
		bool a=Judge(x - 1, y);
		a=Judge(x + 1, y);
		a=Judge(x, y - 1);
		a=Judge(x, y + 1);
	}
}








/*
Map date in the mapdate.txt

*/

