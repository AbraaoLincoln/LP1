#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <iostream>
#include <fstream>
#include "../include/snake.h"
#include "common.h"

class SnakeGame
{
    private:
        Snake *m_snakeAI;
        char *level;
        unsigned rows, columns, foodsToEat;
        Position snake, food, spawn;
        std::ifstream file_input;
        States state;
    public:
        SnakeGame();
        ~SnakeGame();
        void initialize_game(std::string file_name);
        void get_RowsColumns(std::string & line);
        bool update_level();
        void update();
        void render_food();
        bool check_sidesFood(Position & food);
        void render_grid();
        void render_snakeMovement();
        void process_events();
        bool gamer_over();
        void end_messenge();
        void render_snakeKamikaze();
        void wait_user(short event);

};


#endif