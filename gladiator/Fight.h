#pragma once
#include<string>
#include<vector>


class Fight
{
public:

    void aggresion_stage(std::string fighter_1_name, std::vector<int> fighter_1_stats, std::string fighter_2_name, std::vector<int> fighter_2_stat);
    void efficiency_speed_stage();
    void strength_endurance_stage();
    void hole_fight();
    void show_fight();
    void duel();
    void turnament();
    Fight();
    ~Fight();
};