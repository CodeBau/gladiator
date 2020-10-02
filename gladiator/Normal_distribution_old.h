#pragma once
#include <vector>
#include <iostream>

class Normal_distribution
{
public:
    //vector repeat zawiera ilosci wystapien liczb od 0 do 201 czyli 1 wystepuje 1, 5 wystepuje 2 itd 101 jest 0 jest to os symetrii
    std::vector<int> repeat{ 1,1,1,1,1,2,2,2,2,3,3,3,4,4,5,5,6,6,7,8,9,9,10,11,13,14,15,17,18,20,22,24,26,28,31,33,36,39,42,45,49,53,57,
        61,65,70,75,80,86,91,97,104,110,117,124,131,139,146,154,163,171,180,189,198,207,216,226,235,245,255,265,275,285,295,305,315,324,
        334,344,353,362,371,380,388,396,404,411,418,425,431,437,442,447,451,455,458,460,462,464,465,0,465,464,462,460,458,455,451,447,442,
        437,431,425,418,411,404,396,388,380,371,362,353,344,334,324,315,305,295,285,275,265,255,245,235,226,216,207,198,189,180,171,163,
        154,146,139,131,124,117,110,104,97,91,86,80,75,70,65,61,57,53,49,45,42,39,36,33,31,28,26,24,22,20,18,17,15,14,13,11,10,9,9,8,7,6,
        6,5,5,4,4,3,3,3,2,2,2,2,1,1,1,1,1 };

    //to jest vector przetrzymujacy raz wygenerowany rozklad normalny
    std::vector<int>n_d = normal_distribution_values_generate();

    //to jest metoda generujaca vector z wartosciami z rozkladu normalnego generuje wartosci 1:1, 1:2, 1:3...2:6, 2:7... 10:24... itd.
    std::vector<int> normal_distribution_values_generate();

    //to jest float ktory bedzie wybieral losowa liczbe z rozkladu normalnego z przedzialu liczb value1 i value2
    float normal_distribution_values_use(int value1, int value2);

};



