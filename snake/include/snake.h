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
        unsigned m_rows, m_columns, m_snake_size;
        //Position spawn, pst_snake;
        std::unordered_set<unsigned> visited; //armazena as posicoes visitadas.
        std::vector<std::vector<unsigned> > shortest_path;
        std::queue<Position> fila;
        std::queue<unsigned> snake_body;
        std::vector<unsigned> ghost_snake_body;
        std::vector<unsigned> kamikaze_path;
    public:
        Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake);
        //Metodos para achar o menor caminho
        bool find_solution(Position & snake, Position & food);
        unsigned lineColumnToindex(unsigned i, unsigned j);
        unsigned find_path(unsigned pst);
        bool check_sides(Position & snake);
        void render_path(Position & food, short mode);
        Position update_position(Position & snake, short next);
        bool isTheBody(unsigned pst, std::queue<Position> & snake_body);
        void reset(short mode);
        void update_grid(char * newGrid, Position & snake, unsigned & rows, unsigned & columns);
        void update_body(Position & food);
        void simulate_snake(unsigned end_pst);
        bool isTheBody(unsigned pst);
        //Metods quando nao se acha um caminho.
        void snake_kamikaze(Position & snake);
        void clear_path(Position & food);
};

#endif