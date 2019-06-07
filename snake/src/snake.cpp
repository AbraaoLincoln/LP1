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

    if(m_grid[lineColumnToindex(snake.i, snake.j)] == '#') //Encontrou a um muro
    {
        std::cerr << "wall\n";
        return false;
    }
    //std::cerr << snake.i << " , " << snake.j<< "---" << food.i << " , " << food.j << std::endl;

    //Verifica os vizinhos
    //Move primeiro para baixo ou para cima.
    /*
    if(abs(food.i - (snake.i+1)) < abs(food.i - (snake.i-1)))
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
    if(abs(food.j - (snake.j+1)) < abs(food.j - (snake.j-1)))
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
    */

   /* */
   //teste menor path
   if((snake.i == food.i) and (wall_side(snake, food)))
   {
       //Move na vertical
       //Move primeiro para direita ou esquerda
        if(abs(food.j - (snake.j+1)) < abs(food.j - (snake.j-1)))
        {
            //std::cerr << "para direita\n";
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
            //std::cerr << "para a esquerda\n";
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
   }else
   {
        //Move primeiro para baixo ou para cima.
        if(abs(food.i - (snake.i+1)) < abs(food.i - (snake.i-1)))
        {
            //std::cerr << "para baixo\n";
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
            //std::cerr << "para cima\n";
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
        if(abs(food.j - (snake.j+1)) < abs(food.j - (snake.j-1)))
        {
            //std::cerr << "para direita\n";
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
            //std::cerr << "para a esquerda\n";
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
   }
   
    return false;   
}

/**
 * lineColumnToindex
 * Transforma um indice de matriz i e j em um unico indice para um vetor
 * Usado quando os dados estao em uma matriz mas na memoria estao em um vetor
 * @param i = linha da matriz
 * @param j = coluna da matriz
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

/**
 * abs
 * calcula o valor absluto de um numero inteiro
 * @param value numero inteiro
 * @return valor absoluto do numero inteiro passado
 */
unsigned Snake::abs(int value)
{
    if (value >= 0)
    {
        return value;
    }else
    {
        return value * -1;
    }    
}

bool Snake::wall_side(Position & snake, Position & food)
{
    if(snake.j < food.j)
    {
        return m_grid[lineColumnToindex(snake.i, snake.j+1)] != '#';
    }else
    {
        return m_grid[lineColumnToindex(snake.i, snake.j-1)] != '#';
    }
    
}