#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <iostream>
#include <fstream>
#include "common.h"

class SnakeGame
{
    private:
        //char *level;
        //unsigned rows, columns;
        //Position snake, food;
        std::ifstream file_input;
    public:
        SnakeGame();
        ~SnakeGame();
        void initialize_game(std::string file_name);
        void get_RowsColumns(std::string & line);
        bool update_level();
        void render_food();
        void render_grid();
        char *level;
        unsigned rows, columns;
        Position snake, food;
};


#endif