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
        //std::map<std::string, std::string> cfg;
        //Confg_grid cfg_grid;
    public:
        std::map<std::string, std::string> cfg;
        //Confg_grid cfg_grid;
        void load_glob_config(int & argc, char *argv[]);
        void load_config_grid();
};

#endif