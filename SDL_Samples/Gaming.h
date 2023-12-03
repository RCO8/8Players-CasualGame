#pragma once
#include <SDL.h>
#include "Sprite.h"
#include "Timer.h"
#include "UI.h"
#include "Sound.h"
#include "Joystick.h"
#include "Player.h"

class Gaming
{
private:
    bool quit = false;
    SDL_Window* window; //SDL â
    SDL_Renderer* renderer; //â�� �׸� ����
    SDL_Event event;    //�Է� �̺�Ʈ

    Joystick* playerContoll;
    Player* players[8]; //�÷��̾�
    int inputHorizon = 0;
    int inputVertical = 0;
public:
    bool GameInit();    //���� ���۽� �⺻���� ����
    void GameRun();     //���� ������
    void GameOff();     //���� ����
private:
    void CheckKeyPress();	//Ű �̺�Ʈ Ȯ��
    void DrawScreen();		//���ȭ�� �׸���
    void UpdateData();      //���� ������ �� ���� ����
};