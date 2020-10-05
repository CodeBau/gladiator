#include"fight_commentary.h"
#include"Fighter.h"
#include"uniform_distribution.h"
#include"globals.h"


#include<vector>
#include<string>
#include<windows.h>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<sstream>

void fight_commentary(Fighter& f_gld1, Fighter& f_gld2, float f_hit, float f_max_hit)
{
	std::string att_option[]={"szykuje sie do ataku", "atakuje", "rusza z atakiem", "naciera", "robi zamach" };
	std::string att_form[]={"Zadaje", "Uderza","Kopie", "Wali" };
	std::string att_strength[]={"delikatnie", "slabo", "solidnie", "mocno", "poteznie", "krytycznie" };
	std::string att_strength1[]={"delikatny", "slaby", "solidny", "mocny", "potezny", "krytyczny" };
	std::string att_aim[] = { "glowe", "udo", "ramie", "korpus", "watrobe", "szczeke", "oko", "kolano", "szyje" };
	std::string present_comment;


	if (global_former_comment!="")
	{ 
		//ustawienie koloru tekstu konsoli na ciemno szary
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << global_former_comment << std::endl;

		//powrot koloru do jasno szarego
		SetConsoleTextAttribute(hConsole, 7);
	}
	
	present_comment=f_gld1.name + " " + att_option[uniform_distribution(0, sizeof(att_option) / sizeof(att_option[0]))] + "\n";

	int wich_form = uniform_distribution(0, sizeof(att_form) / sizeof(att_form[0]));
	int wich_strenght=f_hit/(f_max_hit/(sizeof(att_strength) / sizeof(att_strength[0])));
	int wich_aim = uniform_distribution(0, sizeof(att_aim) / sizeof(att_aim[0]));

	if (wich_form == 0)
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(1) << f_hit;
		present_comment = present_comment + att_form[wich_form] + " " + att_strength1[wich_strenght] + " (" + ss.str() + ") cios w " + att_aim[wich_aim];
		std::cout<<present_comment << std::endl;
	}
	else
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(1) << f_hit;
		present_comment = present_comment + att_form[wich_form] + " " + att_strength[wich_strenght] + " (" + ss.str() + ") w " + att_aim[wich_aim];
		std::cout << present_comment << std::endl;
	}
	Sleep(50);
	global_former_comment = present_comment;
};
