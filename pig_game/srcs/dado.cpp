#include <iostream>
#include <stdlib.h>
#include <ctime>

int roll_dice(int n_faces)
{
    int face{0};
    face = rand() % n_faces + 1;
    return face;
}

float prob_relt(int times)
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

float prob_dice(int rolls)
{
    //int trys[] = {2 , 3, 4};
    float count{0}, prob{0};

    for(int i{0}; i < 10;i++)
    {
        count += prob_relt(rolls);          
    }

    prob = count / 10;    
    //std::cout << prob;   
    return prob;

    /*
    for(int i{0}; i < 3;i++)
    {   
        //std::cout << "Jogada " << trys[i] << ": " << std::endl;
        for(int j{0}; j < 10;j++)
        {
            prob = prob_relt(trys[i]);
            count += prob;
            //std::cout << prob << ", ";
        }

        prob = count / 10;
        //std::cout << std::endl << "Media: " << prob << "\n" << std::endl;
        count = 0;
    }
    */
}