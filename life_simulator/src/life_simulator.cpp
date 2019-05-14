#include "../include/life_simulator.h"
#include "../include/life.h"
#include "../include/common.h"
#include <iostream>
#include <fstream>

/**
 * construct
 * inicializa o dicionario dos comandos globais.
 * set o valor de maxgen para 0, se o valor de maxgen for diferente de 0 e porque o cliente definiu o numero de maximo de geracoes.
 * inicia o objeto do tipo life e carrega a primeira geração.
 */
Life_simulator::Life_simulator(Common & args)
{
    glob_config = args;
    m_life = new Life(args, m_log_gen);
    
    if(glob_config.cfg["--maxgen"] != "0")
    {
        maxgen = stringTOint(glob_config.cfg["--maxgen"]) + 1;
    }else
    {
        maxgen = 0;
    }
    
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
 * se esta extinto
 * se esta estavel
 * se o numero maximo de geracoes foi atingida(quando informado)
 * @return true se uma das condicoes acontceu, false caso contrario
 */
bool Life_simulator::game_over()
{
    if(m_life->extinct())
    {
        show_msg(0);
        return true;
    }else if(m_life->stable(m_log_gen, gen_equal))
    {
        show_msg(1);
        return true;
    }else if(maxgen != 0)
    {
        maxgen--;
        if(maxgen == 0)
        {
            show_msg(2);
            return true;
        }
    }
    
    return false;
}

/**
 * show_msg
 * mostra a mensagem corresponde a qual das condicoes de parada foi satisfeita.
 * @param index, indice de qual mensagem deve ser exibida
 * 0 = extinto
 * 1 = estavel
 * 2 = o numero maximo de geracoes
 */
void Life_simulator::show_msg(short index)
{
    std::string mgs[]{"A extinção chegou!\n", "Ficou estavel, a geração atual é a mesma que a ", "Geracao maxima atingida!\n"};

    if(m_life->saveIN[0])
    {
        std::ofstream output;
        output.open(glob_config.cfg["--outfile"], std::ofstream::app);
        output << mgs[index];
        if(index == 1)
        {
            output << gen_equal << "º \n";
        }
        output.close();
    }else if(not m_life->saveIN[1])
    {
        std::cout << mgs[index];
        if(index == 1)
        {
            std::cout << gen_equal << "º \n";
        }
    }
}