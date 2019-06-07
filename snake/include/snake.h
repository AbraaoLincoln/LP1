#ifndef SNAKE_H
#define SNAKE_H

#include "common.h"
#include <queue>
#include <stack>
#include <unordered_set>

class Snake
{
    private:
        char *m_grid; //grid atual do jogo
        short m_x, m_y;
        std::stack<unsigned> path;
        std::unordered_set<unsigned> visited; //armazena as posicoes visitadas.
        //unsigned mid_rows, mid_columns;
    public:
        Snake(char * grid);
        bool find_solution(Position & snake, Position & food);
        unsigned lineColumnToindex(unsigned row, unsigned column);
        //void move_row(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        //void move_column(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        //bool around(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
};

#endif