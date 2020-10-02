#include <iostream>
#include <vector>
#include <cstdlib>                                               //for consol cleaning
#include <windows.h>
#include <ctime>
#include <random>                                                //for normal distribution
#include <string>


#include "Game.h"
#include "Menu.h"
#include "Fighter_generator.h"
#include "Fight.h"
#include "Normal_distribution.h"
#include "uniform_distribution.h"
#include "globals.h"
#include "skill_bar.h"


int global_fighter_exist = 0;
int global_gladiator_id = 0;
int global_fighters_space = 20;
int global_bar_lnt = 20;
std::string global_fighter_skills[] = { "Id:            ", "Punkty zycia:  ", "Wytrzymalosc:  ", "Odpornosc:     ","Sprawnosc:     ","Szybkosc:      ","Sila:          ","Agresja:       ", "Doswiadczenie: " };
std::string global_former_comment;

int main()
{
    srand((unsigned int)time(NULL));

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    Game migame;
    migame.initiation();
    //migame.loop();


    //Fighter_generator gld1;
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();

    //Normal_distribution n_d;
    //float probny= n_d.normal_distribution_values_use(50, 70);
    //std::cout<<probny<< std::endl;

    


    return 0;
}