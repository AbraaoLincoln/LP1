#include <iostream>
#include "../include/dice.h"

int dice::roll_dice(int n_faces)
{
    int face{0};
    face = rand() % n_faces + 1;
    return face;
}

float dice::prob_relt(int times)
{
    float prob{0};
    int count{0};

    for(int i{0}; i < times; i++)
    {
        if(roll_dice(6) == 1)
        {
            count++;
        }
    }

    prob = (float)count / (float)times;
    return prob;
}

float dice::prob_dice(int rolls)
{
    float count{0}, prob{0};

    for(int i{0}; i < 10;i++)
    {
        count += prob_relt(rolls);          
    }

    prob = count / 10;    
    return prob;
}