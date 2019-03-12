#include <iostream>
#include <iomanip>
#include "../includes/player.h"
#include "../includes/dado.h"

typedef struct {
    int g_score{0}, p_score{0};
}PLAYER;

void player_1(PLAYER & pl1)
{
    int roll{0};

    for(int i{0}; i < 4;i++)
    {
        roll = roll_dice();
        if( roll != 1)
        {
            pl1.p_score += roll;
            //prob1 += 0.15;
            if((pl1.g_score + pl1.p_score) >= 100)
            {
                 break;
            }

        }else
        {
            pl1.p_score = 0;
            break;
        }
    }
    pl1.g_score += pl1.p_score;
    pl1.p_score = 0;
}

void player_2(PLAYER & pl2)
{
    int roll{0}, r{1};
    float prob{0};

    while(player1(r, prob))
    {
        roll = roll_dice();
        if( roll != 1)
        {
            pl2.p_score += roll;
            //prob2 += 0.15;
            r++;
            if((pl2.g_score + pl2.p_score) >= 100)
            {
                 break;
            }

            }else
            {
                pl2.p_score = 0;
                 break;
            }

            }

            pl2.g_score += pl2.p_score;
            pl2.p_score = 0;
            prob = 0;
            r = 1;
}

void game()
{
    PLAYER pl1, pl2;

    while(pl1.g_score < 100 and pl2.g_score < 100)
    {

        player_2(pl1);
        player_1(pl2);

    }

    std::cout << "Jogador 1: " << pl1.g_score << std::endl;
    std::cout << "Jogador 2: " << pl2.g_score << std::endl;

}