#include "Normal_distribution.h"
#include "uniform_distribution.h"



//to jest metoda generujaca vector z wartosciami z rozkladu normalnego generuje wartosci 1:1, 1:2, 1:3...2:6, 2:7... 10:24... itd.
std::vector<int> Normal_distribution::normal_distribution_values_generate()
{

    //vectro przetrzymujacy wszystkie wygenerowane liczy z rozkladu normalnego wg vectora repeat 
    std::vector<int> normal_distribution_values{};

    for (int i = 0; i < repeat.size(); i++)
    {
        for (int j = 0; j < repeat[i]; j++)
            normal_distribution_values.push_back(i);
    }

    
    return normal_distribution_values;
}
    //to jest float ktory bedzie wybieral losowa liczbe z rozkladu normalnego z przedzialu liczb value1 i value2
float Normal_distribution::normal_distribution_values_use(int value1, int value2)
{

    //losujemy na pusto
    uniform_distribution(0, n_d.size() - 1);

    //zakres jest suma value1 i value2 bo one beda staly po przeciwnej stronie osi 50 | 70 (120)
    int values_range = (value1 + value2);
    


    //losujemy rozkladem jednostajnym (splaszczamy losowanie do wybrania liczby z vectora z liczbami rozkladu normalnego)
    int n_d_random = n_d[uniform_distribution(0, n_d.size() - 1)];
    int y = repeat.size();

    //float daje wynik przeskalowany z rozkladu normalnego od 0-201 na 0 do range. Czyli dla wartosci porownawczych 
    //value1=50 i value2=70 da wartosc z przedzialu 0-120 trzeba sprawdzic czy zmiescilo sie przed polowa =60 jest to os symetrii czyli 101 w liczbach rozkladu normalnego. 
    float x = (float)(values_range * n_d_random) / (y);

    return x;
}




