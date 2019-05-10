#ifndef LIFE_H
#define LIFE_H

#include <unordered_set> 

class Life{

    private:
        unsigned m_i, m_j;
        bool *grid;
        static short c_gen;
        std::unordered_set<int> cells_alive;
    public:
    Life(unsigned i, unsigned j);
    ~Life();
    void gen_evulution();
    void render_gen();
    void show_grid();
};

#endif