#include "../include/life_simulator.h"
#include "../include/life.h"
#include "../include/commun.h"
#include <iostream>
#include <fstream>

/**
 * construct
 * inicializa o dicionario dos comandos.
 * inicia o objeto do tipo life e carrega a primeira geração
 */
Life_simulator::Life_simulator(Commun & args)
{
    glob_config = args;
    m_life = new Life(args, m_log_gen);
}

/**
 * destrucor
 * libera a memoria alocada no construct
 */
Life_simulator::~Life_simulator()
{
    delete m_life;
}

/**
 * game_over
 * verifica se uma das condicoes de termino aconteceu.
 * @return true se uma das condicoes acontceu, false caso contrario
 */
bool Life_simulator::game_over()
{
    if(m_life->extinct())
    {
        std::cout << "A extinção chegou!\n";
        return true;
    }else
    {
        if(m_life->stable(m_log_gen, gen_stable))
        {
            std::cout << "Ficou estavel, a geração atual é a mesma que a " << gen_stable << "º \n";
            return true;
        }
    }
    
    return false;
}