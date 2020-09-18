#pragma once


class Menu {
public:
    unsigned char user_menu_choice;
    std::vector<std::string> menumain_opt{ "1.Gladiator", "2.Walka","3.Wyjdz" };
    std::vector<std::string> menu1_opt{ "1.Zwerbuj nowego gladiatora","2.Powrot" };
    std::vector<std::string> menu2_opt{ "1.Trening", "2.Pojedynek", "3.Turniej","4.Powrot" };

    void show_menu_option(std::vector<std::string> menu_opt);
    void choice_menu_option(std::vector<std::string> menu_opt);
    void menumain(Fighter_generator& gld1);
    void menu1(Fighter_generator& gld1);
    void menu2(Fighter_generator& gld1);
};