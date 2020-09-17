#include"uniform_distribution.h"
#include <random> 

int uniform_distribution(int min, int max)
{
    //max-min (%x) can't be over 32767. 
    //trzeba wywolac voida od bledu z trescia ze losujemy z poza przedzialu. 

    int random = (std::rand() % (max - min) + min);
    return random;
}