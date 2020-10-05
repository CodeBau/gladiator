#include <ctime>
#include <windows.h>

#include"Game.h"
#include"Fighter.h"
#include"Menu.h"


Game::Game(){
}


Game::~Game(){
}


void Game::initiation()
    {
        //tworzenie vectora z Fighterami
        std::vector<Fighter> glds;
        for (int i = 0; i < 8; i++)
            glds.push_back(Fighter());
        
        //Fight fght;
        Menu gamemenu;
        while (1==1)
        {
            gamemenu.menu0(glds);
        }
        

        //Fight generalfight;
        //generalfight.fight_stages_view(gld1, gld2, n_d);


    }

void Game::loop()
{
    //Menu gamemenu;
    //gamemenu.menumain(G_fght, G_gld1,G_gld2,G_n_d);


    //Fight generalfight;
    //generalfight.fight_stages_view(gld1, gld2, n_d);


}