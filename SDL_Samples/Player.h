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
	void HasItem();
};