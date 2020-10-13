#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#include "globals.h"
#include "Fighter.h"
#include "Menu.h"
#include "Game.h"
#include "skill_bar.h"
#include "avarage_skills.h"

    Menu::Menu()
    {
        user_menu_choice = 0;
    }
    Menu::~Menu()
    {
    }


    void Menu::fighter_bar(Fighter& m_gld1)
    {
        int line_lenght = 100;
        if (m_gld1.skills[0][0] == 0)
        {
            std::cout << std::string(line_lenght,'-') << std::endl;
            std::cout << "Nie posiadasz gladiatora, mozesz go zwerbowac w zakladce gladiator" << std::endl;
            std::cout << std::string(line_lenght, '-') << std::endl;
        }
        else
        {
            std::cout << std::string(line_lenght, '-') << std::endl;
            std::cout << "Name: " << m_gld1.name << "    " << global_fighter_skills_names[8];
            skill_bar(m_gld1.skills[1][8], m_gld1.skills[2][8], m_gld1.skills[0][8]);
            std::cout << "    Avg:";
            skill_bar(avarage_skills(m_gld1)[0], avarage_skills(m_gld1)[1], avarage_skills(m_gld1)[2]);
            std::cout << std::endl;
            std::cout << std::string(line_lenght, '-') << std::endl;
        }
    }

    void Menu::show_menu_option(std::vector<std::string> menu_opt)
    {
        for (unsigned int i = 0; i < menu_opt.size(); i++)
        {
            std::cout << menu_opt[i] << std::endl;
        }
    }

    void  Menu::choice_menu_option(std::vector<std::string> menu_opt)
    {
        std::cout << std::endl;
        if (menu_opt.size() > 1)
            std::cout << "Dokonaj wyboru: (" << 1 << " - " << menu_opt.size() << ") " << std::endl;
        else
            std::cout << "Dokonaj wyboru: 1" << std::endl;

        user_menu_choice = _getch();
    }

    //menu gry
    void  Menu::menu0(std::vector <Fighter> &m_glds)
    {
        system("cls");
        std::cout << "******MENU******"<< std::endl;
        fighter_bar(m_glds[1]);
        show_menu_option(menu0_opt);
        choice_menu_option(menu0_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu1(m_glds);
            break;
        case '2':
            if (m_glds[1].skills[0][0] != 0)
            menu2(m_glds);
            else 
            menu2_a_1(m_glds);
            break;
        case '3':
            exit(0);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu0(m_glds);
        }
    }
    //Menu gladiatora
    void  Menu::menu1(std::vector <Fighter> &m_glds)
    {
        system("cls");
        std::cout << "******MENU - Gladiator******" << std::endl << std::endl;

        if (m_glds[1].skills[0][0] != 0)
        {
            m_glds[1].show_stats();
        }

        else
        {
            std::cout << "Nie posiadasz gladiatora";
        }
        
        std::cout << std::endl;
        show_menu_option(menu1_opt);
        choice_menu_option(menu1_opt);
        switch (user_menu_choice)
        {
        case '1':
        {
            if (m_glds[1].skills[0][0] != 0)
            {
             menu11(m_glds);
            }
            else
            {
             m_glds[1].generate_stats();
             //oznaczenie gladiatora gracza
             m_glds[1].skills[1][0] = 1;
             menu1(m_glds);
            }
            break;
        }
        case '2':
            menu0(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu1(m_glds);
        }
    }

    //Pytanie czy zwerbowac nowego gdy posiadasz juz jednego
    void  Menu::menu11(std::vector <Fighter> &m_glds)
    {
        system("cls");
        std::cout << "******MENU - Werbowac nowego******" << std::endl << std::endl;
        m_glds[1].show_stats();
        std::cout << "Posiadasz juz Gladiatora, czy zastapic istniejacego" << std::endl << std::endl;
        show_menu_option(menu11_opt);
        choice_menu_option(menu11_opt);
        switch (user_menu_choice)
        {
        case '1':
            m_glds[1].generate_stats();
            //oznaczenie gladiatora gracza
            m_glds[1].skills[1][0] = 1;
            menu1(m_glds);
            break;
        case '2':
            menu1(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2(m_glds);
        }
    }

    //Menu Arena
    void  Menu::menu2(std::vector <Fighter> &m_glds)
    {
        system("cls");
        std::cout << "******Arena******" << std::endl;
        fighter_bar(m_glds[1]);
        show_menu_option(menu2_opt);
        choice_menu_option(menu2_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu2(m_glds);
break;
        case '2':
            menu22(m_glds);
            break;
        case '3':
            menu23(m_glds);
            break;
        case '4':
            menu0(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2(m_glds);
        }
    }

    //Menu Arena_alternatywa_1 - brak gladiatora
    void  Menu::menu2_a_1(std::vector <Fighter>& m_glds)
    {
        system("cls");
        std::cout << "******Arena******" << std::endl;
        fighter_bar(m_glds[1]);
        std::cout << "Musisz posiadac gladiatora, aby przystapic do walki" << std::endl;
        show_menu_option(menu2_a_1_opt);
        choice_menu_option(menu2_a_1_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu0(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2(m_glds);
        }
    }

    //Menu pojedynku
    void  Menu::menu22(std::vector <Fighter>& m_glds)
    {
        system("cls");
        std::cout << "******Pojedynek******" << std::endl;
        global_1_fighter_to_fight = 1;
        fght.duel_start(m_glds);
        fght.fight_show_stats(m_glds[global_1_fighter_to_fight], m_glds[global_2_fighter_to_fight]);
        show_menu_option(menu22_opt);
        choice_menu_option(menu22_opt);
        switch (user_menu_choice)
        {
        case '1':
            global_show_fight_on_off = 1;
            fght.duel(m_glds);
            break;
        case '2':
            global_show_fight_on_off = 0;
            fght.duel(m_glds);
            break;
        case '3':
            global_1_fighter_to_fight = 0;
            global_2_fighter_to_fight = 0;
            menu2(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu22(m_glds);
        }
    }

    //Menu turnieju
    void  Menu::menu23(std::vector <Fighter>& m_glds)
    {
        system("cls");
        std::cout << "******Turniej******" << std::endl;
        std::vector <int> temp_list = fght.turnament_generate(m_glds);
        fght.turnament_start(m_glds, temp_list);
        show_menu_option(menu23_opt);
        choice_menu_option(menu23_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu231(m_glds, temp_list);
            break;
        case '2':
            menu2(m_glds);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu23(m_glds);
        }
    }

    //Menu turnieju - 1 runda
    void  Menu::menu231(std::vector <Fighter>& m_glds, std::vector<int>& m_turnament_fighters_list)
    {
        int do_you_want_exit = 0;

        //wstepnie 5
        for (int j=1;j<5;j++)
        {
            for (int i = 0; i < m_turnament_fighters_list.size(); i = i + 2)
            {
                system("cls");
                std::cout << j <<" "<< i << std::endl;
                std::cout << "******Turniej - Runda 1******" << std::endl;
                fght.turnament_start(m_glds, m_turnament_fighters_list);
                show_menu_option(menu231_opt);
                choice_menu_option(menu231_opt);
                switch (user_menu_choice)
                {
                case '1':
                    global_show_fight_on_off = 1;
                    fght.fight_aggression_stage(m_glds[m_turnament_fighters_list[i]], m_glds[m_turnament_fighters_list[i + 1]]);
                    fght.turnament_fight_end(m_glds[m_turnament_fighters_list[i]], m_glds[m_turnament_fighters_list[i + 1]], m_turnament_fighters_list);
                    global_show_fight_on_off = 0;
                    break;
                case '2':
                    global_show_fight_on_off = 0;
                    fght.fight_aggression_stage(m_glds[m_turnament_fighters_list[i]], m_glds[m_turnament_fighters_list[i + 1]]);
                    fght.turnament_fight_end(m_glds[m_turnament_fighters_list[i]], m_glds[m_turnament_fighters_list[i + 1]], m_turnament_fighters_list);
                    break;
                case '3':
                    do_you_want_exit = 1;
                    break;
                default:
                    std::cout << "Nie ma takiej opcji";
                    Sleep(500);
                    menu231(m_glds, m_turnament_fighters_list);
                }
            }


            //trzeba dodac sprawdzenia w raz z any_key
            for (int i = 0; i < m_turnament_fighters_list.size(); i++)
            {
                if (m_glds[m_turnament_fighters_list[i]].skills[0][0] == 0)
                {
                    m_turnament_fighters_list.erase(m_turnament_fighters_list.begin() + i);
                }
            }

        }
    }
       
    