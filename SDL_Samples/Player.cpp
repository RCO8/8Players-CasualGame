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

Player::~Player()
{
	general->~Sprite();
}

void Player::SetPlayerSprite(SDL_Renderer *getRend, const char* filename)
{
	general = new Sprite(getRend, filename);
	SetFrameClip();
	general->SetSpriteClip(frames[0]);
	general->SetColorHide(0, 255, 0);
}

void Player::CheckMove(int x, int y)	//입력판정에 따라 이동 조치
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

void Player::DrawPlayer()
{
	if (general)
	{
		general->Drawing(x, y, 0);
	}
}

void Player::CheckLife()
{
	if (life == 0)
	{
		SDL_Log("Game Over");
	}
}

void Player::SetFrameClip()
{	//프레임 인덱스별로 사각형 클립 지정
	frames[0] = { 0,0,16,24 };
}