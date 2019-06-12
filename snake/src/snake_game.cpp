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
    //delete[] level;
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
    //Pega o numero de colunas
    aux_str = line.substr(line.find(' '));
    columns = std::stoul(aux_str);
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
                    spawn.i = i;
                    spawn.j = j;
                }
            }
        }
    }

    m_snake = new Snake{level, rows, columns, snake};
    
}

/**
 * render_food
 * Gera a comida aleatoriamente em algum lugar da grid
 */
void SnakeGame::render_food()
{
    srand(time(NULL));

    do
    {
       food.i = rand() % rows;
       food.j = rand() % columns;

       if(level[food.i*columns+food.j] == ' '){
            if(not m_snake->checks_body(food.i*columns+food.j))
            {
                level[food.i*columns+food.j] =  'f';
                break;
            }
        }
    
    } while(true);
    
    //render_grid();
}

/**
 * render_grid
 * mostra no terminal o grid atual
 */
void SnakeGame::render_grid()
{
    level[0] = '#';
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
                        spawn.i = i;
                        spawn.j = j;
                    }
                }
            }
            return true;
        }

        return false;
    }

    return false;
}

/**
 * process_events
 * processa os eventos do jogo
 */
void SnakeGame::process_events()
{
    std::cout << "Lives: " << state.lives << std::endl;
    std::cout << "Foods: " << state.foods << std::endl;

    render_food();
    render_grid();
    if(m_snake->find_solution(snake, food))
    {
        render_grid();
        m_snake->update_body(food);
        //m_snake->render_path(food, 1);
        m_snake->clear_path(food);
        m_snake->reset(1);
        snake.i = food.i;
        snake.j = food.j;
        state.foods--;
    }else
    {
        m_snake->snake_kamikaze(snake);
        state.lives--;
        render_grid();
        level[food.i*columns+food.j] = ' ';
        snake.i = spawn.i;
        snake.j = spawn.j;
        level[snake.i*columns+snake.j] = '*';
        m_snake->reset(0);
        std::cout << "Solução não encontrada!\n";
    }
}

/**
 * gamer_over
 * verifica se os uma das condicoes de termino de jogo aconteceu
 * @return true, se o snake comeu o numero de todas as comidas do level ou se a quantidade de vidas chegou a zero. false caso contrario.
 */
bool SnakeGame::gamer_over()
{
    if( state.lives == 0 or state.foods == 0)
    {
        return true;
    }

    return false;
}