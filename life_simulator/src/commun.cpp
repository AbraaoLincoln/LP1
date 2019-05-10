#include "../include/commun.h"
#include <fstream>

/**
 * load_confg
 * carrega a configuração da simulação no dicionario cgf
 * @param argc, ponteiro para o argc do main, quantidade de parametros de configuração passado
 * @param argv[], ponteiro para o argv do main
 */
void Commun::load_confg(int & argc, char *argv[])
{
    for(auto i{1}; i < argc;i++)
	{
		if(argv[i][0] == '-')
		{
			cfg[argv[i]] = argv[i+1];
			i++;

		}else
		{
			cfg["arquivo_configuracao"] = argv[i];
		}
	}
}

/**
 * load_confg_grid
 * carrega as cofigurações do do grid
 */
void Commun::load_confg_grid()
{
    std::ifstream input;
    input.open(cfg["arquivo_configuracao"]);
    input >> cfg_grid.rows >> cfg_grid.columns >> cfg_grid.symbol_life;
}