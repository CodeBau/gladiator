#include "Fight.h"
#include "globals.h"
#include "normal_distribution.h"
#include "linear_function.h"
#include "uniform_distribution.h"
#include "skill_bar.h"
#include "fight_commentary.h"


#include<windows.h>
#include<ctime>
#include<iomanip>
#include<iostream>
#include <conio.h>


Fight::Fight() {}

Fight::~Fight() {}


void Fight::duel_start(std::vector <Fighter>& f_glds)
{
     global_2_fighter_to_fight = uniform_distribution(2, global_number_of_fighters);

    if (f_glds[global_2_fighter_to_fight].skills[0][0] == 0|| f_glds[global_2_fighter_to_fight].skills[0][8] == global_maximum_of_exp)
    {
        f_glds[global_2_fighter_to_fight].generate_stats();
    }
}

void Fight::duel_end(Fighter& f_gld1, Fighter& f_gld2)
{
    std::string any;
    system("cls");
    fight_show_stats(f_gld1, f_gld2);

    //ustawienie koloru tekstu konsoli na ciemno szary
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
    std::cout << global_former_comment << std::endl;
    //powrot koloru do jasno szarego
    SetConsoleTextAttribute(hConsole, 7);

    //sprawdzamy kto wygral
    if (f_gld1.skills[0][1] <= 0)
    { 
        std::cout << "Twoj zawodnik "<< f_gld1.name<<" ginie, bedziesz musial poszukac sobie innego, oby lepszego." << std::endl;
        f_gld1.skills[0][0] = 0;
        f_gld2.skills[0][1] = f_gld2.skills[2][1];
        if (f_gld2.skills[0][8] < global_maximum_of_exp)
            f_gld2.skills[0][8]++;
    }

    if (f_gld2.skills[0][1] <= 0)
    {
        std::cout << f_gld2.name << " umiera." << std::endl;
        std::cout << "Twoj zawodnik "<<f_gld1.name<<" wygrywa walke, zdobywa doswiadczenie, laury i troche golda (jeszcze nie)" << std::endl;
        f_gld2.skills[0][0] = 0;
        f_gld1.skills[0][1] = f_gld1.skills[2][1];
        if (f_gld1.skills[0][8] < global_maximum_of_exp)
            f_gld1.skills[0][8]++;
    }

    std::cout<<std::endl  << "Nacisnij dowolny klawisz aby kontynuowac..." << std::endl;
    any = _getch();

    global_1_fighter_to_fight = 0;
    global_2_fighter_to_fight = 0;
}

std::vector<int> Fight::turnament_generate(std::vector <Fighter>& f_glds)
{
    const int how_many_fighters_in_turnament = 8;
    std::vector <int> all_fighters_list = {};
    std::vector <int> turnament_fighters_list = {};
    int possible_player_slot[how_many_fighters_in_turnament / 2];
    int temp = 0;
    int turnament_longest_name = 0;


    //generujemy liste wszystkich fighterow
    for (int i = 1; i < global_number_of_fighters + 1; i++)
    {
        all_fighters_list.push_back(i);
    }

    for (int i = 1; i < how_many_fighters_in_turnament + 1; i++)
    {
        turnament_fighters_list.push_back(0);
    }

    //zakladamy ze gladiator gracza zajmuje pierwsze miejsce w parze
    //zawsze nieparzyste
    //generujemy liste mozliwych slotow dla gracza
    for (int i = 0; i < how_many_fighters_in_turnament; i = i + 2)
    {
        possible_player_slot[temp] = i;
        temp++;
    }

    //ustalamy pozycje zawodnika
    temp = possible_player_slot[uniform_distribution(0, how_many_fighters_in_turnament / 2)];
    turnament_fighters_list[temp] = 1;
    all_fighters_list.erase(all_fighters_list.begin());

    for (int i = 0; i < how_many_fighters_in_turnament; i++)
    {
        //jesli to nie wystepuje gladiator gracza to przypisz losowego z pozostalych
        if (turnament_fighters_list[i] == 0)
        {
            temp = uniform_distribution(0, all_fighters_list.size());
            turnament_fighters_list[i] = all_fighters_list[temp];
            all_fighters_list.erase(all_fighters_list.begin() + temp);
        }
        
        //std::cout << turnament_fighters_list[i] << std::endl;
        //generowanie statystyk dla umarlych i zbyt doswiadczonych
        if (f_glds[turnament_fighters_list[i]].skills[0][0] == 0 || f_glds[turnament_fighters_list[i]].skills[0][8] == global_maximum_of_exp)
        {
            f_glds[turnament_fighters_list[i]].generate_stats();

        }
    }
    return turnament_fighters_list;
}


