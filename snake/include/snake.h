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
        std::unordered_set<unsigned> visited; //armazena as posicoes visitadas.
        std::vector<std::vector<unsigned> > shortest_path;
        std::queue<Position> fila;
        std::queue<Position> snake_body;
        std::queue<Position> m_aux_body;
    public:
        Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake);
        //Metodos para achar o menor caminho
        bool find_solution(Position & snake, Position & food);
        unsigned lineColumnToindex(unsigned i, unsigned j);
        unsigned find_path(unsigned pst);
        bool check_sides(Position & snake);
        void render_path(Position & food);
        Position update_position(Position & snake, short next);
        void update_body(Position & snake, std::queue<Position> & snake_body, unsigned distance, short side);
        bool isTheBody(unsigned pst, std::queue<Position> & snake_body);
        void render_body(std::queue<Position> & snake_body);

        void reset();
        void update_grid(char * newGrid, unsigned & rows, unsigned & columns);
};

#endif