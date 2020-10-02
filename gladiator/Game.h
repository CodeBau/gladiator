#pragma once
#include <ObjectArray.h>
#include "Fight.h"
#include "Fighter_generator.h"


class Game
{
public:
    void initiation();
    void loop();
    Game();
    ~Game();

private:
    Fighter_generator G_gld1;
    Fighter_generator G_gld2;
    Fighter_generator G_gld3;
    Fighter_generator G_glds[8];
    
};