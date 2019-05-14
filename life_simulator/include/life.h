#ifndef LIFE_H
#define LIFE_H

#include <unordered_set> 
#include <vector>
#include <map>
#include "../include/common.h"

class Life{

    private:
        unsigned m_i, m_j;
        char symbol_life;
        bool *grid;
        std::unordered_set<int> cells_alive;
        Common glob_config;
        short c_gen;
        std::map<std::string, life::Color> colors;
    public:
        bool saveIN[2]; //posicao 0 = true, salve em arquivo. Posicao 1 = true salve em imagem.
        Life(Common & arq_cfg, std::vector<std::unordered_set<int>> & log_gen);
        ~Life();
        void gen_evulution();
        void update_gen();
        bool extinct() const;
        void render_gen();
        bool stable(std::vector<std::unordered_set<int>> & m_log_gen, unsigned & gen_equal);
        friend void encode_png(const char* filename, const unsigned char * image, unsigned width, unsigned height);
};

#endif