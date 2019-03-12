#include <iostream>
#include "../includes/dado.h"

bool player1(int t, float & prob )
{
    if(t != 1)
    {
        prob += prob_dice(t);
        if(prob < (float)(1 - prob))
        {
            return true;
        }
    }else
    {
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

    if(prob < (float)(1 - prob))
    {
        return true;
    }

    return false;
}