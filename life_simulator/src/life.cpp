#include "../include/life.h"
#include "../include/commun.h"
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/** \class Life
 * Construtor
 * O construtor aloca dinamicamente a memoria, para um grib de tamanho i por j passado pelo o usuario.
 * @param arq_cfg objeto que possui as configurações globais, nele é onde se encontra o nome do arquivo de configuração do grid.
 */
Life::Life(Commun & arq_cfg, std::vector<std::unordered_set<int>> & m_log_gen)
{
    std::ifstream glob_config;
    std::string line;
    glob_config.open(arq_cfg.cfg["arquivo_configuracao"]);
    glob_config >> m_i >> m_j >> symbol_life;
    m_i += 2;
    m_j += 2;
    grid = new bool[m_i*m_j]; //aloca a memoria sequencialmente na memoria
    getline(glob_config, line); //usado para ignorar um linha
    for(auto i{1u}; i < (m_i - 1); i++) //inicializa o grid com a primeira geração
    {
        getline(glob_config, line);
        //std::cout << line << "\n";
        for(auto j{1u}; j < (m_j - 1); j++)
        {
            if(j <= line.size())
            {
                if(line[j-1] == symbol_life)
                {
                    grid[i*m_j + j] = true;
                    cells_alive.insert(i*m_j + j);
                }else
                {
                    grid[i*m_j + j] = false;
                }         
            }else
            {
                grid[i*m_j + j] = false;
            }
            
        }
    }
    glob_config.close();
    m_log_gen.push_back(cells_alive);
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
 * stable
 * Esse metodo verifica se a configuração atual ja se repetiu, se sim encerra o programa senao atualiza o log com a geracao atual.
 * @param vector de unordered set que contem as geracoes passadas
 * @return true se a geracao atual se repetiu, false caso contrario
 */
bool Life::stable(std::vector<std::unordered_set<int>> & m_log_gen, int & gen_stable)
{
    unsigned count{0};
    for(auto i{0u}; i < m_log_gen.size(); i++)
    {
        for(auto cells_older_gen : m_log_gen[i])
        {
            if(cells_alive.count(cells_older_gen) == 1)
            {
                count++;
            }
        }

        if(count == cells_alive.size() and m_log_gen[i].size() == cells_alive.size())
        {
            gen_stable = i+1;
            return true;
        }else
        {
            count = 0;
        }
        
    }
    m_log_gen.push_back(cells_alive);
    return false;
}

/**
 * mostra no terminal o grid atual
 * usando para fazer debug
 */
void Life::show_grid()
{
    std::cout << "Geração\n";
    for(auto i{1u}; i < (m_i - 1); i++)
    {
        std::cout << "[ ";
        for(auto j{1u};j < (m_j - 1); j++)
        {
            if( grid[i*(m_j) + j])
            {
                std::cout << symbol_life;
            }else
            {
                std::cout << " ";
            }     
        }
        std::cout << " ]\n";
    }
    /*
    std::cout << "inside:\n";
    for(auto i{1u}; i < (m_i - 1); i++)
    {
        for(auto j{1u};j < (m_j - 1); j++)
        {
            std::cout << grid[i*(m_j) + j] << " ";
            
        }
        std::cout << "\n";
    }
    */
    /*
    std::cout << "complete:\n";
    for(auto i{0u}; i < m_i; i++)
    {
        for(auto j{0u};j < m_j; j++)
        {
            std::cout << grid[i*m_j + j] << " ";
            
        }
        std::cout << "\n";
    }
    */
}