void Fight::turnament_start(std::vector <Fighter>& f_glds, std::vector<int> &f_turnament_fighters_list)
{
    
    int turnament_longest_name=0;

    for (int i=0; i< f_turnament_fighters_list.size(); i++)
    {
        if (turnament_longest_name < f_glds[f_turnament_fighters_list[i]].name.size())
        {
            turnament_longest_name= f_glds[f_turnament_fighters_list[i]].name.size();
        }
    }
    
    for (int i = 0; i < f_turnament_fighters_list.size(); i++)
    {
        if (f_turnament_fighters_list[i]==1)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 3);
        }

        std::cout << std::string(turnament_longest_name + 4,'#' ) << std::endl;
        std::cout << "# " << std::string(((turnament_longest_name - f_glds[f_turnament_fighters_list[i]].name.size()) / 2), ' ') << f_glds[f_turnament_fighters_list[i]].name;
        std::cout << std::string(turnament_longest_name - (turnament_longest_name - f_glds[f_turnament_fighters_list[i]].name.size()) / 2 - f_glds[f_turnament_fighters_list[i]].name.size(), ' ') << " #" << std::endl;
        std::cout << std::string(turnament_longest_name + 4, '#') << std::endl;
        std::cout << std::endl;

        if (i % 2 != 0 && i!= f_turnament_fighters_list.size() -1)
        {
            std::cout << std::endl;
            std::cout << std::endl;
        }

        if (f_turnament_fighters_list[i] == 1)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
}

//0-id, 1-zdrowie, 2-wytrzymalosc, 3-odpornosc, 4-sprawnosc, 5-szybkosc, 6-sila, 7-agresja, 8-doswiadczenie 
void Fight::fight_aggression_stage(Fighter& f_gld1, Fighter& f_gld2)
{
    global_former_comment = "";
    while ((f_gld1.skills[0][1] > 0) & (f_gld2.skills[0][1] > 0))
    {
        system("cls");
        if (global_show_fight_on_off==1)
        fight_show_stats(f_gld1, f_gld2);

        int x7 = f_gld1.skills[0][7];
        //std::cout <<"Agresja "<< f_gld1.name<<" : "<<x7<< std::endl;
        int y7 = f_gld2.skills[0][7];
        //std::cout << "Agresja " << f_gld2.name << " : " << y7 << std::endl;
        float los = normal_distribution(x7, y7);
        //std::cout << "Wylosowana: " << los << std::endl;

        if (los < x7)
        {
            fight_atack_stage(f_gld1, f_gld2);
        }
        else
        {
            fight_atack_stage(f_gld2, f_gld1);
        }
    }
}

