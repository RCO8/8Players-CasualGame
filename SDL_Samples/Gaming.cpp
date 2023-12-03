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
    players[0]->SetPlayerSprite(renderer, "Bomberman1.png");

    players[1] = new Player(360, 0);
    players[1]->SetPlayerSprite(renderer, "Bomberman2.png");

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
            case SDL_WINDOWEVENT_MOVED:     //SDL_Log("Window : (%d, %d)", event.window.data1, event.window.data2 - 31);  //이동된 창을 좌표로 얻기
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
            case SDL_SCANCODE_DOWN:
                //playerSprite[0]->SetSpriteClip(17, 1, 15, 22);
                break;
            }
        case SDL_KEYMAPCHANGED:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:       //SDL_Log("Up");
                if (0 < players[0]->GetPosition(false))
                    inputVertical = -1;
                break;
            case SDL_SCANCODE_S:
                //if (windowHeight - playerSprite[0]->GetClipHeight() > players[0]->GetPosition(false))
                    inputVertical = 1;
                break;
            case SDL_SCANCODE_A:     //SDL_Log("Left");
                if (0 < players[0]->GetPosition(true))
                    inputHorizon = -1;
                break;
            case SDL_SCANCODE_D:    //SDL_Log("Right");
                //if (windowWidth - playerSprite[0]->GetClipWidth() > players[0]->GetPosition(true))
                    inputHorizon = 1;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.scancode)  //Same to SDL_KEYDOWN
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_S:
                inputVertical = 0;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                inputHorizon = 0;
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
            // Joystick 생성자 호출
            break;
        }

        //추가적인 입력 디바이스가 있다면 여기로 메서드 호출
        playerContoll->CheckJoystickEvent(event, *players[0]);
    }
}
void Gaming::UpdateData()
{
    //게임 내 변형된 데이터를 여기에 갱신
    //만약에 이벤트에 적용을 하지 않는다면
    //mTimer.StartCount();
    if(inputVertical < 0)
        players[0]->CheckMove(0, -2);
    else if(inputVertical > 0)
        players[0]->CheckMove(0, 2);
    else if(inputHorizon < 0)
        players[0]->CheckMove(-2, 0);
    else if(inputHorizon > 0)
        players[0]->CheckMove(2, 0);

    SDL_Delay(100);
}
void Gaming::DrawScreen()   //Drawing Sprite or UI in this Screen
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
    SDL_RenderClear(renderer);  //Screen Clear   //Fill Color in Screen
    
    //Draw Image
    players[0]->DrawPlayer();
    players[1]->DrawPlayer();
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