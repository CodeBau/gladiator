#include <ctime>
#include <windows.h>

#include"Game.h"
#include"Fighter.h"
#include"Menu.h"
#include"globals.h"


Game::Game(){
}


Game::~Game(){
}


void Game::initiation()
    {
        //tworzenie vectora z Fighterami
       

        std::vector<Fighter> glds;
        //pierwsze 0 -jest nieuzywany zeby indeks odpowiadal liczbie
        //1-zawdonik to zawodnik gracza. (+1 poniewaz "<") 
        for (int i = 0; i < global_number_of_fighters+1; i++)
        {
            glds.push_back(Fighter());
        }
            
        //oznaczenie gladiatora gracza
        glds[1].skills[0][1] = 1;

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