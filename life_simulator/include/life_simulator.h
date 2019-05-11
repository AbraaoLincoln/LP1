#ifndef LIFE_SIMULATOR_H
#define LIFE_SIMULATOR_H

#include <map>
#include <vector>
#include <unordered_set>
#include "../include/life.h"
#include "../include/commun.h"

class Life_simulator
{
    private:
        //Life *m_life;
        std::vector<std::unordered_set<int>> m_log_gen;
        Commun glob_config;
        int gen_equal;
    public:
        Life *m_life;
        Life_simulator(Commun & args);
        ~Life_simulator();
        bool game_over();
};

#endif