#include "snake.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

/**
 * construct da classe Snake
 * @param grid, vetor que contem o grid do jogo
 * @param rows, quantidade de linhas do grid
 * @param columns, quantidade de colunas do grid
 * @param snake, posicao inicial da snake no grid
 */
Snake::Snake(char * grid, unsigned & rows, unsigned & columns, Position & snake)
{
    m_grid = grid;
    m_rows = rows;
    m_columns = columns;
    m_snake_size = 1;
    snake_body.push(lineColumnToindex(snake.i, snake.j));
}

/**
 * update_grid
 * atualiza para o proximo level
 * @param newGrind, ponteiro para o novo grid(level)
 * @param rows, numoro de linhas do grid do novo level
 * @param columns, numoro de colunas do grid do novo level
 */
void Snake::update_grid(char * newGrid, Position & snake, unsigned & rows, unsigned & columns)
{
    m_grid = newGrid;
    m_rows = rows;
    m_columns = columns;
    m_snake_size = 1;
    snake_body.push(lineColumnToindex(snake.i, snake.j));
    
}

/**
 * find_solution
 * encontra o menor caminho ate a comida.
 * @param, snake = posicao da snake no grid
 * @param, food = posicao da comida no grid
 * @return, true se existir um caminho ate a comida, false caso contrario.
 */
bool Snake::find_solution(Position & snake, Position & food)
{
    Position position_aux{snake.i, snake.j}, position_aux2;
    unsigned count{0};
    std::vector<unsigned> aux_vector;
    distance = 0;

    //Inicializa o vector de vector    
    for(auto i{0u}; i < 4;i++)
    {
        std::vector<unsigned> aux(1,0);
        aux.push_back(lineColumnToindex(snake.i, snake.j)); //Inicializa cada caminho com a posicao inicial da snake.
        shortest_path.push_back(aux);
    }
    
    fila.push(snake);

    while(not fila.empty())
    {
        count = 0;
        position_aux = fila.front();
        fila.pop();
        unsigned curent_path = find_path(lineColumnToindex(position_aux.i, position_aux.j));
        simulate_snake(lineColumnToindex(position_aux.i, position_aux.j));

        for(auto i{0u}; i < 4;i++)
        {
            position_aux2 = position_aux;
            position_aux2 = update_position(position_aux2, i);
            
            if( not isTheBody(lineColumnToindex(position_aux2.i, position_aux2.j)) )
            {
                if((m_grid[lineColumnToindex(position_aux2.i, position_aux2.j)] != '#') and (visited.count(lineColumnToindex(position_aux2.i, position_aux2.j)) == 0))
                {
                    visited.insert(lineColumnToindex(position_aux2.i, position_aux2.j));
                    fila.push(position_aux2);
                    if(count > 0)
                    {
                        aux_vector = shortest_path[curent_path];
                        aux_vector[aux_vector.size()-1] = lineColumnToindex(position_aux2.i, position_aux2.j);
                        shortest_path.push_back(aux_vector);
                    }else
                    {
                        shortest_path[curent_path].push_back(lineColumnToindex(position_aux2.i, position_aux2.j));
                    }
                        
                    count++;
                }
            }
                
        }

        distance++;
        if(check_sides(position_aux)) 
        { 
            //render_path(food, 1);
            return true; 
        }       
    }

    return false;
}

/**
 * check_sides
 * verifica se a comida esta em um dos lados da snake.
 * @param snake = posicao da snake no grid
 * @return, true se um dos vizinhos da snake e a comida, false caso contrario.
 */
bool Snake::check_sides(Position & snake)
{
    if(m_grid[lineColumnToindex(snake.i-1, snake.j)] == 'f')
    {
        return true;
    }else if(m_grid[lineColumnToindex(snake.i, snake.j+1)] == 'f')
    {
        return true;
    }else if(m_grid[lineColumnToindex(snake.i+1, snake.j)] == 'f')
    {
        return true;
    }else if(m_grid[lineColumnToindex(snake.i, snake.j-1)] == 'f')
    {
        return true;
    }

    return false;
}

