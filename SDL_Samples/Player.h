#pragma once
#include <SDL.h>
#include "Sprite.h"

class Player
{
private:
	const int StartX, StartY;	//시작할 때 또는 리스폰 위치
	int x, y;	//좌표
	int moveX = 0, moveY = 0;
	int life, health;	//목숨, 체력
	int speed, power, item;	//속도, 위력, 아이템 사용량
	
public:
	Player(int getX, int getY);
	~Player();
	void CheckMove(int x, int y);
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
	void HasItem();

	int GetPosition(bool p)
	{	
		return p ? x : y;	//true = x, false = y
	}
private:
	void CheckLife();	//목숨검사
};