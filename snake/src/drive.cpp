#include <iostream>
#include "snake_game.h"
#include "snake.h"

int main(int argc, char *argv[])
{
    std::string user_input;
    SnakeGame maneger;
    maneger.initialize_game(argv[1]);

    std::cout << ">>> PRESS ENTER para iniciar a simulacao\n";
    getline(std::cin, user_input);

    if(user_input == "")
    {
        while(not maneger.gamer_over())
        {
            maneger.process_events();
            maneger.update();
        }
        maneger.end_messenge();
    }else
    {
        std::cout << "Programa encerrado!\n";
    }
    
    
    return 0;
}