/**
 * find_path
 * encontra qual e o atual caminho sendo analisado
 * @param pst, posicao atual da snake
 * @return posicao do caminho sendo analisado
 */
unsigned Snake::find_path(unsigned pst)
{
    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == pst)
        {
            return i;
        }
    }

    return 0;
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

/**
 * render_path
 * marca no grid o caminho ate a comida
 * @param food, posicao da comida no grid
 */
void Snake::render_path(Position & food, short mode)
{
   unsigned food_index{lineColumnToindex(food.i, food.j)}, path{0};

    for(auto i{0u}; i < shortest_path.size(); i++)
        {
            if(shortest_path[i][shortest_path[i].size()-1] == food_index)
            {
                path = i;
                break;
            }
        }

   if(mode == 0)
   { 
        for(auto i{0u}; i < shortest_path[path].size(); i++)
        {
            m_grid[shortest_path[path][i]] =  'X';
        }

        m_grid[0] = '#';
   }else if(mode == 1)
   {
        auto start_render = shortest_path[path].size() - m_snake_size;
        for(auto i{start_render}; i < shortest_path[path].size(); i++)
        {
            m_grid[shortest_path[path][i]] =  'o';
        }
        m_grid[shortest_path[path][1]] =  ' ';
        m_grid[0] = '#';
   }else
   {
       for(auto i{0u}; i < kamikaze_path.size(); i++)
       {
           m_grid[kamikaze_path[i]] =  'X';
       }
   }    
}

/**
 * clear_path
 * limpa o caminho feito pela snake ate a comida.(coloca espacoes em branco no caminho)
 * @param food, posicao da comida no grid
 */
void Snake::clear_path(Position & food)
{
    unsigned food_index{lineColumnToindex(food.i, food.j)}, path{0};
    
    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == food_index)
        {
            path = i;
            break;
        }
    }

    for(auto i{0u}; i < shortest_path[path].size(); i++)
    {
        m_grid[shortest_path[path][i]] =  ' ';
    }
    //m_grid[shortest_path[path][shortest_path[path].size()-1]] =  '*';
}

/**
 * update_position
 * atualiza a posicao para um de seus vizinhos
 * @param snake posicao da snake no grid
 * @param next proxima posicao da snake
 * 0 = para cima
 * 1 = para direita
 * 2 = para baixo
 * 3 = para a esquerda
 * @return posicao atualizada
 */
Position Snake::update_position(Position & snake, short next)
{
    Position aux_pst{snake.i, snake.j};
    switch(next)
    {
        case 0:
            aux_pst.i -= 1;
            return aux_pst;
            break;
        case 1:
            aux_pst.j += 1;
            return aux_pst;
            break;
        case 2:
            aux_pst.i += 1;
            return aux_pst;
            break;
        case 3:
            aux_pst.j -= 1;
            return aux_pst;
            break;
        default:
            std::cerr << "Erro para calcular a proxima posicao!!!\n";
    }

    return aux_pst;
}

/**
 * update_body
 * simula o movimento da snake
 * @param end_pst, posicao final da snake no grid
 */
void Snake::simulate_snake(unsigned end_pst)
{
    unsigned path{0}, snake_body{0};

    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == end_pst)
        {
            path = i;
            break;
        }
    }
   
    
    if(shortest_path[path].size() >= m_snake_size)
    {
        if(distance == 0)
        {
            auto aux_body{this->snake_body};
            ghost_snake_body.clear();

            while(not aux_body.empty())
            {
                ghost_snake_body.push_back(aux_body.front());
                //std::cerr << aux_body.front() << " ";
                aux_body.pop();
            }
            //std::cerr << "\ndintance 0\n";
        }else
        {
            snake_body = shortest_path[path].size() - m_snake_size;
            ghost_snake_body.clear();

            for(auto i{snake_body}; i < shortest_path[path].size(); i++)
            {
                ghost_snake_body.push_back(shortest_path[path][i]);
            }
        }
        

    }else //else caso a snake seja maior que o caminho
    {

        ghost_snake_body.clear();
        auto aux_body{this->snake_body};

        for(auto i{m_snake_size - shortest_path[path].size()}; i < shortest_path[path].size();i++)
        {
            aux_body.pop();
        }

        while(not aux_body.empty())
        {
            ghost_snake_body.push_back(aux_body.front());
            aux_body.pop();
        }

        for(auto i{0u}; i < shortest_path[path].size(); i++)
        {
            ghost_snake_body.push_back(shortest_path[path][i]);
        }
    }
}

