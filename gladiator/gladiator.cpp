#include <iostream>
#include <vector>
#include <cstdlib>                                               //for consol cleaning
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <random>                                                //for normal distribution

#include "Game.h"
#include "Fighter_generator.h"
#include "uniform_distribution.h"
#include "globals.h"

int global_fighter_exist = 0;
int global_gladiator_id = 0;

class Normal_distribution
{
public:
    std::vector<int> repeat{ 1,1,1,1,1,2,2,2,2,3,3,3,4,4,5,5,6,6,7,8,9,9,10,11,13,14,15,17,18,20,22,24,26,28,31,33,36,39,42,45,49,53,57,
        61,65,70,75,80,86,91,97,104,110,117,124,131,139,146,154,163,171,180,189,198,207,216,226,235,245,255,265,275,285,295,305,315,324,
        334,344,353,362,371,380,388,396,404,411,418,425,431,437,442,447,451,455,458,460,462,464,465,0,465,464,462,460,458,455,451,447,442,
        437,431,425,418,411,404,396,388,380,371,362,353,344,334,324,315,305,295,285,275,265,255,245,235,226,216,207,198,189,180,171,163,
        154,146,139,131,124,117,110,104,97,91,86,80,75,70,65,61,57,53,49,45,42,39,36,33,31,28,26,24,22,20,18,17,15,14,13,11,10,9,9,8,7,6,
        6,5,5,4,4,3,3,3,2,2,2,2,1,1,1,1,1 };

    //to jest vector przetrzymujacy raz wygenerowany rozklad normalny
    std::vector<int>n_d = normal_distribution_values_generate();

    //to jest metoda generujaca vector z wartosciami z rozkladu normalnego generuje wartosci 1:1, 1:2, 1:3...2:6, 2:7... 10:24... itd.
    std::vector<int> normal_distribution_values_generate()
    {
     
     //vectro przetrzymujacy wszystkie wygenerowane liczy z rozkladu normalnego wg vectora repeat 
     std::vector<int> normal_distribution_values{};
                
        for (int i = 0; i < repeat.size(); i++)
        {
            for (int j = 0; j < repeat[i]; j++)
                normal_distribution_values.push_back(i);
        }

        return normal_distribution_values;
    }

    //to jest float ktory bedzie wybieral losowa liczbe z rozkladu normalnego z przedzialu liczb value1 i value2
    float normal_distribution_values_use(int value1, int value2)
    {
        
            //losujemy na pusto
            uniform_distribution(0, n_d.size() - 1);
            int values_range = (value1 + value2);

            //losujemy rozkladem jednostajnym (splaszczamy losowanie do wybrania liczby z vectora z liczbami rozkladu normalnego)
            int n_d_random = n_d[uniform_distribution(0, n_d.size() - 1)];
            int y = repeat.size();
            float x = (float)(values_range * n_d_random) / (y);

            return x;
    }

};

class Fight
{
public:

    void aggresion_stage(std::string fighter_1_name, std::vector<int> fighter_1_stats, std::string fighter_2_name, std::vector<int> fighter_2_stat)
    {


    }

    void efficiency_speed_stage()
    {

    }

    void strength_endurance_stage()
    {

    }

    void hole_fight()
    {

    }

    void show_fight()
    {

    }

    void duel()
    {

    }

    void turnament()
    {

    }

};


class Menu {
public:
    unsigned char user_menu_choice;
    std::vector<std::string> menumain_opt{ "1.Gladiator", "2.Walka","3.Wyjdz" };
    std::vector<std::string> menu1_opt{ "1.Zwerbuj nowego gladiatora","2.Powrot"};
    std::vector<std::string> menu2_opt {"1.Trening", "2.Pojedynek", "3.Turniej","4.Powrot"};

    void show_menu_option(std::vector<std::string> menu_opt)
    {
        for (int i = 0; i < menu_opt.size(); i++)
        {
            std::cout << menu_opt[i] << std::endl;
        }
    }

    void choice_menu_option(std::vector<std::string> menu_opt)
    {
        std::cout << std::endl;
        if (menu_opt.size()>1)
            std::cout << "Dokonaj wyboru: (" << 1 << " - " << menu_opt.size() << ") " << std::endl;
        else 
            std::cout << "Dokonaj wyboru: 1"<< std::endl;

        user_menu_choice = _getch();
    }
        
        void menumain()
    {
        system("cls");
        std::cout << "******MENU******" << std::endl << std::endl;
        show_menu_option(menumain_opt);
        choice_menu_option(menumain_opt);
        switch (user_menu_choice) 
        {
        case '1':
            menu1();
            break;
        case '2':
            menu2();
            break;
        case '3':
            exit(0);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menumain();
        }
    }
    
    void menu1()
    {
        system("cls");
        std::cout << "******MENU - Gladiator******" << std::endl << std::endl;

        if (global_fighter_exist == 1)
        {
            std::cout << "Poka¿ statystyki gladiatora";
        }

        else
        {
            std::cout << "Nie posiadasz gladiatora";
        }
        std::cout << std::endl;
        std::cout <<  std::endl;
        show_menu_option(menu1_opt);
        choice_menu_option(menu1_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu1();
            break;
        case '2':

            menumain();
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu1();
        }
    }
    void menu2()
    {
        system("cls");
        std::cout << "******MENU - Walka******" << std::endl << std::endl;
        show_menu_option(menu2_opt);
        choice_menu_option(menu2_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu2();
            break;
        case '2':
            menu2();
            break;
        case '3':
            menu2();
            break;
        case '4':
            menumain();
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2();;
        }
    }
};


int main()
{
    
    //Fighter_generator gld1;
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();
   // Normal_distribution n_d;
   // float probny= n_d.normal_distribution_values_use(50, 70);
    //std::cout<<probny<< std::endl;

    Game migame;
    migame.initiation();


    return 0;
}