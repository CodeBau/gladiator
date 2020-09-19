#pragma once
#include"Fighter_generator.h"
#include"Normal_distribution.h"


class Fight
{
public:

    void fight_stages_view(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d);
    void fightatack_view(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d);
    void duel();
    void turnament();
    Fight();
    ~Fight();
};