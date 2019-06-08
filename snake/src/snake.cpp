#include "snake.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

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

bool Snake::find_solution2(Position & snake, Position & food)
{
    Position position_aux{snake.i, snake.j}, position_aux2;
    unsigned count{0};
    //Inicializa o vector de vector
    for(auto i{0u}; i < 4;i++)
    {
        std::vector<unsigned> aux(10,0);
        aux.push_back(lineColumnToindex(snake.i, snake.j)); //Inicializa cada caminho com a posicao inicial da snake.
        shortest_path.push_back(aux);
    }
    //Teste ponto de saida
    /*
    for(auto i{0u}; i < 4;i++)
    {
        std::cout << shortest_path[i][0] << std::endl;
    }
    */

   //Verifica os vizinhos em sentido horario.
   //Coloca os vizinhos da posicao atual em visitados
   //Cima
   if(m_grid[lineColumnToindex(snake.i-1, snake.j)] == ' ')
   {
       visited.insert(lineColumnToindex(snake.i-1, snake.j));
       //fila.push(lineColumnToindex(snake.i-1, snake.j));
       position_aux.i -= 1;
       fila.push(position_aux);
       shortest_path[0].push_back(lineColumnToindex(snake.i-1, snake.j));
   }
   //Direita
   if(m_grid[lineColumnToindex(snake.i, snake.j+1)] == ' ')
   {
       visited.insert(lineColumnToindex(snake.i, snake.j+1));
       //fila.push(lineColumnToindex(snake.i, snake.j+1));
       position_aux = snake;
       position_aux.j += 1;
       fila.push(position_aux);
       shortest_path[1].push_back(lineColumnToindex(snake.i, snake.j+1));
   }
   //Baixo
   if(m_grid[lineColumnToindex(snake.i+1, snake.j)] == ' ')
   {
       visited.insert(lineColumnToindex(snake.i+1, snake.j));
       //fila.push(lineColumnToindex(snake.i+1, snake.j));
       position_aux = snake;
       position_aux.i += 1;
       fila.push(position_aux);
       shortest_path[2].push_back(lineColumnToindex(snake.i+1, snake.j));
   }
   //Esquerda
   if(m_grid[lineColumnToindex(snake.i, snake.j-1)] == ' ')
   {
       visited.insert(lineColumnToindex(snake.i, snake.j-1));
       //fila.push(lineColumnToindex(snake.i, snake.j-1));
       position_aux = snake;
       position_aux.j -= 1;
       fila.push(position_aux);
       shortest_path[3].push_back(lineColumnToindex(snake.i, snake.j-1));
   }
   /*
   while(not fila.empty())
   {
       position_aux = fila.front();
       fila.pop();
   }
    std::cout << position_aux.i << " " << position_aux.j << std::endl;
   */

  while(not fila.empty())
  {
      count = 0;
      position_aux = fila.front();
      fila.pop();
      unsigned curent_path = find_path(lineColumnToindex(position_aux.i, position_aux.j));

      if((m_grid[lineColumnToindex(position_aux.i-1, position_aux.j)] != '#') and (visited.count(lineColumnToindex(position_aux.i-1, position_aux.j)) == 0))
      {
          visited.insert(lineColumnToindex(position_aux.i-1, position_aux.j));
          position_aux2 = position_aux;
          position_aux2.i -= 1;
          fila.push(position_aux2);
          shortest_path[curent_path].push_back(lineColumnToindex(position_aux.i-1, position_aux.j));
          count++;
      }

      if((m_grid[lineColumnToindex(position_aux.i, position_aux.j+1)] != '#') and (visited.count(lineColumnToindex(position_aux.i, position_aux.j+1)) == 0))
      {
          visited.insert(lineColumnToindex(position_aux.i, position_aux.j+1));
          position_aux2 = position_aux;
          position_aux2.j += 1;
          fila.push(position_aux2);
          if(count > 0)
          {
              std::vector<unsigned> aux_vector{shortest_path[curent_path]};
              aux_vector[aux_vector.size()-1] = lineColumnToindex(position_aux.i, position_aux.j+1);
              shortest_path.push_back(aux_vector);
          }else
          {
              shortest_path[curent_path].push_back(lineColumnToindex(position_aux.i, position_aux.j+1));
          }
          
          count++;
      }

      if((m_grid[lineColumnToindex(position_aux.i-1, position_aux.j)] != '#') and (visited.count(lineColumnToindex(position_aux.i-1, position_aux.j)) == 0))
      {
          visited.insert(lineColumnToindex(position_aux.i-1, position_aux.j));
          position_aux2 = position_aux;
          position_aux2.i -= 1;
          fila.push(position_aux2);
          if(count > 0)
          {
              std::vector<unsigned> aux_vector{shortest_path[curent_path]};
              aux_vector[aux_vector.size()-1] = lineColumnToindex(position_aux.i-1, position_aux.j);
              shortest_path.push_back(aux_vector);
          }else
          {
              shortest_path[curent_path].push_back(lineColumnToindex(position_aux.i-1, position_aux.j));
          }
          
          count++;
      }

      if((m_grid[lineColumnToindex(position_aux.i, position_aux.j-1)] != '#') and (visited.count(lineColumnToindex(position_aux.i, position_aux.j-1)) == 0))
      {
          visited.insert(lineColumnToindex(position_aux.i, position_aux.j-1));
          position_aux2 = position_aux;
          position_aux2.j -= 1;
          fila.push(position_aux2);
          if(count > 0)
          {
              std::vector<unsigned> aux_vector{shortest_path[curent_path]};
              aux_vector[aux_vector.size()-1] = lineColumnToindex(position_aux.i, position_aux.j-1);
              shortest_path.push_back(aux_vector);
          }else
          {
              shortest_path[curent_path].push_back(lineColumnToindex(position_aux.i, position_aux.j-1));
          }
      }
  }


  
}

unsigned Snake::find_path(unsigned pst)
{
    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == pst)
        {
            return i;
        }
    }
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