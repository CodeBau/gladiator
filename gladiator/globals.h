#pragma once
#include <string>

//to sa tylko h od zmiennych globalnych. 
//Deinicje w gladiators.cpp

//globalna zmienna potwierdzajaca istnienie gladiatora gracza.
extern int global_fighter_exist;

//globalna zmienna nadajaca kolejny numer kazdemu stworzonemu gladiatorowi.
extern int global_gladiator_id;

//dlugosc skill_bar paska umiejetnosci.
extern int global_bar_lnt;

//Rozsuniecie pomiedzy wyswietleniem zawodnikow. 
extern int global_fighters_space;

//Tabela z nazwami umiejetnosci
extern std::string global_fighter_skills[];

//komentarz w walce z poprzdniej rundy
extern std::string global_former_comment;