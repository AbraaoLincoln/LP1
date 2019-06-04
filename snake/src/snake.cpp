#include "snake.h"
#include "common.h"
#include <queue>
#include <iostream>

Snake::Snake(char * grid)
{
    m_grid = grid;
}

/**
 * find_solution
 * verifica se a snake consegue chegar ate a comida.
 * @param, board do jogo
 * @param, snake = linha do grid onde esta a snake
 * @param, food = coluna do grid onde esta a snake
 * @param, rows numero de linhas do grid
 * @param, columns numero de colunas do grid
 * @return, true se existir um caminho ate a comida, caso contrario false.
 */
bool Snake::find_solution(Position & snake, Position & food, unsigned & rows, unsigned & columns)
{
    mid_rows = rows/2;
    mid_columns = columns/2;
    Position current_position{snake.i, snake.j}, position_aux;
    std::queue<Position> path;
    path.push(current_position);

    position_aux = path.back();
    //std::cerr << position_aux.i << " " << position_aux.j;
    while(m_grid[position_aux.i*columns+position_aux.j] != 'f')
    {
        //std::cerr << position_aux.i << " " << position_aux.j;
        move_row(snake, food, columns, path);
        //std::cerr << "Colunas agr\n";
        move_column(snake, food, columns, path);
        //std::cerr << "X agr\n";
        position_aux = path.back();
        //std::cerr << "main path\n";
    }
    //std::cerr << "aqui\n";
    while(not path.empty())
    {
        position_aux = path.front();
        m_grid[position_aux.i*columns+position_aux.j] = 'x';
        path.pop();
    }
    return false;
}

/**
 * move_row
 * Move a snake na vertical
 * @param snake = posicao atual da snake
 * @param food = posicao da comida
 * @param columns = numero de colunas do grid
 * @param path = caminho do ponto inicial ate a comida
 */
void Snake::move_row(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path)
{
    if(food.i > snake.i)//Move para baixo no grid
    {
        while(m_grid[(snake.i+1)*columns+snake.j] == ' ' and (snake.i+1) <= food.i){
            snake.i++;
            path.push(snake);
        }

        if(m_grid[(snake.i+1)*columns+snake.j] == 'f')
        {
            snake.i++;
            path.push(snake);
        }
    }else
    {   //Move para cima no grid
        while(m_grid[(snake.i-1)*columns+snake.j] == ' ' and (snake.i-1) >= food.i){
            snake.i--;
            path.push(snake);
        }

        if(m_grid[(snake.i-1)*columns+snake.j] == 'f')
        {
            snake.i--;
            path.push(snake);
        }
    }
    
}

/**
 * move_columns
 * Move a snake na horizontal
 * @param snake = posicao atual da snake
 * @param food = posicao da comida
 * @param columns = numero de colunas do grid
 * @param path = caminho do ponto inicial ate a comida
 */
void Snake::move_column(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path)
{
    bool exit{false};
    if(food.j > snake.j)//Move para a direita no grid
    {
        do
        {   
            while(m_grid[snake.i*columns+(snake.j+1)] == ' ' and (snake.j+1) <= food.j){
                snake.j++;
                path.push(snake);
            }
            //std::cerr << "Aqui\n";
            if(m_grid[snake.i*columns+(snake.j+1)] == 'f')
            {
                snake.j++;
                path.push(snake);
                break;
            }else
            {
                //exit = around(snake, food, columns, path);
                if(around(snake, food, columns, path))
                {
                    move_column(snake, food, columns, path);
                }else
                {
                    exit = false;
                }
                
            }

        }while(exit);

        
    }else if(food.j < snake.j)
    {   //Move para a esquerda no grid
        //std::cerr << "aqui\n";
        do
        {   
            while(m_grid[snake.i*columns+(snake.j-1)] == ' ' and (snake.j-1) >= food.j){
                snake.j--;
                path.push(snake);
            }
            //std::cerr << "Aqui\n";
            if(m_grid[snake.i*columns+(snake.j-1)] == 'f')
            {
                snake.j--;
                path.push(snake);
                break;
            }else
            {
                //exit = around(snake, food, columns, path);
                if(around(snake, food, columns, path))
                {
                    move_column(snake, food, columns, path);
                }else
                {
                    exit = false;
                }
                        
            }
                    
        }while(exit);
                
    }
    
}

/**
 * around
 * Faz a snake da a volta no muro.
 * @param snake = posicao atual da snake
 * @param food = posicao da comida
 * @param columns = numero de colunas do grid
 * @param path = caminho do ponto inicial ate a comida
 * @retrun true se a snake consegue da a volta, false caso contrario.
 */
bool Snake::around(Position & snake, Position & food, unsigned & columns, std::queue<Position> & path)
{
    std::queue<Position> path_around;

    if((snake.j+1) != ' ')//Direita
    {
        while(m_grid[snake.i*columns+(snake.j+1)] != ' ' and m_grid[(snake.i-1)*columns+snake.j] == ' ')
        {
            snake.i--;
            path_around.push(snake);
        }

        if((snake.i-1) == 0 and m_grid[snake.i*columns+(snake.j+1)] != ' ')
        {
            return false;
        }
    }

    if((snake.j-1) != ' ') //Esquerda
    {
        while(m_grid[snake.i*columns+(snake.j-1)] != ' ' and m_grid[(snake.i-1)*columns+snake.j] == ' ')
        {
            snake.i--;
            path_around.push(snake);
        }

        if((snake.i-1) == 0 and m_grid[snake.i*columns+(snake.j-1)] != ' ')
        {
            return false;
        }

    }

    while(not path_around.empty())
    {
        path.push(path_around.front());
        path_around.pop();
    }

    return true;
}