#pragma once
#include"Fighter.h"

class Fight
{
public:
    Fight();
    ~Fight();
    void fight_stage_aggression_view(Fighter& f_gld1, Fighter& f_gld2);
    void fight_stage_atack_view(Fighter& f_gld1, Fighter& f_gld2);
    void fight_show_stats(Fighter& f_gld1, Fighter& f_gld2);
    void duel(Fighter& f_gld1, Fighter& f_gld2);
    void turnament();

};

