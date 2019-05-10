#ifndef LIFE_H
#define LIFE_H

#include <unordered_set> 
#include <vector>
#include "../include/commun.h"

class Life{

    private:
        unsigned m_i, m_j;
        char symbol_life;
        bool *grid;
        std::unordered_set<int> cells_alive;
    public:
    Life(Commun & arq_cfg, std::vector<std::unordered_set<int>> & m_log_gen);
    ~Life();
    void gen_evulution();
    void update_gen();
    bool extinct() const;
    void show_grid();
    bool stable(std::vector<std::unordered_set<int>> & m_log_gen, int & gen_stable);
};

#endif