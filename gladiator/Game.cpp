#include <ctime>
#include <windows.h>

#include"Game.h"
#include"Fighter_generator.h"
#include"Menu.h"
#include"Fight.h"


Game::Game(){
}


Game::~Game(){
}


void Game::initiation()
    {
        //generowanie rozkladu normalnego
        Normal_distribution n_d;


        //generowanie potrzebnej liczby slotow na gladiatora. Max 8 do turnieju 
        Fighter_generator gld1;
        gld1.generate_stats();
        Fighter_generator gld2;
        gld2.generate_stats();
        Fighter_generator gld3;
        Fighter_generator gld4;
        Fighter_generator gld5;
        Fighter_generator gld6;
        Fighter_generator gld7;
        Fighter_generator gld8;

        

        //Menu gamemenu;
        //gamemenu.menumain(gld1);


        Fight generalfight;
        generalfight.fight_stages_view(gld1, gld2, n_d);


    }
