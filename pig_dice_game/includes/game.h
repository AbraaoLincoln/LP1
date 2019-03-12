#ifndef game_H
#define game_H

typedef struct {
    int g_score{0}, p_score{0};
}PLAYER;

void game();

void player_1(PLAYER & pl1);

void player_2(PLAYER & pl2);

#endif