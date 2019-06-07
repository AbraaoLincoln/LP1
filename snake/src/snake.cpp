#include "snake.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

Snake::Snake(char * grid)
{
    m_grid = grid;
}

/**
 * find_solution
 * verifica se a snake consegue chegar ate a comida.
 * @param, snake = linha do grid onde esta a snake
 * @param, food = coluna do grid onde esta a snake
 * @return, true se existir um caminho ate a comida, caso contrario false.
 */
bool Snake::find_solution(Position & snake, Position & food)
{
    if(m_grid[lineColumnToindex(snake.i, snake.j)] == 'f') //Encontrou a comida
    {
        path.push(lineColumnToindex(snake.i, snake.j));
        return true;
    }

    //Verifica os vizinhos
    //Move primeiro para baixo ou para cima.
    if((food.i - (snake.i+1)) < (food.i - (snake.i-1)))
    {
        Position aux{snake.i+1, snake.j};

        if(m_grid[lineColumnToindex(snake.i+1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i+1, snake.j)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
        aux.i -= 2;
        if(m_grid[lineColumnToindex(snake.i-1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i-1, snake.j)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
    }else
    {
        Position aux{snake.i-1, snake.j};
        if(m_grid[lineColumnToindex(snake.i-1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i-1, snake.j)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
        aux.i += 2;
        if(m_grid[lineColumnToindex(snake.i+1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i+1, snake.j)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
    }

    //Move primeiro para direita ou esquerda
    if((food.j - (snake.j+1)) < (food.j - (snake.j-1)))
    {
        Position aux{snake.i, snake.j+1};

        if(m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j+1)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
        aux.j -= 2;
        if(m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j-1)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
    }else
    {
        Position aux{snake.i, snake.j-1};
        if(m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j-1)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
        aux.j += 2;
        if(m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j+1)) == 0)
        {
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
            }
        }
    }

    return false;   
}

/**
 * lineColumnToindex
 * Transforma um indice de matriz i e j em um unico indice para um vetor
 * Usado quando os dados estao em uma matriz mas na memoria estao em um vetor
 * @param row = linha da matriz
 * @param column = coluna da matriz
 * @return index =  indice do elemento no vetor
 */
unsigned Snake::lineColumnToindex(unsigned row, unsigned column)
{
    return row*column+column;
}
