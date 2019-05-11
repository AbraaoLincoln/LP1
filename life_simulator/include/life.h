#ifndef LIFE_H
#define LIFE_H

#include <unordered_set> 
#include <vector>
#include <map>
#include "../include/commun.h"

class Life{

    private:
        unsigned m_i, m_j;
        char symbol_life;
        bool *grid;
        std::unordered_set<int> cells_alive;
        Commun glob_config;
        short c_gen;
        std::map<std::string, life::Color> colors;
        //bool write[2];
    public:
    bool write[2];
    Life(Commun & arq_cfg, std::vector<std::unordered_set<int>> & m_log_gen);
    ~Life();
    void gen_evulution();
    void update_gen();
    bool extinct() const;
    void show_grid();
    bool stable(std::vector<std::unordered_set<int>> & m_log_gen, int & gen_stable);
    friend void encode_png(const char* filename, const unsigned char * image, unsigned width, unsigned height);
};

#endif