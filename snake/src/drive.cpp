#include <iostream>
#include "snake_game.h"
#include "snake.h"

int main(int argc, char *argv[])
{
    SnakeGame maneger;
    maneger.initialize_game(argv[1]);
    maneger.render_food();

    Snake cobra{maneger.level};
    cobra.find_solution(maneger.snake, maneger.food, maneger.rows, maneger.columns);
    maneger.render_grid();
    return 0;
}