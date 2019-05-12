#include <iostream>
#include "../include/life.h"
#include "../include/life_simulator.h"
#include "../include/common.h"

int main(int argc, char *argv[])
{
    
    Common config;
    config.load_glob_config(argc, argv);
    Life_simulator slife{config};

    while(not slife.game_over())
    {
        slife.m_life->render_gen();
        slife.m_life->gen_evulution();
        slife.m_life->update_gen();
    }

    return 0;
}