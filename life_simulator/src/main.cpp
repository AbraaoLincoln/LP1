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
        slife.render_gen();
        slife.gen_evolution();
        slife.update_gen();
    }

    return 0;
}