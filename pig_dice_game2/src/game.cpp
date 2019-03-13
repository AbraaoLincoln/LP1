#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "../includes/main.h"
#include "../includes/dice.h"
#include "../includes/game.h"
#include "../includes/pc_player.h"

void play_game(STATUS * status, int & started, int & mode)
{
    PLAYER play1, play2;

    switch(mode)
    {
        case 1:
            if(started == 0)
            {
                std::cout << "Play 1 turn:\n";
                player(play1);
                status->play1_score += play1.g_score;
                if(play1.g_score < 100)
                {
                    //std::cout << "PC turn:\n";
                    player_1(play2);
                    status->play2_score += play2.g_score;
                }
            }else
            {
                //std::cout << "PC turn:\n";
                player_1(play2);
                status->play2_score += play2.g_score;
                if(play2.g_score < 100)
                {
                    std::cout << "Play 1 turn:\n";
                    player(play1);
                    status->play1_score += play1.g_score;
                }
            }
            break;
        case 2:
            if(started == 0)
            {
                std::cout << "Play 1 turn:\n";
                player(play1);
                status->play1_score += play1.g_score;
                if(play1.g_score < 100)
                {
                    std::cout << "Play 2 turn:\n";
                    player(play2);
                    status->play2_score += play2.g_score;
                }
            }else
            {
                std::cout << "Play 2 turn:\n";
                player(play2);
                status->play2_score += play2.g_score;
                if(play2.g_score < 100)
                {
                    std::cout << "Play 1 turn:\n";
                    player(play1);
                    status->play1_score += play1.g_score;
                }
            }
            break;
        case 3:
            if(started == 0)
            {
                player_1(play1);
                status->play1_score += play1.g_score;
                if(play1.g_score < 100)
                {
                    player_2(play2);
                    status->play2_score += play2.g_score;
                }
            }else
            {
                player_2(play2);
                status->play2_score += play2.g_score;
                if(play2.g_score < 100)
                {
                    player_1(play1);
                    status->play1_score += play1.g_score;
                }
            }
            
            break;
        default:
            std::cout << "Erro!" << std::endl;
    }
}

void show_scoreboard(STATUS * status)
{
    std::ostringstream line;

    line << std::setw(18) << std::setfill('=') << "=";
    std::cout << line.str() << std::endl;
    std::cout << "|   " << "SCOREBOARD" << "   |" << std::endl;
    std::cout << line.str() << std::endl;
    std::cout << "| " << "Jogador 1: " << std::setw(3) << std::setfill(' ') << status->play1_score << " |" << std::endl;
    std::cout << "| " << "Jogador 2: " << std::setw(3) << std::setfill(' ') << status->play2_score << " |" << std::endl;
    std::cout << line.str() << std::endl;

    if(status->play1_score >= 100 or status->play2_score >= 100)
    {
        if(status->play1_score >= 100)
        {
            std::cout << "Play 1 wins!" << std::endl;
        }else
        {
            std::cout << "Play 2 wins!" << std::endl;
        }
        
    }
}

bool game_over(STATUS * status)
{
    if(status->play1_score >= 100 or status->play2_score >= 100)
    {
        return true;
    }else
    {
        return false;
    }
    
}

void player(PLAYER & play)
{
    dice d;
    std::string choice{""};
    int face_up{0};
    std::vector<int> values;

    do
    {

        face_up = d.roll_dice();
        values.push_back(face_up);
        if(face_up != 1)
        {
            play.p_score += face_up;
            std::cout << "Press enter to roll the dice or type anything to finish your turn: " << std::endl;
            for(unsigned i{0}; i < values.size(); i++)
            {
                std::cout << i+1 << "-" << values[i] << ": ";
            }
            std::cout << "Total turn: " << play.p_score << std::endl;
            getline(std::cin, choice);
        }else
        {
            play.p_score = 0;
            choice = "lose";
        }

    }while(choice == "");

    play.g_score += play.p_score;
}

void player_1(PLAYER & play1)
{
    int roll{0};
    dice dado;

    for(int i{0}; i < 4;i++)
    {
        roll = dado.roll_dice();
        if( roll != 1)
        {
            play1.p_score += roll;
            if((play1.g_score + play1.p_score) >= 100)
            {
                 break;
            }

        }else
        {
            play1.p_score = 0;
            break;
        }
    }
    play1.g_score += play1.p_score;
    play1.p_score = 0;
}

void player_2(PLAYER & play2)
{
    int roll{0}, r{1};
    float prob{0};
    pc_player pc;
    dice dado;

    while(pc.player_prob(r, prob))
    {
        roll = dado.roll_dice();
        if( roll != 1)
        {
            play2.p_score += roll;
            r++;
            if((play2.g_score + play2.p_score) >= 100)
            {
                 break;
            }

            }else
            {
                play2.p_score = 0;
                 break;
            }

            }

            play2.g_score += play2.p_score;
            play2.p_score = 0;
            prob = 0;
            r = 1;
}