#include "Fighter_generator.h"
#include "uniform_distribution.h"
#include "globals.h"
#include "Menu.h"


void Fighter_generator::show_stats()
    {
        std::cout << "Name: " << name << std::endl;
        for (int i = 0; i < gladiator.size(); i++)
        {
            switch (i) {
            case 0:
                std::cout << "Id:            ";
                break;
            case 1:
                std::cout << "Zdrowie:       ";
                break;
            case 2:
                std::cout << "Wytrzymalosc:  ";
                break;
            case 3:
                std::cout << "Sprawnosc:     ";
                break;
            case 4:
                std::cout << "Szybkosc:      ";
                break;
            case 5:
                std::cout << "Sila:          ";
                break;
            case 6:
                std::cout << "Agresja:       ";
                break;
            case 7:
                std::cout << "Doswiadczenie: ";
                break;

            }
            std::cout << gladiator[i] << std::endl;
        }
        std::cout << std::endl;
    }

   void Fighter_generator::generate_stats()
    {
        global_gladiator_id++;

        name = names[uniform_distribution(0, names.size())]+ pseudos[uniform_distribution(0, pseudos.size())] + surnames[uniform_distribution(0, surnames.size())];
        //gladiator generate id (global+1)
        gladiator[0] = global_gladiator_id;
        //gladiator constr zdrowie/hp
        gladiator[1] = (uniform_distribution(50, 100));
        //gladiator constr wytrzymalosc/endurance
        gladiator[2] = (uniform_distribution(50, 100));
        //gladiator constr sprawnoœæ/efficiency
        gladiator[3] = (uniform_distribution(50, 100));
        //gladiator constr szybkosc/speed
        gladiator[4] = (uniform_distribution(50, 100));
        //gladiator constr si³a/strength
        gladiator[5] = (uniform_distribution(50, 100));
        //gladiator constr agresja/aggression
        gladiator[6] = (uniform_distribution(50, 100));
        //gladiator constr doswiadczenie/experience
        gladiator[7] = 0;

    }

   Fighter_generator::Fighter_generator()
    {
        //gladiator constr name
        name = "Brak";
        //gladiator constr  id
        gladiator.push_back(0);
        //gladiator constr zdrowie/hp
        gladiator.push_back(0);
        //gladiator constr wytrzymalosc/endurance
        gladiator.push_back(0);
        //gladiator constr sprawnoœæ/efficiency
        gladiator.push_back(0);
        //gladiator constr szybkosc/speed
        gladiator.push_back(0);
        //gladiator constr si³a/strength
        gladiator.push_back(0);
        //gladiator constr agresja/aggression
        gladiator.push_back(0);
        //gladiator constr doswiadczenie/experience
        gladiator.push_back(0);

    }

   Fighter_generator::~Fighter_generator()
    {}

