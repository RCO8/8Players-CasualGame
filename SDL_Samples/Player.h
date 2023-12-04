#pragma once
#include <SDL.h>
#include "Sprite.h"

class Player
{
private:
	const int StartX, StartY;	//시작할 때 또는 리스폰 위치
	int x, y;	//좌표
	int life, health;	//목숨, 체력
	int speed, power, item;	//속도, 위력, 아이템 사용량

	int moveX, moveY;	//이동을 위한 입력체크

	//Sprite controll
	Sprite* general;
	SDL_Rect frames[20];	//프레임 클립
	int nowFrame;	//현재 프레임
public:
	Player(int getX, int getY);
	~Player();
	void SetPlayerSprite(SDL_Renderer *getRend, const char* filename);
	void CheckMove();
	void Damaged(int h);
	void PowerUp(int opt);	// {1:speed, 2:power, 3:item}
	void HasItem();
	void SetFrame(int f) { nowFrame = f; }	//프레임 설정
	int GetPosition(bool p) { return p ? x : y; }	//true = x, false = y

	void InputX(int x) { moveX = x; }	//X축 입력
	void InputY(int y) { moveY = y; }	//Y축 입력

	void DrawPlayer();
private:
	void CheckLife();	//목숨검사
	void SetFrameClip();	//고정으로 프레임의 클립 지정
};