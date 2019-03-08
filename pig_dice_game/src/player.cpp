#include "../includes/dado.h"
#include <iostream>

bool player1(int t, float & prob )
{
    prob += prob_dice(t);
    //std::cout << prob;
    if(prob < (float)(1 - prob))
    {
        //std::cout << "aqui";
        return true;
    }

    return false;
}

bool player_R()
{
    int yes{-1};
    yes = rand() % 2;

    if(yes == 1)
    {
        return true;
    }else
    {
        return false;
    }
}

bool player_F(float & prob)
{ 
    //std::cout << prob << std::endl;
    if(prob < (float)(1 - prob))
    {
        return true;
    }

    return false;
}