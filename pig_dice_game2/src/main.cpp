#include <iostream>
#include <ctime>
#include "../include/main.h"
#include "../include/game.h"

int main(void)
{
    status sts;
    int first, mode{3};
    srand(time(NULL));
    game_menu(mode);
    game_start(first);

    while(not game_over(sts))
    {
        play_game(sts, first, mode);
        system("clear");
        show_scoreboard(sts);
    }
    return EXIT_SUCCESS;
}