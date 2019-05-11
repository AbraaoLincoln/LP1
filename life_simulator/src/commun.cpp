#include "../include/commun.h"
#include "../include/lodepng.h"
#include <iostream>
#include <fstream>

/**
 * load_confg
 * carrega a configuração da simulação no dicionario cgf
 * @param argc, ponteiro para o argc do main, quantidade de parametros de configuração passado
 * @param argv[], ponteiro para o argv do main
 */
void Commun::load_glob_config(int & argc, char *argv[])
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

// Example 1
// Encode from raw pixels to disk with a single function call
// The image argument has width * height RGBA pixels or width * height * 4 bytes
void encode_png(const char* filename, const unsigned char * image, unsigned width, unsigned height)
{
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
