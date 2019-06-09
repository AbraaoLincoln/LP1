#include "snake_game.h"
#include <iostream>
#include <fstream>
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
}

/**
 * Inicializa o jogo.
 * Carrega cada level
 * @param file_name = nome do arquivo de entrada com as configuracoes
 */
void SnakeGame::initialize_game(std::string file_name)
{
    std::ifstream file_input;
    file_input.open(file_name);
    std::string line;

    file_input >> rows >> columns;

    if((rows < 1 or columns < 1) or (rows > 100 or columns > 100))
    {
        std::cout << "Tamanho do grid invalido\n";
        level = new char[1];
    }else
    {
        getline(file_input,line); // Pula uma linha.
        level = new char[rows*columns];
        for(auto i{0u}; i < rows; i++)
        {
            getline(file_input,line);
            //std::cerr << line << "\n";
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
        /*
        random_position = rand() % (rows*columns);

        if(level[random_position] == ' '){
            level[random_position] =  'f';
            exit = true;
        }
        */

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