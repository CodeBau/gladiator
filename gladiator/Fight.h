#pragma once
#include"Fighter.h"

class Fight
{
public:
    Fight();
    ~Fight();
    void duel_start(std::vector <Fighter>& f_glds);
    void duel_end(Fighter& f_gld1, Fighter& f_gld2);
    std::vector<int> turnament_generate(std::vector <Fighter>& f_glds);
    void turnament_start(std::vector <Fighter>& f_glds, std::vector<int>& f_turnament_fighters_list);
    void fight_aggression_stage(Fighter& f_gld1, Fighter& f_gld2);
    void fight_atack_stage(Fighter& f_gld1, Fighter& f_gld2);
    void fight_show_stats(Fighter& f_gld1, Fighter& f_gld2);
    void duel(std::vector <Fighter>& f_glds);
    void turnament();
};

