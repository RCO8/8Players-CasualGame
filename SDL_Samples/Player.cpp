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

void Player::CheckMove(int x, int y)
{
	this->x += speed * x;
	this->y += speed * y;
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
	CheckLife();
}

void Player::CheckLife()
{
	if (life == 0)
	{
		SDL_Log("Game Over");
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