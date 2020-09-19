#pragma once
#include <string>
#include <vector>
#include <iostream>


class Fighter_generator 
{
public:
    
    std::vector <std::string> names{ "Jan", "Stanislaw", "Andrzej", "Jozef", "Tadeusz", "Jerzy", "Zbigniew", "Krzysztof", "Henryk", "Ryszard", "Kazimierz", "Marek", "Marian", "Piotr", "Janusz", "Wladyslaw", "Adam", "Wieslaw", "Zdzislaw", "Edward", "Mieczyslaw", "Roman", "Miroslaw", "Grzegorz", "Czeslaw", "Dariusz", "Wojciech", "Jacek", "Eugeniusz", "Tomasz", "Stefan", "Zygmunt", "Leszek", "Bogdan", "Antoni", "Pawel", "Franciszek", "Slawomir", "Waldemar", "Jaroslaw", "Robert", "Mariusz", "Wlodzimierz", "Michal", "Zenon", "Boguslaw", "Witold", "Aleksander", "Bronislaw", "Waclaw", "Boleslaw", "Ireneusz", "Maciej", "Artur", "Edmund", "Marcin", "Lech", "Karol", "Rafal", "Arkadiusz", "Leon", "Sylwester", "Lucjan", "Julian", "Wiktor", "Romuald", "Bernard", "Ludwik", "Feliks", "Alfred", "Alojzy", "Przemyslaw", "Cezary", "Daniel", "Mikolaj", "Ignacy", "Leslaw", "Radoslaw", "Konrad", "Bogumil", "Szczepan", "Gerard", "Hieronim", "Krystian", "Leonard", "Wincenty", "Benedykt", "Hubert", "Sebastian", "Norbert", "Adolf", "Lukasz", "Emil", "Teodor", "Rudolf", "Joachim", "Jakub", "Walenty", "Alfons", "Damian" };
    std::vector <std::string> pseudos{ " 'Lufa' "," 'Kasztan' "," 'Maly' "," 'Lysy' "," 'Grucha' "," 'Banan' "," 'Tega Pala' "," 'Ursus' "," 'Tuba' "," 'Bam-Bam' "," 'Misiek' "," 'Tygrys' "," 'Pudzian' "," 'Szwagier' "," 'Szklana' "," 'Szczena' "," 'Rekin' "," 'Tygrys' "," 'Burza' "," 'Szpadel' "," 'Oli' "," 'Krzywy' "," 'Waski' "," 'Suchy' "," 'Brzydal' "," 'Bzyku' "," 'Rafi' "," 'Kielon' "," 'Kalosz' "," 'Ryba' "," 'Robal' "," 'Swinia' "," 'Seba' "," 'Lona' "," 'Ostry' "," 'Rudy' "," 'Kedzior' "," 'Zloty' "," 'Bialy' "," 'Czarny' "," 'Krecha' "," 'Flacha' "," 'Duzy' "," 'Gruby' "," 'Szczena' "," 'Piekny' "," 'Grzmot' "," 'Mlot' "," 'Goral' "," 'Fifi' "," 'Kilof' "," 'Cichy' "," 'Wilku' "," 'Tata' "," 'Dziadek' "," 'Babyface' "," 'Kiler' "," 'Dolar' "," 'Ruski' "," 'Waleczny' "," 'Niesmiertelny' "," 'Gibki' "," 'Rezus' "," 'Zygi' "," 'Owca' "," 'Rolnik' "," 'Mnich' "," 'Bokser' "," 'Prezes' "," 'Bysior' "," 'Bestia' "," 'Masa' "," 'Perszing' "," 'Pala' "," 'Mlody' "," 'Miekki' "," 'Twardy' "," 'Kosiarz' "," 'Sliski' "," 'Sokol' "," 'Skala' "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," " };
    std::vector <std::string> surnames{ "Nowak","Kowalski","Wisniewski","Wojcik","Kowalczyk","Kaminski","Lewandowski","Zielinski","Wozniak","Szymanski","Dabrowski","Kozlowski","Mazur","Jankowski","Kwiatkowski","Wojciechowski","Krawczyk","Kaczmarek","Piotrowski","Grabowski","Zajac","Pawlowski","Krol","Michalski","Wrobel","Wieczorek","Jablonski","Nowakowski","Majewski","Olszewski","Dudek","Stepien","Jaworski","Adamczyk","Malinowski","Gorski","Pawlak","Nowicki","Sikora","Witkowski","Rutkowski","Walczak","Baran","Michalak","Szewczyk","Ostrowski","Tomaszewski","Zalewski","Wroblewski","Pietrzak","Jasinski","Marciniak","Sadowski","Bak","Zawadzki","Duda","Jakubowski","Wilk","Chmielewski","Borkowski","Wlodarczyk","Sokolowski","Szczepanski","Sawicki","Lis","Kucharski","Kalinowski","Wysocki","Mazurek","Kubiak","Maciejewski","Kolodziej","Kazmierczak","Czarnecki","Sobczak","Konieczny","Krupa","Glowacki","Urbanski","Mroz","Zakrzewski","Wasilewski","Krajewski","Laskowski","Sikorski","Ziolkowski","Gajewski","Szulc","Makowski","Kaczmarczyk","Brzezinski","Baranowski","Przybylski","Szymczak","Kania","Kozak","Janik","Borowski","Blaszczyk","Adamski", };
    Fighter_generator();
    ~Fighter_generator();
    std::string name;
    std::vector <int> gladiator;
    int id_count;
    void show_stats();
    void show_stats_all();
    void generate_stats();
private:
    //zakresy losowan wartosci umiejetnosci przy generowaniu gladiatora
    int min_hp;
    int max_hp;
    int min_en;
    int max_en;
    int min_ef;
    int max_ef;
    int min_sp;
    int max_sp;
    int min_st;
    int max_st;
    int min_ag;
    int max_ag;
    //doswiadczenie jest zdobywane wraz z walkami, sa to orientacyjne wartosci
    //aby zastapic liczbe slowem
    int min_ex;
    int max_ex;
};