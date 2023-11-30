#include "Player.h"

Player::Player(int getX, int getY) : StartX(getX), StartY(getY)
{
	this->x = StartX;
	this->y = StartY;

	//이 속성들은 캐릭터를 생성할 때 기본적인 값들이다.
	life = 3;
	health = 20;
	speed = 1;
	power = 1;
	item = 1;

	//스프라이트 설정
}

void Player::PlayerMove(int x, int y)
{
	//화면 밖으로 나가지 않거나 벽을 지나가지 못하게 추가
	this->x += x;
	this->y += y;
}

void Player::Damaged(int h)
{
	health -= h;
	if (health <= 0)	//health가 0이면 life 1감소
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
	//아이템을 사용 
}