void Fight::fight_atack_stage(Fighter& f_gld1, Fighter& f_gld2)
{
    int min_prct_hit = 50;      //minimalna wartosc uderzenia w % - dekalroawana tutaj
    int max_prct_hit = 100;     //maksymalna wartosc uderzenia w % - dekalroawana tutaj

    //szybkosc pierwszego zawodnika
    int x5 = f_gld1.skills[0][5];
    //sprawnosc 2 zawodnika
    int y4 = f_gld2.skills[0][4];
    //stosunek szybkosci pierwszego zawodnika do sprawnosci drugigo zawodnika
    float spd_eff = (x5 * 1.0 / y4);
    //stosunek maximum szybkosci mozliwe do uzyskania oraz minimum sprawnosci mozliwe do uzyskania (skrajny przypadek max ataku)
    float max_spd_eff = f_gld1.skills[2][5] * 1.0 / f_gld2.skills[1][4];
    //stosunek minimum szybkosci mozliwe do uzyskania oraz maximum sprawnosci mozliwe do uzyskania (skrajny przypadek min ataku)
    float min_spd_eff = f_gld1.skills[1][5] * 1.0 / f_gld2.skills[2][4];
    //graniczna gorna wartosc ataku w [%] do uzyskania. Uzywamy wykresu liniowego z 2 pkt (max_prct_hit=max_spd_eff*a+b oraz min_prct_hit=min_spd_eff*a+b z spd_eff wyznaczamy prct_hit)
    float prct_hit = linear_function(max_prct_hit, max_spd_eff, min_prct_hit, min_spd_eff, spd_eff);
    //losujmy rzeczywista wartosc uderzenia 
    float los = uniform_distribution(0, prct_hit);
    //sila 1 zawodnika
    int x6 = f_gld1.skills[0][6];
    //wartosc uderzenia = sila zawodnika pomnozona przez % ataku
    float hit = x6 * los / 100;
    //maksymalna wartosc uderzenia = sila zawodnika pomnozona przez maksymalny % ataku
    float max_hit = x6 * prct_hit / 100;
    //odpornosc zawodnika 2
    float y3 = f_gld2.skills[0][3];
    //doswiadczenie zawodnika 2
    float y8 = f_gld2.skills[0][8];
    //obrazenia uderzeie/wtrzymalos powiekszona o 15
    float damage = hit * 1.0 / (y3+y8)*15;
    //maksymalne mozliwe obrazenia uderzenie/wtrzymalos powiekszona o 15
    float max_damage = max_hit * 1.0 / y3 * 15;
    int y1 = f_gld2.skills[0][1];
    //std::cout << "Punkty zycia " << f_gld2.name << " : " << y1 << std::endl;
    f_gld2.skills[0][1] = f_gld2.skills[0][1] - damage;
    y1 = f_gld2.skills[0][1];
    //std::cout << "Zdrowie " << f_gld2.name << " po strzale : " << y1 << std::endl;
    if (global_show_fight_on_off == 1)
    fight_commentary(f_gld1, f_gld2, damage, max_damage);
}

void Fight::fight_show_stats(Fighter& f_gld1, Fighter& f_gld2)
{
    //"Name: " to 5 znakow
    int first_name_lnt = 5 + f_gld1.name.size();

    //"Doswiadczenie: " + "[" + "]" = 17 znakow. + bar_lnt = 37 znakow
    int max_skill_lnt = 17 + global_bar_lnt;

    //sprawdzamy czy wiecej znakow (dluzszy) jest imie gladiatora, czy nazwa umiejetnosci + skill_bar
    if (first_name_lnt >= max_skill_lnt)
    {
        std::cout << "Name: " << f_gld1.name << std::string(global_fighters_space, ' ') << "Name: " << f_gld2.name << std::endl;
        for (int i = 1; i < (sizeof f_gld1.skills[0] / sizeof(int)); i++)
        {
            std::cout << global_fighter_skills_names[i];
            skill_bar(f_gld1.skills[1][i], f_gld1.skills[2][i], f_gld1.skills[0][i]);
            std::cout << std::string((first_name_lnt - max_skill_lnt + global_fighters_space + 1), ' ');
            std::cout << global_fighter_skills_names[i];
            skill_bar(f_gld2.skills[1][i], f_gld2.skills[2][i], f_gld2.skills[0][i]);
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Name: " << f_gld1.name << std::string(global_fighters_space + max_skill_lnt - first_name_lnt - 1, ' ') << "Name: " << f_gld2.name << std::endl;
        for (int i = 1; i < (sizeof f_gld1.skills[0] / sizeof(int)); i++)
        {
            std::cout << global_fighter_skills_names[i];
            skill_bar(f_gld1.skills[1][i], f_gld1.skills[2][i], f_gld1.skills[0][i]);
            std::cout << std::string(global_fighters_space, ' ');
            std::cout << global_fighter_skills_names[i];
            skill_bar(f_gld2.skills[1][i], f_gld2.skills[2][i], f_gld2.skills[0][i]);
            std::cout << std::endl;
        }
    }
}

void Fight::duel(std::vector <Fighter>& f_glds)
{
    fight_aggression_stage(f_glds[global_1_fighter_to_fight], f_glds[global_2_fighter_to_fight]);
    duel_end(f_glds[global_1_fighter_to_fight], f_glds[global_2_fighter_to_fight]);
}

void Fight::turnament()
{


}