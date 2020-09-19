#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#include "globals.h"
#include "Fighter_generator.h"
#include "Menu.h"
#include "Game.h"


    void Menu::show_menu_option(std::vector<std::string> menu_opt)
    {
        for (int i = 0; i < menu_opt.size(); i++)
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

    //menuglowne gry
    void  Menu::menumain(Fighter_generator& m_gld1)
    {
        system("cls");
        std::cout << "******MENU******" << std::endl << std::endl;
        show_menu_option(menumain_opt);
        choice_menu_option(menumain_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu1(m_gld1);
            break;
        case '2':
            menu2(m_gld1);
            break;
        case '3':
            exit(0);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menumain(m_gld1);
        }
    }
    //Menu gladiatora
    void  Menu::menu1(Fighter_generator& m_gld1)
    {
        system("cls");
        std::cout << "******MENU - Gladiator******" << std::endl << std::endl;

        if (global_fighter_exist == 1)
        {
            m_gld1.show_stats();
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
            if (global_fighter_exist == 1)
            {
             menu11(m_gld1);
            }
            else
            {
             global_fighter_exist = 1;
             m_gld1.generate_stats();
             menu1(m_gld1);
            }
            break;
        }
        case '2':
            menumain(m_gld1);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu1(m_gld1);
        }
    }

    //Pytanie czy zwerbowac nowego gdy istnieje
    void  Menu::menu11(Fighter_generator& m_gld1)
    {
        system("cls");
        std::cout << "******MENU - Werbowac nowego******" << std::endl << std::endl;
        m_gld1.show_stats();
        std::cout << "Posiadasz juz Gladiatora, czy zastapic istniejacego" << std::endl << std::endl;
        show_menu_option(menu11_opt);
        choice_menu_option(menu11_opt);
        switch (user_menu_choice)
        {
        case '1':
            m_gld1.generate_stats();
            menu1(m_gld1);
            break;
        case '2':
            menu1(m_gld1);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2(m_gld1);
        }
    }

    //Menu walk
    void  Menu::menu2(Fighter_generator& m_gld1)
    {
        system("cls");
        std::cout << "******MENU - Walka******" << std::endl << std::endl;
        show_menu_option(menu2_opt);
        choice_menu_option(menu2_opt);
        switch (user_menu_choice)
        {
        case '1':
            menu2(m_gld1);
            break;
        case '2':
            menu2(m_gld1);
            break;
        case '3':
            menu2(m_gld1);
            break;
        case '4':
            menumain(m_gld1);
            break;
        default:
            std::cout << "Nie ma takiej opcji";
            Sleep(500);
            menu2(m_gld1);
        }
    }

   
        
       
    