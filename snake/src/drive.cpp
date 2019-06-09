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

    while(maneger.update_level())
    {
        maneger.render_food();
        cobra.update_grid(maneger.level, maneger.rows, maneger.columns);
        cobra.find_solution(maneger.snake, maneger.food);
        maneger.render_grid();
        cobra.reset();
    }

    return 0;
}