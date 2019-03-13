#ifndef GAME_H
#define GAME_H

typedef struct
{
    int g_score{0}, p_score{0};
}PLAYER;

void play_game(STATUS * status, int & started, int & mode);

void show_scoreboard(STATUS * status);

bool game_over(STATUS * status);

void player(PLAYER & play);

void player_1(PLAYER & play1);

void player_2(PLAYER & play2);

#endif