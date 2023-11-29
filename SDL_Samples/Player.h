#pragma once
#include <SDL.h>

class Player
{
private:
	int x, y;	//��ǥ
	int life, health;	//���, ü��
	int speed, power, item;	//�ӵ�, ����, ������ ��뷮

public:
	Player(int getX, int getY);
	~Player();
	void PlayerMove(int x, int y);
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
	void HasItem();
};