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

	moveX = 0;
	moveY = 0;

	//��������Ʈ ����
	nowFrame = 1;
}

Player::~Player()
{
	general->~Sprite();
}

void Player::SetPlayerSprite(SDL_Renderer *getRend, const char* filename)
{
	general = new Sprite(getRend, filename);
	SetFrameClip();
	general->SetSpriteClip(frames[1]);
	general->SetColorHide(0, 255, 33);
}

void Player::CheckMove()	//�Է������� ���� �̵� ��ġ
{
	if (moveX > 0 && this->x <= 720 - general->GetClipWidth())
		this->x += speed;
	else if (moveX < 0 && this->x >= 0)
		this->x -= speed;
	else if (moveY > 0 && this->y <= 640 - general->GetClipHeight())
		this->y += speed;
	else if (moveY < 0 && this->y >= 0)
		this->y -= speed;
	SDL_Delay(30);
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
	//�������� ��� 
}

void Player::DrawPlayer()
{
	if (general)
	{
		general->SetSpriteClip(frames[nowFrame]);
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
{	//������ �ε������� �簢�� Ŭ�� ����
	frames[0] = { 0,1,15,22 };
	frames[1] = { 17,1,15,22 };
	frames[2] = { 33,1,15,22 };
}