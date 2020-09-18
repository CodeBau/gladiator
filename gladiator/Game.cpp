#include <ctime>
#include <windows.h>

#include"Game.h"
#include"Fighter_generator.h"
#include"Menu.h"

Game::Game()
{

};


Game::~Game()
{

};


void Game::initiation()
    {
        //generowanie potrzebnej liczby slotow na gladiatora. Max 8 do turnieju 
        Fighter_generator gld1;
        Fighter_generator gld2;
        Fighter_generator gld3;
        Fighter_generator gld4;
        Fighter_generator gld5;
        Fighter_generator gld6;
        Fighter_generator gld7;
        Fighter_generator gld8;

        Menu mainmenu;
        mainmenu.menu1(gld1);

    }
