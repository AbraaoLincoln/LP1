#ifndef LIFE_H
#define LIFE_H

#include <unordered_set> 
#include <vector>
#include <map>
#include "../include/common.h"

class Life{

    private:
        Common glob_config;
        unsigned m_i, m_j;
        char symbol_life;
        bool *grid;
        short c_gen; //geracao atual
        short rule[3]; //Posicao 0 = qtd. de vizinhos vivos para que a celula nasca, Posicoes 1 e 2 qtd. de vizinhos vivos para que celular continue viva.
        std::unordered_set<int> cells_alive;
        std::map<std::string, life::Color> colors;
    public:
        bool saveIN[2]; //posicao 0 = true, salva em arquivo. Posicao 1 = true salva em imagem.
        Life(Common & arq_cfg, std::vector<std::unordered_set<int>> & log_gen);
        ~Life();
        void gen_evolution();
        void update_gen();
        bool extinct() const;
        void render_gen();
        bool stable(std::vector<std::unordered_set<int>> & m_log_gen, unsigned & gen_equal);
};

#endif