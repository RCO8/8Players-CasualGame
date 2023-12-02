#include "Gaming.h"

const int windowWidth = 720;
const int windowHeight = 640;

bool Gaming::GameInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("8Players Action", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        SDL_Log("Failed Init Window : %s \n", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        SDL_Log("Failed Init Renderer : %s", SDL_GetError());
        return false;
    }

    //Resouce Setting
    SDL_Color bgImgColor = { 255,255,255 };
    players[0] = new Player(0, 0);
    SDL_Color hideSprite = { 0,255,0 };
    playerSprite[0] = new Sprite(renderer, "Bomberman.png");
    playerSprite[0]->SetSpriteClip(0, 1, 15, 22);
    playerSprite[0]->SetColorHide(hideSprite);
    return true;
}

void Gaming::CheckKeyPress()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: quit = true; break;
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_MINIMIZED: //SDL_Log("Window Minimize");
                break;
            case SDL_WINDOWEVENT_ENTER:     //SDL_Log("Window Inside");
                break;
            case SDL_WINDOWEVENT_LEAVE:     //SDL_Log("Window Outside");
                break;
            case SDL_WINDOWEVENT_MOVED:     //SDL_Log("Window : (%d, %d)", event.window.data1, event.window.data2 - 31);  //�̵��� â�� ��ǥ�� ���
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:  //SDL_Log("Window Enable");
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:    //SDL_Log("Window Disable");
                break;
            case SDL_WINDOWEVENT_CLOSE: quit = true; break;
            }

            //Keyboard Check
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_UP:       //SDL_Log("Up");
                if (0 < players[0]->GetPosition(false))
                    players[0]->CheckMove(0, -2);
                break;
            case SDL_SCANCODE_DOWN:     //SDL_Log("Down");
                if(windowHeight - playerSprite[0]->GetClipHeight() > players[0]->GetPosition(false))
                    players[0]->CheckMove(0, 2);
                break;
            case SDL_SCANCODE_LEFT:     //SDL_Log("Left");
                if(0 < players[0]->GetPosition(true))
                    players[0]->CheckMove(-2, 0);
                break;
            case SDL_SCANCODE_RIGHT:    //SDL_Log("Right");
                if(windowWidth - playerSprite[0]->GetClipWidth() > players[0]->GetPosition(true))
                    players[0]->CheckMove(2, 0);
                break;
            case SDL_SCANCODE_RETURN:   //SDL_Log("Enter");
                break;
            case SDL_SCANCODE_SPACE:    //SDL_Log("Space");
                break;
            case SDL_SCANCODE_LSHIFT:   //SDL_Log("Shift");
                break;
            case SDL_SCANCODE_LCTRL:    //SDL_Log("Ctrl");
                break;
            case SDL_SCANCODE_LALT:     //SDL_Log("Alt");
                break;
            case SDL_SCANCODE_F1:       //SDL_Log("F1");
                break;
            case SDL_SCANCODE_W:        //SDL_Log("W");
                break;
            case SDL_SCANCODE_S:        //SDL_Log("S");
                break;
            case SDL_SCANCODE_A:        //SDL_Log("A");
                break;
            case SDL_SCANCODE_D:        //SDL_Log("D");
                break;
            case SDL_SCANCODE_ESCAPE:   //SDL_Log("Escape");
                break;
            }
        case SDL_KEYUP:
            switch (event.key.keysym.scancode)  //Same to SDL_KEYDOWN
            {
            case SDL_SCANCODE_LEFT:     
            case SDL_SCANCODE_RIGHT:
                break;
            }
            break;

            //Mouse Check
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case 1: //SDL_Log("Left Mouse");
                break;
            case 2: //SDL_Log("Middle Mouse");
                break;
            case 3: //SDL_Log("Right Mouse");
                break;
            }
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button) //Same to SDL_MOUSEBUTTONDOWN
            {
            case 1:
            case 2:
            case 3:
                break;
            }
        case SDL_MOUSEMOTION: //SDL_Log("Mouse : (%d, %d)", event.motion.x, event.motion.y);
            break;
        case SDL_MOUSEWHEEL:
            switch (event.wheel.y)
            {
            case 1:     //SDL_Log("Wheel Up");
                break;
            case -1:    //SDL_Log("Wheel Down");
                break;
            }

            //Controller Check (Console version)
        case SDL_CONTROLLERDEVICEADDED: //if Controller is connected
            // Joystick ������ ȣ��
            break;
        }

        //�߰����� �Է� ����̽��� �ִٸ� ����� �޼��� ȣ��
        playerContoll->CheckJoystickEvent(event, *players[0]);
    }
}
void Gaming::UpdateData()
{
    //���� �� ������ �����͸� ���⿡ ����
    //���࿡ �̺�Ʈ�� ������ ���� �ʴ´ٸ�
    //mTimer.StartCount();
    SDL_Delay(100);
}
void Gaming::DrawScreen()   //Drawing Sprite or UI in this Screen
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
    SDL_RenderClear(renderer);  //Screen Clear   //Fill Color in Screen
    
    //Draw Image
    playerSprite[0]->Drawing(players[0]->GetPosition(true), players[0]->GetPosition(false), 0);
    //Draw UI

    SDL_RenderPresent(renderer);    //Redraw at Screen
}

void Gaming::GameRun()
{
    while (!quit)
    {
        CheckKeyPress();
        UpdateData();
        DrawScreen();
    }
}

void Gaming::GameOff()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}