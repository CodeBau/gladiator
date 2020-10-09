#pragma once
#include <string>
#include <vector>

//to sa tylko h od zmiennych globalnych. 
//Definicje w gladiators.cpp

//ogolna liczba zawodnikow w grze
extern int global_number_of_fighters;

//pierwszy zawodnik do walki
extern int global_1_fighter_to_fight;

//drugi zawodnik do walki
extern int global_2_fighter_to_fight;

//show fight 1-on/0-off
extern int global_show_fight_on_off;

//globalna zmienna nadajaca kolejny numer kazdemu stworzonemu gladiatorowi.
extern int global_fighter_id;

//dlugosc skill_bar paska umiejetnosci.
extern int global_bar_lnt;

//maxymalne doswiadczenie, po ktorym gladiator idzie na emeryture
extern int global_maximum_of_exp;

//Rozsuniecie pomiedzy wyswietleniem zawodnikow. 
extern int global_fighters_space;

//tablica z nazwami umiejetnosci
extern std::string global_fighter_skills_names[];

//komentarz w walce z poprzdniej rundy
extern std::string global_former_comment;

//vector z wszystkimi mozliwymi imionami gladiatora
extern std::vector <std::string> global_names;

//vector z wszystkimi mozliwymi pseudonimami gladiatora
extern std::vector <std::string> global_pseudos;

//vector z wszystkimi mozliwymi nazwiskami gladiatora
extern std::vector <std::string> global_surnames;
