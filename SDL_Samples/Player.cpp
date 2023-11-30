#include "Player.h"

Player::Player(int getX, int getY) : StartX(getX), StartY(getY)
{
	this->x = StartX;
	this->y = StartY;

	//�� �Ӽ����� ĳ���͸� ������ �� �⺻���� �����̴�.
	life = 3;
	health = 20;
	speed = 1;
	power = 1;
	item = 1;

	//��������Ʈ ����
}

void Player::PlayerMove(int x, int y)
{
	//ȭ�� ������ ������ �ʰų� ���� �������� ���ϰ� �߰�
	this->x += x;
	this->y += y;
}

void Player::Damaged(int h)
{
	health -= h;
	if (health <= 0)	//health�� 0�̸� life 1����
	{
		life--;
		health = 20;
		this->x = StartX;
		this->y = StartY;
	}
}

void Player::PowerUp(int opt)
{
	switch (opt)
	{
	case 1:	//speed up
		if(speed <= 3)
			speed++;
		break;
	case 2:	//power up
		if (power <= 3)
			power++;
		break;
	case 3:	//item up
		if (item <= 3)
			item++;
		break;
	}
}

void Player::HasItem()
{
	//�������� ��� 
}