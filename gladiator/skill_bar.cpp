#include"skill_bar.h"
#include <iostream>
#include <vector>
#include <string>



void skill_bar(int min, int max, int skill)
{
    int bar_lnt=20;
    int skill_bar_point;
    skill_bar_point = ((skill - min) * bar_lnt) / (max - min);

    std::cout << skill_bar_point << std::endl;
}