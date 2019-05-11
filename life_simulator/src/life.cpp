#include "../include/life.h"
#include "../include/commun.h"
#include "../include/canvas.h"
#include "../include/lodepng.h"
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace life;

/** \class Life
 * Construtor
 * O construtor aloca dinamicamente a memoria, para um grib de tamanho i por j passado pelo o usuario.
 * @param arq_cfg objeto que possui as configurações globais, nele é onde se encontra o nome do arquivo de configuração do grid.
 * @param log_gen, log de gerecoes
 */
Life::Life(Commun & arq_cfg, std::vector<std::unordered_set<int>> & log_gen)
{
    glob_config = arq_cfg;
    std::ifstream l_glob_config;
    std::string line;
    l_glob_config.open(arq_cfg.cfg["arquivo_configuracao"]);
    l_glob_config >> m_i >> m_j >> symbol_life;
    m_i += 2;
    m_j += 2;
    grid = new bool[m_i*m_j]; //aloca a memoria sequencialmente na memoria
    getline(l_glob_config, line); //usado para ignorar um linha
    for(auto i{1u}; i < (m_i - 1); i++) //inicializa o grid com a primeira geração
    {
        getline(l_glob_config, line);
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
    l_glob_config.close();
    log_gen.push_back(cells_alive);

    if(glob_config.cfg.count("--outfile") == 1)
    {
        write[0] = true;
    }else if(glob_config.cfg.count("--imgdir") == 1)
    {
        write[1] = true;
        colors["BLACK"]        = Color{0,0,0};
        colors["WHITE"]        = Color{255,255,255};
        colors["DARK_GREEN"]   = Color{0,100,0};
        colors["GREEN"]        = Color{0,250,0};
        colors["RED"]          = Color{255,0,0};
        colors["CRIMSON"]      = Color{220,20,60};
        colors["LIGHT_BLUE"]   = Color{135,206,250};
        colors["LIGHT_GREY"]   = Color{210,210,210};
        colors["DEEP_SKY_BLUE"] = Color{0,191,255};
        colors["DODGER_BLUE"]  = Color{30,144,255};
        colors["STEEL_BLUE"]   = Color{70,130,180};
        colors["YELLOW"]       = Color{255,255,0};
        colors["LIGHT_YELLOW"] = Color{255,255,153};
    }
    c_gen = 0;
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
bool Life::stable(std::vector<std::unordered_set<int>> & log_gen, int & gen_stable)
{
    unsigned count{0};
    for(auto i{0u}; i < log_gen.size(); i++)
    {
        for(auto cells_older_gen : log_gen[i])
        {
            if(cells_alive.count(cells_older_gen) == 1)
            {
                count++;
            }
        }

        if(count == cells_alive.size() and log_gen[i].size() == cells_alive.size())
        {
            gen_stable = i+1;
            return true;
        }else
        {
            count = 0;
        }
        
    }
    log_gen.push_back(cells_alive);
    return false;
}

/**
 * mostra no terminal o grid atual
 * usando para fazer debug
 */
void Life::show_grid()
{
    if(write[0])
    {
        std::ofstream output;
        output.open(glob_config.cfg["--outfile"], std::ofstream::app);
        output << "Geração\n";
        for(auto i{1u}; i < (m_i - 1); i++)
        {
            output << "[ ";
            for(auto j{1u};j < (m_j - 1); j++)
            {
                if( grid[i*(m_j) + j])
                {
                    output << symbol_life;
                }else
                {
                    output << " ";
                }     
            }
            output << " ]\n";
        }
        output.close();
    }else if(write[1])
    {
        c_gen++;
        std::ostringstream file;
        file << "gen" << c_gen << ".png";
        short block_size;
        std::istringstream conversion(glob_config.cfg["--blocksize"]);
        conversion >> block_size;
        Canvas imagem{(m_i-2), (m_j-2), block_size};
        imagem.clear(colors[glob_config.cfg["--bkgcolor"]]);
        
        for(auto j{1u}; j < (m_j-1);j++)
        {
            for(auto i{1u}; i < (m_i-1); i++)
            {
                if( grid[i*m_j + j])
                {
                    imagem.pixel(Point2(j-1, i-1), colors[glob_config.cfg["--alivecolor"]]);
                }
                
            }
        }

        encode_png(file.str().c_str(), imagem.pixels(), imagem.width(), imagem.height() );
    }else
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
    }
}