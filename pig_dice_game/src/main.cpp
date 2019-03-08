#include <iostream>
#include "../includes/dado.h"
#include "../includes/game.h"

int main()
{
    srand(time(NULL));
    int p1{0}, p2{0};
    //game();
    for(int i{0}; i < 10;i++)
    {
        game(p1, p2);
        std::cout << "===============" << std::endl;
    }
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    return 0;
}