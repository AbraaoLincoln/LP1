#include <iostream>
#include "snake_game.h"
#include "snake.h"

int main(int argc, char *argv[])
{
    SnakeGame maneger;
    maneger.initialize_game(argv[1]);
    maneger.render_food();

    Snake cobra{maneger.level, maneger.rows, maneger.columns, maneger.snake};
    cobra.find_solution(maneger.snake, maneger.food);
    maneger.render_grid();
    cobra.reset();
    //std::cerr << "Upadate level\n";
    if(maneger.update_level())
    {
        //std::cerr << "1\n";
        maneger.render_food();
        //maneger.render_grid();
        cobra.update_grid(maneger.level, maneger.rows, maneger.columns);
        cobra.find_solution(maneger.snake, maneger.food);
        //std::cerr << "2\n";
        maneger.render_grid();
    }
    return 0;
}