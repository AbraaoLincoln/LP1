#ifndef SNAKE_H
#define SNAKE_H

#include "common.h"
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

class Snake
{
    private:
        char *m_grid; //grid atual do jogo
        unsigned m_rows, m_columns;
        std::stack<unsigned> path;
        std::unordered_set<unsigned> visited; //armazena as posicoes visitadas.
        std::vector<std::vector<unsigned> > shortest_path;
        std::queue<Position> fila;
        //unsigned mid_rows, mid_columns;
    public:
        Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake);
        bool find_solution(Position & snake, Position & food);
        bool find_solution2(Position & snake, Position & food);
        unsigned lineColumnToindex(unsigned i, unsigned j);
        void render_path();
        unsigned find_path(unsigned pst);
        unsigned abs(int value);
        bool wall_side(Position & snake, Position & food);
        //void move_row(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        //void move_column(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
        //bool around(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path);
};

#endif