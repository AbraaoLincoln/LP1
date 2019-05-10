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
   /*
   Commun configuration;
   configuration.load_glob_config(argc, argv);
   configuration.load_config_grid();
   std::cout << configuration.cfg_grid.rows << "\n";
   std::cout << configuration.cfg_grid.columns << "\n";
   std::cout << configuration.cfg_grid.symbol_life << "\n";
   */

    //teste life e commun
    /*
    Commun configuration;
    configuration.load_glob_config(argc, argv);
    Life g{configuration};
    g.show_grid();
    g.gen_evulution();
    g.update_gen();
    std::cout << "\n";
    g.show_grid();
    */
    Commun configuration;
    configuration.load_glob_config(argc, argv);
    Life_simulator slife{configuration};

    do
    {
        slife.m_life->show_grid();
        slife.m_life->gen_evulution();
        slife.m_life->update_gen();
        //slife.m_life->show_grid();
    }while(not slife.game_over());
    //slife.m_life->show_grid();
    return 0;
}