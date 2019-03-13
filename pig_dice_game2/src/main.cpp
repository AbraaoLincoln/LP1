#include <iostream>
#include <ctime>
#include "../includes/main.h"
#include "../includes/game.h"

int main(void)
{
    STATUS s;
    int first, mode{1};
    srand(time(NULL));
    first = rand() % 2;
    std::cout << "Play " << first+1 << " start" << std::endl;

    while(not game_over(&s))
    {
        //show_scoreboard(&s);
        play_game(&s, first, mode);
        system("clear");
        show_scoreboard(&s);
    }
    return EXIT_SUCCESS;
}