#ifndef GAME_H
#define GAME_H

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"

struct PLAYER
{
    int g_score{0}, p_score{0};
};

void play_game(status & sts, int & started, int & mode);

void show_scoreboard(status & sts);

void game_menu(int & mode);

int game_start(int & first);

bool game_over(status & sts);

void player(PLAYER & play);

void player_1(PLAYER & play1);

void player_2(PLAYER & play2);

#endif