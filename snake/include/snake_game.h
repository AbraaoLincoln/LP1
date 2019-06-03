#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <iostream>
#include "common.h"

class SnakeGame
{
    private:
        //char *level;
        //unsigned rows, columns;
        //Position snake, food;
    public:
        SnakeGame();
        ~SnakeGame();
        void initialize_game(std::string file_name);
        void render_food();
        void render_grid();
        char *level;
        unsigned rows, columns;
        Position snake, food;
};


#endif