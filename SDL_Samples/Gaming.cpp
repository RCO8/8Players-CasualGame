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

    playerContoll = new Joystick();

    //Resouce Setting
    SDL_Color bgImgColor = { 255,255,255 };
    players[0] = new Player(0, 0);
    players[0]->SetPlayerSprite(renderer, "Bomberman1.png");

    players[1] = new Player(360, 0);
    players[1]->SetPlayerSprite(renderer, "Bomberman2.png");

    players[2] = new Player(705, 0);
    players[2]->SetPlayerSprite(renderer, "Bomberman3.png");

    players[3] = new Player(0, 320);
    players[3]->SetPlayerSprite(renderer, "Bomberman4.png");

    players[4] = new Player(705, 320);
    players[4]->SetPlayerSprite(renderer, "Bomberman5.png");

    players[5] = new Player(0, 615);
    players[5]->SetPlayerSprite(renderer, "Bomberman5.png");

    players[6] = new Player(360, 615);
    players[6]->SetPlayerSprite(renderer, "Bomberman5.png");

    players[7] = new Player(705, 615);
    players[7]->SetPlayerSprite(renderer, "Bomberman5.png");

    return true;
}

void Gaming::CheckKeyPress()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: quit = true; return;
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
            case SDL_WINDOWEVENT_CLOSE: quit = true; return;
            }

            //Keyboard Check
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_ESCAPE:
                quit = true;
                break;
            }
        case SDL_KEYMAPCHANGED:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
                players[0]->InputY(-1);
                break;
            case SDL_SCANCODE_S:
                players[0]->InputY(1);
                break;
            case SDL_SCANCODE_A:     
                players[0]->InputX(-1);
                break;
            case SDL_SCANCODE_D:
                players[0]->InputX(1);
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.scancode)  //Same to SDL_KEYDOWN
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_S:
                players[0]->InputY(0);
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                players[0]->InputX(0);
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
        playerContoll->CheckJoystickEvent(event);
    }
}
void Gaming::UpdateData()
{
    //���� �� ������ �����͸� ���⿡ ����
    //���࿡ �̺�Ʈ�� ������ ���� �ʴ´ٸ�
    players[0]->InputX(playerContoll->GetJoyAxisX[0]);
    players[0]->InputY(playerContoll->GetJoyAxisY[0]);
    players[0]->CheckMove();
    players[1]->CheckMove();
}
void Gaming::DrawScreen()   //Drawing Sprite or UI in this Screen
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
    SDL_RenderClear(renderer);  //Screen Clear   //Fill Color in Screen
    
    //Draw Image
    players[0]->DrawPlayer();
    players[1]->DrawPlayer();
    players[2]->DrawPlayer();
    players[3]->DrawPlayer();
    players[4]->DrawPlayer();
    players[5]->DrawPlayer();
    players[6]->DrawPlayer();
    players[7]->DrawPlayer();
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