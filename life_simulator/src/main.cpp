#include <iostream>
#include "../include/life.h"
#include "../include/life_simulator.h"
#include "../include/commun.h"

int main(int argc, char *argv[])
{
    
    Commun config;
    config.load_glob_config(argc, argv);
    Life_simulator slife{config};

    do
    {
        slife.m_life->render_gen();
        slife.m_life->gen_evulution();
        slife.m_life->update_gen();
    }while(not slife.game_over());

    return 0;
}