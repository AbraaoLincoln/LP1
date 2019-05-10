#include <iostream>
#include "../include/life.h"

int main(void)
{
    Life g{3,3};
    g.show_grid();
    g.gen_evulution();
    g.render_gen();
    std::cout << "\n";
    g.show_grid();
    g.gen_evulution();
    g.render_gen();
    std::cout << "\n";
    g.show_grid();
    return 0;
}