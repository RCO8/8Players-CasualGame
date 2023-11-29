
#include <iostream>
#include "Gaming.h"

int main(int argc, char* argv[])
{
    Gaming game;
    bool success = game.GameInit();
    while(success)
        game.GameRun();
	game.GameOff();
    return 0;
}
