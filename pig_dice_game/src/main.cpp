#include <iostream>
#include <ctime>
#include "../includes/game.h"

int main()
{
    srand(time(NULL));
    game();
    /*
    for(int i{0}; i < 10;i++)
    {
        game(p1, p2);
        std::cout << "===============" << std::endl;
    }
    */
    return 0;
}