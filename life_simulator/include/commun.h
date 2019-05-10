#ifndef COMMUN_H
#define COMMUN_H

#include <map>

struct Confg_grid
{
    int rows, columns;
    char symbol_life;
    //std::string rules;
};

class Commun
{
    private:
        std::map<std::string, std::string> cfg;
        //Confg_grid cfg_grid;
    public:
        Confg_grid cfg_grid;
        void load_confg(int & argc, char *argv[]);
        void load_confg_grid();
};

#endif