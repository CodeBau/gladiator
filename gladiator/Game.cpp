#include <ctime>
#include <windows.h>

#include"Game.h"
#include"Fighter_generator.h"

Game::Game()
{

};


Game::~Game()
{

};


void Game::initiation()
    {
        srand((unsigned int)time(NULL));

        Fighter_generator gld1;
        gld1.generate_stats();
        gld1.show_stats();

        Fighter_generator gld2;
        gld2.generate_stats();
        gld2.show_stats();

        Fighter_generator gld3;
        gld3.generate_stats();
        gld3.show_stats();
        

    }
