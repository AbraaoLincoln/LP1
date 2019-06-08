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
    public:
        Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake);
        //Metodos para achar o menor caminho
        bool find_solution(Position & snake, Position & food);
        unsigned lineColumnToindex(unsigned i, unsigned j);
        unsigned find_path(unsigned pst);
        bool check_sides(Position & snake);
        void render_path(Position & food);
        Position update_position(Position & snake, short next);
        //Metodos para encontrar um caminho
        bool find_any_solution(Position & snake, Position & food);
        unsigned abs(int value);
        bool wall_side(Position & snake, Position & food);
};

#endif