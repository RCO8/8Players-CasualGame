#pragma once
#include <SDL.h>

class Player
{
private:
	int x, y;	//좌표
	int life, health;	//목숨, 체력
	int speed, power, item;	//속도, 위력, 아이템 사용량

public:
	Player(int getX, int getY);
	~Player();
	void PlayerMove(int x, int y);
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
};

Player::Player(int getX, int getY)
{
	x = getX;
	y = getY;
	SDL_Log("X : %d, Y : %d", x, y);
	life = 3;
	health = 20;
	speed = 1;
	power = 1;
	item = 1;
}

Player::~Player()
{

}

void Player::PlayerMove(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Player::Damaged(int h)
{
	health -= h;
	if (health < 0)
	{
		life--;
		//원위치로
		health = 20;
	}
}

void Player::PowerUp(int opt)
{
	switch (opt)
	{
	case 1:
		if (speed < 3) speed++; break;
	case 2:
		if (power < 3) power++; break;
	case 3:
		if (item < 3) item++; break;
	default:
		break;
	}
}