#ifndef SNAKE_H
#define SNAKE_H

#include "common.h"
#include <queue>

class Snake
{
    private:
        char *m_grid;
        short m_x, m_y;
        unsigned mid_rows, mid_columns;
    public:
        Snake(char * grid);
        bool find_solution(Position & snake, Position & food, unsigned & rows, unsigned & columns);
        void move_row(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        void move_column(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        bool around(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
};

#endif