#include "snake_game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

/**
 * construtor da classe snake_game
 */
SnakeGame::SnakeGame()
{
    
}

/**
 * destructor da classe snake_game
 * Libera a memoria alocada no initialize_game
 */
SnakeGame::~SnakeGame()
{
    delete[] level;
    file_input.close();
}

/**
 * get_RowsColumns
 * retira de uma string dois inteiro
 * @param line, string que contem os interios separados por espacoes
 */
void SnakeGame::get_RowsColumns(std::string & line)
{
    std::string aux_str;

    //Pega o numero de linhas
    aux_str = line.substr(0, line.find(' '));
    rows = std::stoul(aux_str);
    //std::cerr << rows << std::endl;
    //Pega o numero de colunas
    aux_str = line.substr(line.find(' '));
    columns = std::stoul(aux_str);
    //std::cerr << columns << std::endl;
}

/**
 * Inicializa o jogo.
 * Carrega o primeiro level do jogo
 * @param file_name = nome do arquivo de entrada com as configuracoes
 */
void SnakeGame::initialize_game(std::string file_name)
{
    file_input.open(file_name);
    std::string line;

    //file_input >> rows >> columns;
    getline(file_input, line);
    get_RowsColumns(line);

    if((rows < 1 or columns < 1) or (rows > 100 or columns > 100))
    {
        std::cout << "Tamanho do grid invalido\n";
        level = new char[1];
    }else
    {
        //getline(file_input,line); // Pula uma linha.
        level = new char[rows*columns];
        for(auto i{0u}; i < rows; i++)
        {
            getline(file_input,line);
            for(auto j{0u}; j < columns; j++)
            {
                level[i*columns+j] = line[j];
                if(line[j] == '*')
                {
                    snake.i = i;
                    snake.j = j;
                }
            }
        }
        //getline(file_input, line);
    }
    
}

/**
 * render_food
 * Gera a comida aleatoriamente em algum lugar da grid
 */
void SnakeGame::render_food()
{
    srand(time(NULL));
    //unsigned random_position{0};
    bool exit{false};

    do
    {
       food.i = rand() % rows;
       food.j = rand() % columns;

       if(level[food.i*columns+food.j] == ' '){
            level[food.i*columns+food.j] =  'f';
            exit = true;
        }
    } while(not exit);
    
    render_grid();
}

/**
 * render_grid
 * mostra no terminal o grid atual
 */
void SnakeGame::render_grid()
{
    for(auto i{0u}; i < rows; i++)
    {
        for(auto j{0u}; j < columns; j++)
        {
            std::cout << level[i*columns+j];
        }
        std::cout << "\n";
    }
}

/**
 * update_level
 * carrega o proximo level na memoria
 * @return true, se o proximo level foi carregado, false caso contrario
 */

bool SnakeGame::update_level()
{
    delete[] level;
    std::string line;

    if(not file_input.eof())
    {
        getline(file_input, line);
        //std::cerr << (line == "" ? true:false) << std::endl;
        
        if(line != "")
        {
            get_RowsColumns(line);

            level = new char[rows*columns];
            for(auto i{0u}; i < rows; i++)
            {
                getline(file_input,line);
                for(auto j{0u}; j < columns; j++)
                {
                    level[i*columns+j] = line[j];
                    if(line[j] == '*')
                    {
                        snake.i = i;
                        snake.j = j;
                    }
                }
            }
            return true;
        }

        return false;
    }

    return false;
}