#include <iostream>
#include <ctime>
#include "../includes/main.h"
#include "../includes/game.h"

int main(void)
{
    status sts;
    int first, mode{3};
    srand(time(NULL));
    game_menu(mode);
    first = rand() % 2;
    std::cout << "Play " << first+1 << " start" << std::endl;

    while(not game_over(sts))
    {
        //show_scoreboard(&s);
        play_game(sts, first, mode);
        system("clear");
        show_scoreboard(sts);
    }
    return EXIT_SUCCESS;
}