#pragma once
#include"Fighter.h"

class Fight
{
public:
    Fight();
    ~Fight();
    void fight_start_stage_view(std::vector <Fighter>& m_glds);
    void fight_aggression_stage_view(Fighter& f_gld1, Fighter& f_gld2);
    void fight_atack_stage_view(Fighter& f_gld1, Fighter& f_gld2);
    void fight_show_stats(Fighter& f_gld1, Fighter& f_gld2);
    void duel(Fighter& f_gld1, Fighter& f_gld2);
    void turnament();

};

