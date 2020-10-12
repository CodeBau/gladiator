#include"avarage_skills.h"

float* avarage_skills(Fighter& m_gld1)
{
    // avg[0]-min avg[1]-max avg[2]-avg
    float avg[3] = { 0,0,0 };

    //ilosc skilli w tablicy
    //0-id, 1-zdrowie, 2-wytrzymalosc, 3-odpornosc, 4-sprawnosc, 5-szybkosc, 6-sila, 7-agresja, 8-doswiadczenie
    int numb_of_skills = sizeof(m_gld1.skills[0]) / sizeof(m_gld1.skills[0][0]);

    //bez 0-id, 1-zdrowie, 8-doswiadczenie
    for (int i = 2; i < numb_of_skills - 1; i++)
    {
        avg[0] = avg[0] + m_gld1.skills[1][i];
        avg[1] = avg[1] + m_gld1.skills[2][i];
        avg[2] = avg[2] + m_gld1.skills[0][i];
    }
    numb_of_skills = numb_of_skills - 3;
    avg[0] = avg[0] / numb_of_skills;
    avg[1] = avg[1] / numb_of_skills;
    avg[2] = avg[2] / numb_of_skills;

    return avg;
}