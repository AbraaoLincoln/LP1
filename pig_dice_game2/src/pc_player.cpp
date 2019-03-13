#include <iostream>
#include "../includes/dice.h"
#include "../includes/pc_player.h"

bool pc_player::player_prob(int t, float & prob )
{
    dice dado;
    if(t != 1)
    {
        prob += dado.prob_dice(t);
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

bool pc_player::player_random()
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

bool pc_player::player_fix(float & prob)
{ 

    if(prob < (float)(1 - prob))
    {
        return true;
    }

    return false;
}