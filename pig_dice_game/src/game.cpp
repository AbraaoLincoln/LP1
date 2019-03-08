#include "../includes/player.h"
#include "../includes/dado.h"
#include <iostream>

void game(int & p1, int & p2){
    int g_score1{0}, g_score2{0}, p_score1{0}, p_score2{0},r{1}, roll{0};
    float prob1{0}, prob2{0};

    while(g_score1 < 100 and g_score2 < 100)
    {
        if(g_score1 < 100)
        {
            for(int i{0}; i < 4;i++)
            {
                roll = roll_dice();
                if( roll != 1)
                {
                    p_score1 += roll;
                    prob1 += 0.15;
                    if((g_score1 + p_score1) >= 100)
                    {
                        break;
                    }

                }else
                {
                    p_score1 = 0;
                    break;
                }
            }
                g_score1 += p_score1;
                p_score1 = 0;
                prob1 = 0;
            
        } 
        if(g_score1 < 100)
        {
                while(player1(r, prob2))
                {
                    roll = roll_dice();
                    if( roll != 1)
                    {
                        p_score2 += roll;
                        //prob2 += 0.15;
                        r++;
                        if((g_score2 + p_score2) >= 100)
                        {
                            break;
                        }

                    }else
                    {
                        p_score2 = 0;
                        break;
                    }

                }

                g_score2 += p_score2;
                p_score2 = 0;
                prob2 = 0;
                r = 1;
        }

    }

    std::cout << "Jogador 1: " << g_score1 << std::endl;
    std::cout << "Jogador 2: " << g_score2 << std::endl;

    if(g_score1 > g_score2)
    {
        p1++;
    }else
    {
        p2++;
    }
    

}