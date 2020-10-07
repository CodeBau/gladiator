#include <string>

#include "Fighter.h"
#include "uniform_distribution.h"
#include "globals.h"
#include "skill_bar.h"


void Fighter::show_stats()
    {
        std::cout << "Name: " << name << std::endl;
        for (int i = 2; i < (sizeof skills[0] / sizeof(int)); i++)
        {
            std::cout << global_fighter_skills[i];
            skill_bar (skills[1][i], skills[2][i],skills[0][i]);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
void Fighter::show_stats_all()
    {
        std::cout << "Name: " << name << std::endl;
        for (int i = 0; i < (sizeof skills[0] / sizeof(int)); i++)
        {
            std::cout << global_fighter_skills[i];
            std::cout << skills[0][i] << std::endl;
        }
        std::cout << std::endl;
    }

   void Fighter::generate_stats()
    {
        global_fighter_id++;


        name = global_names[uniform_distribution(0, global_names.size())]+ global_pseudos[uniform_distribution(0, global_pseudos.size())] + global_surnames[uniform_distribution(0, global_surnames.size())];

        //gladiator generate id (global+1)
        skills[0][0] = global_fighter_id;

        //znacznik gladiatora gracza
        skills[0][1] = 0;

        //wytrzymalosc/endurance wartosc min i max mozliwa do wylosowania.
        skills[1][2] = 50;
        skills[2][2] = 100;
        skills[0][2] = (uniform_distribution(skills[1][2], skills[2][2]));

        //punkty zycia/hp wartosc min i max mozliwa do wylosowania.
        skills[1][1] = 0;
        skills[2][1] = skills[0][2];
        skills[0][1] = skills[0][2];

        //odpornosc/resistance wartosc min i max mozliwa do wylosowania.
        skills[1][3] = 50;
        skills[2][3] = 100;
        skills[0][3] = (uniform_distribution(skills[1][3], skills[2][3]));

        //sprawnoœæ/efficiency wartosc min i max mozliwa do wylosowania.
        skills[1][4] = 50;
        skills[2][4] = 100;
        skills[0][4] = (uniform_distribution(skills[1][4], skills[2][4]));

        //szybkosc/speed wartosc min i max mozliwa do wylosowania.
        skills[1][5] = 50;
        skills[2][5] = 100;
        skills[0][5] = (uniform_distribution(skills[1][5], skills[2][5]));

        //si³a/strength wartosc min i max mozliwa do wylosowania.
        skills[1][6] = 50;
        skills[2][6] = 100;
        skills[0][6] = (uniform_distribution(skills[1][6], skills[2][6]));

        //agresja/aggression wartosc min i max mozliwa do wylosowania.
        skills[1][7] = 50;
        skills[2][7] = 100;
        skills[0][7] = (uniform_distribution(skills[1][7], skills[2][7]));

        //doswiadczenie/experience wartosc wartosc min i max do skill_bar.
        skills[1][8] = 0;
        skills[2][8] = 20;
        skills[0][8] = 0;

    }

   Fighter::Fighter()
    {
        //gladiator constr name
        name = "Brak";
        //gladiator constr id
        skills[0][0]=0;
        //gladiator constr punkty zycia/hp
        skills[0][1] = 0;
        //gladiator constr wytrzymalosc/endurance
        skills[0][2] = 0;
        //gladiator constr odpornosc/resistance
        skills[0][3] = 0;
        //gladiator constr sprawnoœæ/efficiency
        skills[0][4] = 0;
        //gladiator constr szybkosc/speed
        skills[0][5] = 0;
        //gladiator constr si³a/strength
        skills[0][6] = 0;
        //gladiator constr agresja/aggression
        skills[0][7] = 0;
        //gladiator constr doswiadczenie/experience
        skills[0][8] = 0;

    }

   Fighter::~Fighter()
    {}

