#include "snake.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

Snake::Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake)
{
    m_grid = grid;
    m_rows = rows;
    m_columns = columns;
    visited.insert(lineColumnToindex(snake.i, snake.j));
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
        std::cerr << "food\n";
        return true;
    }

    if(m_grid[lineColumnToindex(snake.i, snake.j)] == '#') //Encontrou a comida
    {
        std::cerr << "wall\n";
        return false;
    }
    std::cerr << snake.i << " , " << snake.j<< " index: " << lineColumnToindex(snake.i, snake.j) << std::endl;

    //Verifica os vizinhos
    //Move primeiro para baixo ou para cima.
    
    if((food.i - (snake.i+1)) < (food.i - (snake.i-1)))
    {
        std::cerr << "para baixo\n";
        Position aux{snake.i+1, snake.j};

        if(m_grid[lineColumnToindex(snake.i+1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i+1, snake.j)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
        aux.i -= 2;
        if(m_grid[lineColumnToindex(snake.i-1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i-1, snake.j)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
    }else
    {
        std::cerr << "para cima\n";
        Position aux{snake.i-1, snake.j};
        if(m_grid[lineColumnToindex(snake.i-1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i-1, snake.j)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
        aux.i += 2;
        if(m_grid[lineColumnToindex(snake.i+1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i+1, snake.j)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
    }

    //Move primeiro para direita ou esquerda
    if((food.j - (snake.j+1)) < (food.j - (snake.j-1)))
    {
        std::cerr << "para direita\n";
        Position aux{snake.i, snake.j+1};

        if(m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j+1)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
        aux.j -= 2;
        if(m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j-1)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
    }else
    {
        std::cerr << "para a esquerda\n";
        Position aux{snake.i, snake.j-1};
        if(m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j-1)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
        aux.j += 2;
        if(m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j+1)) == 0)
        {
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }
        }
    }
    
   /*
   Position aux{snake.i+1, snake.j};

        if(m_grid[lineColumnToindex(snake.i+1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i+1, snake.j)) == 0)
        {
            std::cerr << "para baixo\n";
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }else
            {
                return false;
            }
            
        }
        aux.i -= 2;
        std:: cerr << "next line:" << aux.i << std::endl;
        std::cerr << m_grid[lineColumnToindex(aux.i, snake.j)] << " , " << visited.count(lineColumnToindex(snake.i-1, snake.j)) << std::endl;
        if(m_grid[lineColumnToindex(snake.i-1, snake.j)] != '#' and visited.count(lineColumnToindex(snake.i-1, snake.j)) == 0)
        {
            std::cerr << "para cima\n";
            visited.insert(lineColumnToindex(aux.i, aux.j));
            if(find_solution(aux, food))
            {
                path.push(lineColumnToindex(aux.i, aux.j));
                return true;
            }else
            {
                return false;
            }
            
        }
        
        Position aux1{snake.i, snake.j+1};

        if(m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j+1)) == 0)
        {
            std::cerr << "para a direita\n";
            visited.insert(lineColumnToindex(aux1.i, aux1.j));
            if(find_solution(aux1, food))
            {
                path.push(lineColumnToindex(aux1.i, aux1.j));
                return true;
            }
        }
        aux1.j -= 2;
        if(m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#' and visited.count(lineColumnToindex(snake.i, snake.j-1)) == 0)
        {
            std::cerr << "Para a esquerda\n";
            visited.insert(lineColumnToindex(aux1.i, aux1.j));
            if(find_solution(aux1, food))
            {
                path.push(lineColumnToindex(aux1.i, aux1.j));
                return true;
            }
        }
    */
    std::cerr << "Last return\n";
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
unsigned Snake::lineColumnToindex(unsigned i, unsigned j)
{
    return i*m_columns+j;
}

void Snake::render_path()
{
    while(not path.empty())
    {
        m_grid[path.top()] =  'X';
        path.pop();
    }
}
