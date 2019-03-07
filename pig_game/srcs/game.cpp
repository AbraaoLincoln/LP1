#include "../includes/player.h"
#include "../includes/dado.h"
#include <iostream>

void game(){
    int g_score1{0}, g_score2{0}, p_score1{0}, p_score2{0},r{1}, roll{0};
    float prob1{0}, prob2{0};

    while(g_score1 < 100 and g_score2 < 100)
    {
        if(g_score1 < 100)
        {
                while(player1(r, prob1))
                {
                    roll = roll_dice(6);
                    if( roll != 1)
                    {
                        p_score1 += roll;
                        r++;
                        std::cout << p_score1 << ", ";
                    }else
                    {
                        p_score1 = 0;
                        break;
                    }

                }
                std::cout << std::endl;
                g_score1 += p_score1;
                p_score1 = 0;
                prob1 = 0;
                r = 1;
        } 
        if(g_score1 < 100)
        {
                while(player1(r, prob2))
                {
                    roll = roll_dice(6);
                    if( roll != 1)
                    {
                        p_score2 += roll;
                        r++;
                        //std::cout << p_score1 << ", ";
                    }else
                    {
                        p_score2 = 0;
                        break;
                    }

                }
                //std::cout << std::endl;
                g_score2 += p_score2;
                p_score2 = 0;
                prob2 = 0;
                r = 1;
        }

        //std::cout << "Jogador 1: " << prob1 << std::endl;
        //std::cout << "Jogador 2: " << prob2 << std::endl;
    }

    std::cout << "Jogador 1: " << g_score1 << std::endl;
    std::cout << "Jogador 2: " << g_score2 << std::endl;

}