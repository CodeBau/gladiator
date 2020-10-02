#include"skill_bar.h"
#include"globals.h"

#include<vector>
#include<string>
#include<windows.h>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<sstream>


void skill_bar(int min, int max, int skill)
{
    int bar_lnt=20;
    int skill_bar_point;
    skill_bar_point = ((skill - min) * bar_lnt) / (max - min);

    //std::cout << skill_bar_point << std::endl;

    if (skill_bar_point <= 0)
    {
        std::cout << "[" << std::string(bar_lnt, ' ') << "]";
    }
    else if (skill_bar_point == bar_lnt)
    {

        std::cout << "[";
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 34);
        std::cout << std::string(skill_bar_point, '|');
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "]";

    }
    else
    {
        std::cout << "[";
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 34);
        std::cout << std::string(skill_bar_point, '|');
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << std::string(bar_lnt - skill_bar_point, ' ') << "]";

    }

}