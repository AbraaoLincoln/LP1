#include <iostream>
#include "snake_game.h"
#include "snake.h"

int main(int argc, char *argv[])
{
    SnakeGame maneger;
    maneger.initialize_game(argv[1]);
    
    while(not maneger.gamer_over())
    {
        maneger.process_events();
    }
    return 0;
}