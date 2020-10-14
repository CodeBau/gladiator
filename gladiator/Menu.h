#pragma once

#include"Fight.h"
#include"Fighter.h"

class Menu {
public:
    Fight fght;
    
    unsigned char user_menu_choice;
    std::vector<std::string> menu0_opt{ "1.Gladiator", "2.Arena","3.Wyjdz" };
    std::vector<std::string> menu1_opt{ "1.Zwerbuj nowego gladiatora","2.Powrot" };
    std::vector<std::string> menu11_opt{ "1.Tak","2.Zrezygnuj"};
    std::vector<std::string> menu2_opt{ "1.Pojedynek", "2.Turniej","3.Powrot" };
    std::vector<std::string> menu2_a_1_opt{ "1.Powrot" };
    std::vector<std::string> menu22_opt{ "1.Pokaz walke", "2.Symuluj walke", "3.Powrot" };
    std::vector<std::string> menu23_opt{ "1.Rozpocznij turniej", "2.Powrot" };
    std::vector<std::string> menu231_opt{ "1.Pokaz walke", "2.Symuluj walke", "3.Wyjdz z turnieju" };

    Menu();
    ~Menu();

    void show_menu_option(std::vector<std::string> menu_opt);
    void choice_menu_option(std::vector<std::string> menu_opt);
    void fighter_bar(Fighter& m_gld1);
    void menu0(std::vector <Fighter>& m_glds);
    void menu1(std::vector <Fighter> &m_glds);
    void menu11(std::vector <Fighter> &m_glds);
    void menu2(std::vector <Fighter> &m_glds);
    void menu2_a_1(std::vector <Fighter> &m_glds);
    void menu22(std::vector <Fighter> &m_glds);
    void menu23(std::vector <Fighter> &m_glds);
    void menu231(std::vector <Fighter> &m_glds, std::vector<int>& m_turnament_fighters_list);



    
};