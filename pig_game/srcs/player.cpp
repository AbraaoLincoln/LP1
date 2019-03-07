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