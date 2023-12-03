#pragma once
#include <SDL.h>
#include "Sprite.h"

class Player
{
private:
	const int StartX, StartY;	//������ �� �Ǵ� ������ ��ġ
	int x, y;	//��ǥ
	int life, health;	//���, ü��
	int speed, power, item;	//�ӵ�, ����, ������ ��뷮
	Sprite* general;
	SDL_Rect* frames;
public:
	Player(int getX, int getY);
	~Player();
	void SetPlayerSprite(SDL_Renderer *getRend, const char* filename);
	void CheckMove(int x, int y);
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
	void HasItem();

	int GetPosition(bool p)
	{	
		return p ? x : y;	//true = x, false = y
	}

	void DrawPlayer();
private:
	void CheckLife();	//����˻�
	void SetFrameClip();	//�������� �������� Ŭ�� ����
};