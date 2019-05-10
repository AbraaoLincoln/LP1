#ifndef LIFE_SIMULATOR_H
#define LIFE_SIMULATOR_H

#include <map>
#include "../include/life.h"

struct Log{

};

class Life_simulator
{
    private:
        Life m_life;
        Log m_log_gen;
    public:
        Life_simulator();
        void start();
};

#endif