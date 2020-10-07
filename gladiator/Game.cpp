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
        //pierwsze 0 zeby indeks odpowiadal liczbie
        glds.push_back(0);
        for (int i = 1; i < 9; i++)
            glds.push_back(Fighter());
        
        //oznaczenie gladiatora gracza
        glds[0].skills[0][1] = 1;

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