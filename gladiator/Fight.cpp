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

Fight::Fight() {}

Fight::~Fight() {}


void Fight::fight_start_stage_view(std::vector <Fighter>& m_glds)
{
    
    
    if (f_gld2.skills[0][0] == 0)
    {
        f_gld2.generate_stats();
    }
}


//0-id, 1-zdrowie, 2-wytrzymalosc, 3-sprawnosc, 4-szybkosc, 5- sila, 6-agresja, 7-doswiadczenie 
void Fight::fight_aggression_stage_view(Fighter& f_gld1, Fighter& f_gld2)
{
    global_former_comment = "";
    while ((f_gld1.skills[0][1] > 0) & (f_gld2.skills[0][1] > 0))
    {
        system("cls");
        fight_show_stats(f_gld1, f_gld2);
        int x7 = f_gld1.skills[0][7];
        //std::cout <<"Agresja "<< f_gld1.name<<" : "<<x7<< std::endl;
        int y7 = f_gld2.skills[0][7];
        //std::cout << "Agresja " << f_gld2.name << " : " << y7 << std::endl;
        float los = normal_distribution(x7, y7);
        //std::cout << "Wylosowana: " << los << std::endl;

        if (los < x7)
        {
            fight_atack_stage_view(f_gld1, f_gld2);
        }

        else
        {
            fight_atack_stage_view(f_gld2, f_gld1);
        }
    }
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
        std::cout << f_gld1.name << " umiera." << std::endl;
        f_gld1.skills[0][0] = 0;
        f_gld2.skills[0][1]= f_gld2.skills[2][1];
        f_gld2.skills[0][8]++;
    }
    if (f_gld2.skills[0][1] <= 0)
    {
        std::cout << f_gld2.name << " umiera." << std::endl;
        f_gld2.skills[0][0] = 0;
        f_gld1.skills[0][1] = f_gld1.skills[2][1];
        f_gld1.skills[0][8]++;
    }
}

void Fight::fight_atack_stage_view(Fighter& f_gld1, Fighter& f_gld2)
{
    int min_prct_hit = 50;      //minimalna wartosc uderzenia w % - dekalroawana tutaj
    int max_prct_hit = 100;     //maksymalna wartosc uderzenia w % - dekalroawana tutaj

    int x5;                     //szybkosc 1 zawodnika
    int y4;                     //sprawnosc 2 zawodnika
    float spd_eff;              //stosunek szybkosci/sprawnosci
    float min_spd_eff;          //min stosunek szybkosci do sprawnosci mozliwy do uzyskania
    float max_spd_eff;          //max stosunek szybkosci do sprawnosci mozliwy do uzyskania
    float prct_hit;             //wartosc makymalnego % ataku mozliwa do uzyskania
    float los;                  //zmienna pprzetrzymujaca losowane wartosci
    float hit;                  //wartosc uddrzenia
    float max_hit;              //maksymalna wartosc uddrzenia
    float damage;               //wartosc obrazen
    float max_damage;           //wartosc obrazen


    //szybkosc pierwszego zawodnika
    x5 = f_gld1.skills[0][5];
    //sprawnosc 2 zawodnika
    y4 = f_gld2.skills[0][4];
    //stosunek szybkosci pierwszego zawodnika do sprawnosci drugigo zawodnika
    spd_eff = (x5 * 1.0 / y4);
    //stosunek maximum szybkosci mozliwe do uzyskania oraz minimum sprawnosci mozliwe do uzyskania (skrajny przypadek max ataku)
    max_spd_eff = f_gld1.skills[2][5] * 1.0 / f_gld2.skills[1][4];
    //stosunek minimum szybkosci mozliwe do uzyskania oraz maximum sprawnosci mozliwe do uzyskania (skrajny przypadek min ataku)
    min_spd_eff = f_gld1.skills[1][5] * 1.0 / f_gld2.skills[2][4];
    //graniczna gorna wartosc ataku w [%] do uzyskania. Uzywamy wykresu liniowego z 2 pkt (max_prct_hit=max_spd_eff*a+b oraz min_prct_hit=min_spd_eff*a+b z spd_eff wyznaczamy prct_hit)
    prct_hit = linear_function(max_prct_hit, max_spd_eff, min_prct_hit, min_spd_eff, spd_eff);
    //losujmy rzeczywista wartosc uderzenia 
    los = uniform_distribution(0, prct_hit);
    //sila 1 zawodnika
    int x6 = f_gld1.skills[0][6];
    //wartosc uderzenia = sila zawodnika pomnozona przez % ataku
    hit = x6 * los / 100;
    //maksymalna wartosc uderzenia = sila zawodnika pomnozona przez maksymalny % ataku
    max_hit = x6 * prct_hit / 100;
    //odpornosc zawodnika 2
    int y3 = f_gld2.skills[0][3];
    //obrazenia uderzeie/wtrzymalos powiekszona o 15
    damage = hit * 1.0 / y3 * 15;
    //maksymalne mozliwe obrazenia uderzenie/wtrzymalos powiekszona o 15
    max_damage = max_hit * 1.0 / y3 * 15;
    int y1 = f_gld2.skills[0][1];
    //std::cout << "Punkty zycia " << f_gld2.name << " : " << y1 << std::endl;
    f_gld2.skills[0][1] = f_gld2.skills[0][1] - damage;
    y1 = f_gld2.skills[0][1];
    //std::cout << "Zdrowie " << f_gld2.name << " po strzale : " << y1 << std::endl;
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
            std::cout << global_fighter_skills[i];
            skill_bar(f_gld1.skills[1][i], f_gld1.skills[2][i], f_gld1.skills[0][i]);
            std::cout << std::string((first_name_lnt - max_skill_lnt + global_fighters_space + 1), ' ');
            std::cout << global_fighter_skills[i];
            skill_bar(f_gld2.skills[1][i], f_gld2.skills[2][i], f_gld2.skills[0][i]);
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Name: " << f_gld1.name << std::string(global_fighters_space + max_skill_lnt - first_name_lnt - 1, ' ') << "Name: " << f_gld2.name << std::endl;
        for (int i = 1; i < (sizeof f_gld1.skills[0] / sizeof(int)); i++)
        {
            std::cout << global_fighter_skills[i];
            skill_bar(f_gld1.skills[1][i], f_gld1.skills[2][i], f_gld1.skills[0][i]);
            std::cout << std::string(global_fighters_space, ' ');
            std::cout << global_fighter_skills[i];
            skill_bar(f_gld2.skills[1][i], f_gld2.skills[2][i], f_gld2.skills[0][i]);
            std::cout << std::endl;
        }
    }
}

void Fight::duel(Fighter& f_gld1, Fighter& f_gld2)
{
    if (f_gld2.skills[0][0] == 0)
    {
        f_gld2.generate_stats();
    }
    fight_aggression_stage_view(f_gld1, f_gld2);
}

void Fight::turnament()
{

}