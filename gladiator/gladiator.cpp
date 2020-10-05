#include <iostream>
#include <vector>
#include <cstdlib>                                               //for consol cleaning
#include <windows.h>
#include <ctime>
#include <random>                                                //for normal distribution
#include <string>


#include "Game.h"
#include "Menu.h"
#include "Fighter.h"
#include "normal_distribution.h"
#include "uniform_distribution.h"
#include "globals.h"
#include "skill_bar.h"


int global_fighter_exist = 0;
int global_gladiator_id = 0;
int global_fighters_space = 20;
int global_bar_lnt = 20;
std::string global_fighter_skills[] = { "Id:            ", "Punkty zycia:  ", "Wytrzymalosc:  ", "Odpornosc:     ","Sprawnosc:     ","Szybkosc:      ","Sila:          ","Agresja:       ", "Doswiadczenie: " };
std::string global_former_comment;
std::vector <std::string> global_names ={ "Jan", "Stanislaw", "Andrzej", "Jozef", "Tadeusz", "Jerzy", "Zbigniew", "Krzysztof", "Henryk", "Ryszard", "Kazimierz", "Marek", "Marian", "Piotr", "Janusz", "Wladyslaw", "Adam", "Wieslaw", "Zdzislaw", "Edward", "Mieczyslaw", "Roman", "Miroslaw", "Grzegorz", "Czeslaw", "Dariusz", "Wojciech", "Jacek", "Eugeniusz", "Tomasz", "Stefan", "Zygmunt", "Leszek", "Bogdan", "Antoni", "Pawel", "Franciszek", "Slawomir", "Waldemar", "Jaroslaw", "Robert", "Mariusz", "Wlodzimierz", "Michal", "Zenon", "Boguslaw", "Witold", "Aleksander", "Bronislaw", "Waclaw", "Boleslaw", "Ireneusz", "Maciej", "Artur", "Edmund", "Marcin", "Lech", "Karol", "Rafal", "Arkadiusz", "Leon", "Sylwester", "Lucjan", "Julian", "Wiktor", "Romuald", "Bernard", "Ludwik", "Feliks", "Alfred", "Alojzy", "Przemyslaw", "Cezary", "Daniel", "Mikolaj", "Ignacy", "Leslaw", "Radoslaw", "Konrad", "Bogumil", "Szczepan", "Gerard", "Hieronim", "Krystian", "Leonard", "Wincenty", "Benedykt", "Hubert", "Sebastian", "Norbert", "Adolf", "Lukasz", "Emil", "Teodor", "Rudolf", "Joachim", "Jakub", "Walenty", "Alfons", "Damian" };
std::vector <std::string> global_pseudos ={ " 'Lufa' "," 'Kasztan' "," 'Maly' "," 'Lysy' "," 'Grucha' "," 'Banan' "," 'Tega Pala' "," 'Ursus' "," 'Tuba' "," 'Bam-Bam' "," 'Misiek' "," 'Tygrys' "," 'Pudzian' "," 'Szwagier' "," 'Szklana' "," 'Szczena' "," 'Rekin' "," 'Tygrys' "," 'Burza' "," 'Szpadel' "," 'Oli' "," 'Krzywy' "," 'Waski' "," 'Suchy' "," 'Brzydal' "," 'Bzyku' "," 'Rafi' "," 'Kielon' "," 'Kalosz' "," 'Ryba' "," 'Robal' "," 'Swinia' "," 'Seba' "," 'Lona' "," 'Ostry' "," 'Rudy' "," 'Kedzior' "," 'Zloty' "," 'Bialy' "," 'Czarny' "," 'Krecha' "," 'Flacha' "," 'Duzy' "," 'Gruby' "," 'Szczena' "," 'Piekny' "," 'Grzmot' "," 'Mlot' "," 'Goral' "," 'Fifi' "," 'Kilof' "," 'Cichy' "," 'Wilku' "," 'Tata' "," 'Dziadek' "," 'Babyface' "," 'Kiler' "," 'Dolar' "," 'Ruski' "," 'Waleczny' "," 'Niesmiertelny' "," 'Gibki' "," 'Rezus' "," 'Zygi' "," 'Owca' "," 'Rolnik' "," 'Mnich' "," 'Bokser' "," 'Prezes' "," 'Bysior' "," 'Bestia' "," 'Masa' "," 'Perszing' "," 'Pala' "," 'Mlody' "," 'Miekki' "," 'Twardy' "," 'Kosiarz' "," 'Sliski' "," 'Sokol' "," 'Skala' "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," " };
std::vector <std::string> global_surnames ={ "Nowak","Kowalski","Wisniewski","Wojcik","Kowalczyk","Kaminski","Lewandowski","Zielinski","Wozniak","Szymanski","Dabrowski","Kozlowski","Mazur","Jankowski","Kwiatkowski","Wojciechowski","Krawczyk","Kaczmarek","Piotrowski","Grabowski","Zajac","Pawlowski","Krol","Michalski","Wrobel","Wieczorek","Jablonski","Nowakowski","Majewski","Olszewski","Dudek","Stepien","Jaworski","Adamczyk","Malinowski","Gorski","Pawlak","Nowicki","Sikora","Witkowski","Rutkowski","Walczak","Baran","Michalak","Szewczyk","Ostrowski","Tomaszewski","Zalewski","Wroblewski","Pietrzak","Jasinski","Marciniak","Sadowski","Bak","Zawadzki","Duda","Jakubowski","Wilk","Chmielewski","Borkowski","Wlodarczyk","Sokolowski","Szczepanski","Sawicki","Lis","Kucharski","Kalinowski","Wysocki","Mazurek","Kubiak","Maciejewski","Kolodziej","Kazmierczak","Czarnecki","Sobczak","Konieczny","Krupa","Glowacki","Urbanski","Mroz","Zakrzewski","Wasilewski","Krajewski","Laskowski","Sikorski","Ziolkowski","Gajewski","Szulc","Makowski","Kaczmarczyk","Brzezinski","Baranowski","Przybylski","Szymczak","Kania","Kozak","Janik","Borowski","Blaszczyk","Adamski", };


int main()
{
    srand((unsigned int)time(NULL));

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    Game migame;
    migame.initiation();
    migame.loop();

    //Fighter gld1;
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();
    //gld1.generate_stats(global_gladiator_id);
    //gld1.show_stats();

   
    //std::cout << normal_distribution(50, 70) << std::endl;


    return 0;
}