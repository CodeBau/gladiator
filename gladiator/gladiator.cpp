#include <iostream>
#include <vector>
#include <cstdlib>                                               //for consol cleaning
#include <windows.h>
#include <ctime>
#include <random>                                                //for normal distribution

#include "Game.h"
#include "Menu.h"
#include "Fighter_generator.h"
#include "Fight.h"
#include "Normal_distribution.h"
#include "uniform_distribution.h"
#include "globals.h"

int global_fighter_exist = 1;
int global_gladiator_id = 0;



int main()
{
    srand((unsigned int)time(NULL));

    Game migame;
    migame.initiation();


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