#pragma once
#include <string>
#include <vector>
#include <iostream>


class Fighter 
{
public:
    Fighter();
    ~Fighter();
    std::string name;
    float skills[3][9];
    int id_count;
    void show_stats();
    void show_stats_all();
    void generate_stats();
};