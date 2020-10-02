#pragma once
#include"Fighter_generator.h"
#include"Normal_distribution.h"


class Menu {
public:
    unsigned char user_menu_choice;
    std::vector<std::string> menumain_opt{ "1.Gladiator", "2.Walka","3.Wyjdz" };
    std::vector<std::string> menu1_opt{ "1.Zwerbuj nowego gladiatora","2.Powrot" };
    std::vector<std::string> menu11_opt{ "1.Tak","2.Zrezygnuj"};
    std::vector<std::string> menu2_opt{ "1.Trening", "2.Pojedynek", "3.Turniej","4.Powrot" };

    void show_menu_option(std::vector<std::string> menu_opt);
    void choice_menu_option(std::vector<std::string> menu_opt);
    void menumain(Fighter_generator& m_gld1, Fighter_generator& m_gld2, Normal_distribution& f_n_d);
    void menu1(Fighter_generator& m_gld1, Fighter_generator& m_gld2, Normal_distribution& f_n_d);
    void menu11(Fighter_generator& m_gld1, Fighter_generator& m_gld2, Normal_distribution& f_n_d);
    void menu2(Fighter_generator& m_gld1, Fighter_generator& m_gld2, Normal_distribution& f_n_d);
};