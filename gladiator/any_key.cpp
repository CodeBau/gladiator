#include<string>
#include<iostream>
#include<conio.h>

#include"any_key.h"

void any_key ()
{
    std::string any_key;
    std::cout << std::endl << "Nacisnij dowolny klawisz aby kontynuowac..." << std::endl;
    any_key = _getch();
}