/**
 * isTheBody
 * verifica se o corpo da snake esta no caminho sendo analisado.
 * @param pst, posicao para onde a snake vai.
 */
bool Snake::isTheBody(unsigned pst)
{
    for(auto i{0u}; i < ghost_snake_body.size(); i++)
    {
        if(pst == ghost_snake_body[i])
        {
            return true;
        }
    }

    return false;
}

/**
 * reset
 * resetar tudo para as configuracoes iniciais.
 * @param Snake_spawn, posicao do spawn da snake
 * @param mode, mode execucao
 * 0 = reseta tudo
 * 1 = nao reseta o corpo da snake
 */
void Snake::reset(Position & snake_spawn, short mode)
{
    visited.clear();
    
    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        shortest_path[i].clear();
    }
    shortest_path.clear();

    while(not fila.empty())
    {
        fila.pop();
    }

    if(mode == 0)
    {
        while(not snake_body.empty())
        {
            snake_body.pop();
        }
        m_snake_size = 1;
           
    }else if(mode == 1)
    {
         while(not snake_body.empty())
        {
            snake_body.pop();
        }
        snake_body.push(lineColumnToindex(snake_spawn.i, snake_spawn.j)); //ja e add no metodo update_grid
        m_snake_size = 1;
    }
   
    kamikaze_path.clear();
}

/**
 * update_body
 * atualiza o tamanho do corpo da snake em 1
 */
void Snake::update_body(Position & food)
{
    unsigned path{0}, new_size{0};

    //Decidir onde vai ficar a nova parte da snake
    m_snake_size++;
    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == lineColumnToindex(food.i, food.j))
        {
            path = i;
            break;
        }
    }
    

    if(shortest_path[path].size() >= m_snake_size)
    {
        while(not snake_body.empty())
        {
            snake_body.pop();
        }
        
        new_size = shortest_path[path].size() - m_snake_size;
        for(auto i{new_size}; i < shortest_path[path].size(); i++)
        {
            snake_body.push(shortest_path[path][i]);
        }
    }

}
/**
 * snake_kamikaze
 * a snake se mata
 * @param snake, posicao da snake
 */
void Snake::snake_kamikaze(Position & snake)
{
    auto start{snake};

    while(m_grid[lineColumnToindex(start.i, start.j)] == ' ')
    {
        kamikaze_path.push_back(lineColumnToindex(start.i, start.j));
        start.j++;
    }
    kamikaze_path.push_back(lineColumnToindex(start.i, start.j));

}

/**
 * checks_body
 * verifica se a posicao passada esta ocupada pela snake
 * @param pst, posicao a ser testada
 * @return true caso a snake esteja na posicao, false caso contrario
 */
bool Snake::checks_body(unsigned pst)
{
    std::queue<unsigned> aux_tail{snake_body};
    
    while(not aux_tail.empty())
    {
        if(pst == aux_tail.front())
        {
            return true;
        }
        aux_tail.pop();
    }

    return false;
}

/**
 * get_snakeBody
 * @return retorna uma reference para o corpo da snake
 */

std::queue<unsigned>& Snake::get_snakeBody()
{
    return snake_body;
}
/**
 * get_shortestPath
 * @param sht_path indece o menor caminho
 * @param food, posicao da comida no grid
 * @return referencia para o vector que contem o menor caminho.
 */
std::vector<unsigned>& Snake::get_shortestPath(Position & food)
{
    unsigned path{0};

    for(auto i{0u}; i < shortest_path.size(); i++)
    {
        if(shortest_path[i][shortest_path[i].size()-1] == lineColumnToindex(food.i, food.j))
        {
            path = i;
            break;
        }
    }

    return shortest_path[path];
}