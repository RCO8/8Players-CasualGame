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

	int moveX, moveY;	//�̵��� ���� �Է�üũ

	//Sprite controll
	Sprite* general;
	SDL_Rect frames[20];	//������ Ŭ��
	int nowFrame;	//���� ������
public:
	Player(int getX, int getY);
	~Player();
	void SetPlayerSprite(SDL_Renderer *getRend, const char* filename);
	void CheckMove();
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
	void HasItem();
	void SetFrame(int f) { nowFrame = f; }	//������ ����
	int GetPosition(bool p) { return p ? x : y; }	//true = x, false = y

	void InputX(int x) { moveX = x; }	//X�� �Է�
	void InputY(int y) { moveY = y; }	//Y�� �Է�

	void DrawPlayer();
private:
	void CheckLife();	//����˻�
	void SetFrameClip();	//�������� �������� Ŭ�� ����
};