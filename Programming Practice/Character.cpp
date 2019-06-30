#include "Character.h"
#include<cmath>

Character::Character()
{

	this->Character_position.x = position.x + 20;
	this->Character_position.y = position.y + 20;

	lastMove = SDL_GetTicks();
};
void Character::spaw()
{
	SDL_RenderCopy(window->getRender(), texture, nullptr, &position);
}


void Character::move(Map &NowMap)
{
	int i = (int)position.y / 40;
	int j = (int)position.x / 40;
	double timeLenth = 0.001*(SDL_GetTicks() - lastMove);
	if (moving[0] && position.y >= 0 && (i-1)>=0 && NowMap.loadMap[i-1][j] == EMPYT)
	{
		moveTemp.second -= speed * timeLenth;
	}
	if (moving[1] && position.y <= 480 && (i+1))<=480 NowMap.loadMap[i+1][j] == EMPYT)
	{
		moveTemp.second += speed * timeLenth;
	}
	if (moving[2] && position.x >= 0 && (j-1)>=0 && NowMap.loadMap[i][j-1] == EMPYT)
	{
		moveTemp.first -= speed * timeLenth;
	}
	if (moving[3] && position.x <= 560 && (j+1)<=560 NowMap.loadMap[i][j+1] == EMPYT)
	{
		moveTemp.first += speed * timeLenth;
	}

	if (std::abs(moveTemp.first) > 1)
	{
		position.x += (int)std::trunc((float)moveTemp.first);
		moveTemp.first = std::trunc((float)moveTemp.first);
	}
	if (std::abs(moveTemp.second) > 1)
	{
		position.y += (int)std::trunc((float)moveTemp.second);
		moveTemp.second = std::trunc((float)moveTemp.first);
	}

	lastMove = SDL_GetTicks();
}

//bool Character::Judge(Map& Nmap)
//{
//	int i = (int)position.x / 40 ;
//	int j = (int)position.y / 40;
//	if (Nmap.map[i][j] == DANGER)
//	{
//		this->damage_amount = true;
//	}
//}

bool Character::damage(bool damage_amount)
{
	if (damage_amount == true)
	{
		return true;
	}
}

void Character::refresh()
{
	move();

	//还有炸弹的位置

	showImage();
}

void Character::showImage()
{
	SDL_RenderCopy(window->getRender(), texture, nullptr, &position);
}

void Character::keyDownEvent1(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_w:
		moving[0] = true;
		moving[1] = false;
		break;
	case SDLK_s:
		moving[1] = true;
		moving[0] = false;
		break;
	case SDLK_a:
		moving[2] = true;
		moving[3] = false;
		break;
	case SDLK_d:
		moving[3] = true;
		moving[2] = false;
		break;
	case SDLK_SPACE:
		set = true;
	default:
		break;
	}
}

void Character::keyUpEvent1(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_w:
		moving[0] = false;
		break;
	case SDLK_s:
		moving[1] = false;
		break;
	case SDLK_a:
		moving[2] = false;
		break;
	case SDLK_d:
		moving[3] = false;
		break;
	case SDLK_SPACE:
		set = false;
	default:
		break;
	}
}
void Character::keyDownEvent2(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_UP:
		moving[0] = true;
		moving[1] = false;
		break;
	case SDLK_DOWN:
		moving[1] = true;
		moving[0] = false;
		break;
	case SDLK_LEFT:
		moving[2] = true;
		moving[3] = false;
		break;
	case SDLK_RIGHT:
		moving[3] = true;
		moving[2] = false;
		break;
	case SDLK_KP_ENTER:
		set = true;
	default:
		break;
	}
}

void Character::keyUpEvent2(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_UP:
		moving[0] = false;
		break;
	case SDLK_DOWN:
		moving[1] = false;
		break;
	case SDLK_LEFT:
		moving[2] = false;
		break;
	case SDLK_RIGHT:
		moving[3] = false;
		break;
	case SDLK_KP_ENTER:
		set = false;
	default:
		break;
	}
}

Character::Character()
{
};