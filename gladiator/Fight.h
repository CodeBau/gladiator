#pragma once
#include"Fighter_generator.h"
#include"Normal_distribution.h"
#include"Menu.h"
#include"Game.h"


class Fight
{
public:
    void fight_stages_view(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d);
    void fight_stage_atack_view(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d);
    void fight_show_stats(Fighter_generator& f_gld1, Fighter_generator& f_gld2);
    void duel(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d);
    void turnament();
    Fight();
    ~Fight();
};