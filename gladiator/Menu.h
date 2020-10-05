#pragma once

#include"Fight.h"
#include"Fighter.h"
#include"Normal_distribution_old.h"


class Menu {
public:
    Fight fght;
    
    unsigned char user_menu_choice;
    std::vector<std::string> menumain_opt{ "1.Gladiator", "2.Walka","3.Wyjdz" };
    std::vector<std::string> menu1_opt{ "1.Zwerbuj nowego gladiatora","2.Powrot" };
    std::vector<std::string> menu11_opt{ "1.Tak","2.Zrezygnuj"};
    std::vector<std::string> menu2_opt{ "1.Trening", "2.Pojedynek", "3.Turniej","4.Powrot" };

    Menu();
    ~Menu();

    void fighter_bar(Fighter& m_gld1);
    void show_menu_option(std::vector<std::string> menu_opt);
    void choice_menu_option(std::vector<std::string> menu_opt);
    void menu0(std::vector <Fighter> &m_glds);
    void menu1(std::vector <Fighter> &m_glds);
    void menu11(std::vector <Fighter> &m_glds);
    void menu2(std::vector <Fighter> &m_glds);



    
};