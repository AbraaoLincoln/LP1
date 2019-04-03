#include <iostream>
#include "../include/dice.h"

//Gera a face do dado.
int dice::roll_dice(int n_faces)
{
    int face{0};
    face = rand() % n_faces + 1;
    return face;
}
//Calcula a probabilidade relativa de sair face 1.
float dice::prob_relt(int times)
{
    float prob{0};
    int count{0};

    for(int i{0}; i < times; i++)
    {
        if(roll_dice(6) == 1)
        {
            count++;
        }
    }

    prob = (float)count / (float)times;
    return prob;
}
//Calcula a probabilidade de sair face 1, na rodada atual.
float dice::prob_dice(int rolls)
{
    float count{0}, prob{0};

    for(int i{0}; i < 10;i++)
    {
        count += prob_relt(rolls);          
    }

    prob = count / 10;    
    return prob;
}
//Mostra no terminal a face do dado.
void dice::show_face(int face)
{
    switch(face)
    {
        case 1:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║       ║" << std::endl;
            std::cout << "║   ¤   ║" << std::endl;
            std::cout << "║       ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        case 2:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║ ¤     ║" << std::endl;
            std::cout << "║       ║" << std::endl;
            std::cout << "║     ¤ ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        case 3:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║ ¤     ║" << std::endl;
            std::cout << "║   ¤   ║" << std::endl;
            std::cout << "║     ¤ ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        case 4:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "║       ║" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        case 5:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "║   ¤   ║" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        case 6:
            std::cout << "╔═══════╗" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "║ ¤   ¤ ║" << std::endl;
            std::cout << "╚═══════╝" << std::endl;
            break;
        default:
            std::cout << "Valor invalido!" << std::endl;
    }
}