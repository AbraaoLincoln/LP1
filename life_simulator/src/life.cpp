#include "../include/life.h"
#include <unordered_set>
#include <iostream>

/** \class Life
 * Construtor
 * O construtor aloca dinamicamente a memoria, para um grib de tamanho i por j passado pelo o usuario.
 * @param i quantidade de linhas do grib
 * @param quantidade de colunas do grib.
 */
Life::Life(unsigned i, unsigned j) : m_i{i+2}, m_j{j+2}
{
    grid = new bool[m_i*m_j];

    //grid[1*(m_j) + 2] = true;
    //grid[3*(m_j) + 2] = true;
    //grid[2*(m_j) + 2] = true;

    //grid[1*(m_j) + 2] = true;
    //grid[1*(m_j) + 3] = true;
    //grid[2*(m_j) + 2] = true;
  
}

/** 
 * Destruct
 * Libera a memoria alocada pelo construct.
 */
Life::~Life()
{
    delete[] grid;
}

/**
 * gen_evulition
 * Aplica as regras do jogo da vida de Conway e gera um nova geração.
 * @return nao sei ainda.
 */
void Life::gen_evulution()
{
    int count_alive{0};
    cells_alive.clear();

    for(auto i{1u}; i < (m_i - 1); i++)
    {
        for(auto j{1u};j < (m_j - 1); j++)
        {
            //vizinho 1
            if(grid[(i-1)*(m_j) + (j-1)])
            {
                count_alive++;
            }
            //vizinho 2
            if(grid[(i-1)*(m_j) + j])
            {
                count_alive++;
            }
            //vizinho 3
            if(grid[(i-1)*(m_j) + (j+1)])
            {
                count_alive++;
            }
            //vizinho 4
            if(grid[i*(m_j) + (j-1)])
            {
                count_alive++;
            }
            //vizinho 5
            if(grid[i*(m_j) + (j+1)])
            {
                count_alive++;
            }
            //vizinho 6
            if(grid[(i+1)*(m_j) + (j-1)])
            {
                count_alive++;
            }
            //vizinho 7
            if(grid[(i+1)*(m_j) + j])
            {
                count_alive++;
            }
            //vizinho 8
            if(grid[(i+1)*(m_j) + (j+1)])
            {
                count_alive++;
            }

            //Etapa de verificação se a celula morre ou vive
            //aqui é onde as regras são aplicadas

            //Regra numero 3
            if(grid[i*(m_j) + j] == true )
            {
                if(count_alive == 3 or count_alive == 2)
                {
                    cells_alive.insert(i*(m_j) + j);
                }
            }
            //Regra numero 4
            if(grid[i*(m_j) + j] == false and count_alive == 3)
            {
                cells_alive.insert(i*(m_j) + j);
            }
           
            //std::cout << grid[i*(m_j) + j] << " , " << count_alive << "\n";
            count_alive = 0;

        }
    }

}

/**
 * update_gen
 * Atualiza o grid com a nova geração
 * @return nada
 */
void Life::update_gen()
{
    for(auto i{1u}; i < (m_i - 1); i++)
    {
        for(auto j{1u};j < (m_j - 1); j++)
        {
            if(cells_alive.count(i*(m_j) + j) == 1)
            {
                grid[i*(m_j) + j] = true;
            }else
            {
                grid[i*(m_j) + j] = false;
            }
            
        }
    }
}
/**
 * extinct
 * verifica se a geração atual esta extinta
 * @return true se estiver extinta, false caso contrario.
 */
bool Life::extinct() const
{
    return cells_alive.empty();
}

/**
 * mostra no terminal o grid atual
 * usando para fazer debug
 */
void Life::show_grid()
{
    std::cout << "inside:\n";
    for(auto i{1u}; i < (m_i - 1); i++)
    {
        for(auto j{1u};j < (m_j - 1); j++)
        {
            std::cout << grid[i*(m_j) + j] << " ";
            
        }
        std::cout << "\n";
    }

    std::cout << "complete:\n";
    for(auto i{0u}; i < m_i; i++)
    {
        for(auto j{0u};j < m_j; j++)
        {
            std::cout << grid[i*m_j + j] << " ";
            
        }
        std::cout << "\n";
    }
}