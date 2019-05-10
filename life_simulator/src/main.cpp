#include <iostream>
#include "../include/life.h"
#include "../include/life_simulator.h"
#include "../include/commun.h"

int main(int argc, char *argv[])
{
    //teste clase life ok:
    /*
    Life g{3,3};
    g.show_grid();
    g.gen_evulution();
    g.update_gen();
    std::cout << "\n";
    g.show_grid();
    g.gen_evulution();
    g.update_gen();
    std::cout << "\n";
    g.show_grid();
    std::cout << g.extinct() << "\n";
    */

   //teste class commun
   Commun configuration;
   configuration.load_confg(argc, argv);
   configuration.load_confg_grid();
   std::cout << configuration.cfg_grid.rows << "\n";
   std::cout << configuration.cfg_grid.columns << "\n";
   std::cout << configuration.cfg_grid.symbol_life << "\n";
    return 0;
}