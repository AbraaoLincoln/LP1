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
    visited.insert(lineColumnToindex(snake.i, snake.j));

    //teste body
    /*
    Position aux{snake.i+3, snake.j};
    snake_body.push(aux);
    aux.i = snake.i;
    aux.i += 2;
    snake_body.push(aux);
    aux.i = snake.i;
    aux.i += 1;
    snake_body.push(aux);
    */
    //snake_body.push(snake);
    //render_body(snake_body);
    /*
    Position aux{snake.i+1, snake.j+1};
    snake_body.push(aux);
    aux.i = snake.i;
    aux.j = snake.j;
    aux.i += 1;
    snake_body.push(aux);
    snake_body.push(snake);
    //render_body(snake_body);
    */
    m_aux_body = snake_body;
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
    unsigned count{0}, distance{0};

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
        
        for(auto i{0u}; i < 4;i++)
        {
            position_aux2 = position_aux;
            position_aux2 = update_position(position_aux2, i);

            if(distance > 0) { update_body(snake, snake_body, distance, i); }

            if( not isTheBody(lineColumnToindex(position_aux2.i, position_aux2.j), m_aux_body) )
            {
                if((m_grid[lineColumnToindex(position_aux2.i, position_aux2.j)] != '#') and (visited.count(lineColumnToindex(position_aux2.i, position_aux2.j)) == 0))
                {
                    visited.insert(lineColumnToindex(position_aux2.i, position_aux2.j));
                    fila.push(position_aux2);
                    if(count > 0)
                    {
                        std::vector<unsigned> aux_vector{shortest_path[curent_path]};
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
        if(check_sides(position_aux)) { break; }
    }

    render_path(food);
    return true;
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
 * 
 */
void Snake::render_path(Position & food)
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
        m_grid[shortest_path[path][i]] =  'X';
    }

    m_grid[0] = '#';
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
    switch(next)
    {
        case 0:
            snake.i -= 1;
            return snake;
            break;
        case 1:
            snake.j += 1;
            return snake;
            break;
        case 2:
            snake.i += 1;
            return snake;
            break;
        case 3:
            snake.j -= 1;
            return snake;
            break;
        default:
            std::cout << "Erro para calcular a proxima posicao!!!\n";
    }

    return snake;
}

/**
 * render_body
 * @param snake_body, fila que contem as posicoes do corpo da snake
 */
void Snake::render_body(std::queue<Position> & snake_body)
{
    std::queue<Position> aux{snake_body};
    Position aux_pst;

    while(not aux.empty())
    {
        aux_pst = aux.front();
        //m_grid[lineColumnToindex(aux_pst.i, aux_pst.j)] = '#';
        std::cerr << lineColumnToindex(aux_pst.i, aux_pst.j) << " ";
        aux.pop();
    }
    std::cerr << "\n";
}

/**
 * update_body
 */
void Snake::update_body(Position & snake, std::queue<Position> & snake_body, unsigned distance, short side)
{
    std::queue<Position> aux_body{snake_body};
    Position aux_head{snake.i, snake.j};

    switch(side)
    {
        case 0:
            //snake.i -= 1;
            for(auto i{0u}; i < distance; i++)
            {
                aux_head.i -= 1;
                aux_body.pop();
                aux_body.push(aux_head);
            }
            break;
        case 1:
            //snake.j += 1;
            for(auto i{0u}; i < distance; i++)
            {
                aux_head.j += 1;
                aux_body.pop();
                aux_body.push(aux_head);
            }
            break;
        case 2:
            //snake.i += 1;
            for(auto i{0u}; i < distance; i++)
            {
                aux_head.i += 1;
                aux_body.pop();
                aux_body.push(aux_head);
            }
            break;
        case 3:
            //snake.j -= 1;
            for(auto i{0u}; i < distance; i++)
            {
                aux_head.j -= 1;
                aux_body.pop();
                aux_body.push(aux_head);
            }
            break;
        default:
            std::cout << "Erro ao mover o corpo!!!\n";
    }

    m_aux_body = aux_body; 
}

/**
 * isTheBody
 */
bool Snake::isTheBody(unsigned pst, std::queue<Position> & snake_body)
{
    std::queue<Position> aux_body{snake_body};
    Position aux;

    while(not aux_body.empty())
    {
        aux = aux_body.front();
        if(lineColumnToindex(aux.i, aux.j) == pst)
        {
            return true;
        }
        aux_body.pop();
    }

    return false;
}