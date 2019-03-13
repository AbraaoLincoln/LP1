#include <iostream>
#include "../includes/main.h"
#include "../includes/game.h"

int main(void)
{
    STATUS s;
    int first, mode{3};
    first = rand() % 2;

    while(not game_over(&s))
    {
        play_game(&s, first, mode);
        //system("clear");
        show_scoreboard(&s);
    }
    return EXIT_SUCCESS;
}