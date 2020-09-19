#include "globals.h"
#include "Fight.h"
#include "Fighter_generator.h"
#include "Normal_distribution.h"


//0-id, 1-zdrowie, 2-wytrzymalosc, 3-sprawnosc, 4-szybkosc, 5- sila, 6-agresja, 7-doswiadczenie 
    void Fight::fight_stages_view (Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d)
    {   
        f_gld1.show_stats();
        f_gld2.show_stats();

        while ((f_gld1.gladiator[1]>0) & (f_gld2.gladiator[1] > 0))
        { 
            int x6 = f_gld1.gladiator[6];
            //std::cout <<"Agresja "<< f_gld1.name<<" : "<<x6<< std::endl;
            int y6 = f_gld2.gladiator[6];
            //std::cout << "Agresja " << f_gld2.name << " : " << y6 << std::endl;
            float los = f_n_d.normal_distribution_values_use(x6, y6);
            std::cout << "Wylosowana: " << los << std::endl;
        
            if (los< x6)
            {
                fightatack_view(f_gld1, f_gld2,f_n_d);
            }

            else
            { 
                fightatack_view(f_gld2, f_gld1,f_n_d);
            }
        }
        
    }

    void Fight::fightatack_view(Fighter_generator& f_gld1, Fighter_generator& f_gld2, Normal_distribution& f_n_d)
    {
        //naddatek do szybkosc
        int nad = 20;
        int uderzenie;
        int minus_hp;

        //std::cout << "Atakuje " << f_gld1.name << std::endl;
        int x4 = f_gld1.gladiator[4];
        //std::cout << "Szybkosc " << f_gld1.name << x4 << std::endl;
        //std::cout << "Szybkosc " << f_gld1.name << " powiekszona o + naddatek: " << x4 + nad << std::endl;
        int y3 = f_gld2.gladiator[3];
       //std::cout << "Sprawnosc " << f_gld2.name << " : " << y3 << std::endl;
        float los = f_n_d.normal_distribution_values_use(x4 + nad, y3);
        //std::cout << "Wylosowana: " << los << std::endl;
        float procent = los * 100 / (x4 + nad + y3);
        //std::cout << "W procentach: " << procent << std::endl;

        int x5 = f_gld1.gladiator[5];
        //std::cout << "Sila " << f_gld1.name << " : " << x5 << std::endl;
        uderzenie = x5 * procent / 100;
        //std::cout << "Uderzenie: " << uderzenie << std::endl;
        int y2 = f_gld2.gladiator[2];
        //std::cout << "Wytrzymalosc " << f_gld2.name << " : " << y2 << std::endl;
        minus_hp = uderzenie*1.0/y2*15;
        std::cout << "-HP: " << minus_hp<< std::endl;
        int y1 = f_gld2.gladiator[1];
        //std::cout << "Zdrowie " << f_gld2.name << " : " << y1 << std::endl;
        f_gld2.gladiator[1] = f_gld2.gladiator[1] - minus_hp;
        y1 = f_gld2.gladiator[1];
        std::cout << "Zdrowie " << f_gld2.name << " postrzale : " << y1 << std::endl;

        std::cout <<"[ ][ ][ ][ ][ ]"<< std::endl;
        std::cout <<"[+][+][+][ ][ ]"<< std::endl;
        std::cout <<"[++++______]"<< std::endl;
        std::cout <<"[|||||||||||||||||||||]"<< std::endl;
        std::cout <<"[||||||||||           ]"<< std::endl;

    }
     


    void Fight::duel()

    {

    }

    void Fight::turnament()
    {

    }

    Fight::Fight()
    {

    }

    Fight::~Fight()
    {

    }