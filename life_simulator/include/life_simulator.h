#ifndef LIFE_SIMULATOR_H
#define LIFE_SIMULATOR_H

#include <map>
#include <vector>
#include <unordered_set>
#include "../include/life.h"
#include "../include/common.h"

class Life_simulator
{
    private:
        Life *m_life;
        std::vector<std::unordered_set<int>> m_log_gen;
        Common glob_config;
        unsigned gen_equal, maxgen;
    public:
        Life_simulator(Common & args);
        ~Life_simulator();
        bool game_over();
        void show_msg(short index);
        void render_gen();
        void gen_evolution();
        void update_gen();
};

#endif