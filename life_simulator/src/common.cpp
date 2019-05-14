#include "../include/common.h"
#include "../include/lodepng.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * load_confg
 * carrega a configuração da simulação no dicionario cgf
 * @param argc, ponteiro para o argc do main, quantidade de parametros de configuração passado
 * @param argv[], ponteiro para o argv do main
 */
void Common::load_glob_config(int & argc, char *argv[])
{
    for(auto i{1}; i < argc;i++)
	{
		if(argv[i][0] == '-')
		{
			if(argv[i][1] == 'h' or argv[i][2] == 'h')
			{
				print_help();
			}else if(i+1 < argc) //evita segmentation fault
			{
				cfg[argv[i]] = argv[i+1];
				i++;
			}
			

		}else
		{
			cfg["arquivo_configuracao"] = argv[i];
		}
	}
}

/**
 * stringTOint
 * converte string para inteiro
 * @param s, uma string
 */
int stringTOint(std::string s)
{
	int n;
	std::istringstream conversion(s);
    conversion >> n;
	return n;	
}

/**
 * print_help
 * exibi no terminal a ajuda.
 */
void Common::print_help()
{
	std::cout << "Usage: glife [<options>] <input_cfg_file>\n";
	std::cout << "  Simulation options:\n";
	std::cout << "    --help" << "               Print this help text.\n";
	std::cout << "    --imgdir <path>" << "      Specify directory where output images are written to.\n";
	std::cout << "    --maxgen <num>" << "       Maximum number of generations to simulate.\n";
	std::cout << "    --fps <num>" << "          Number of generations presented per second.\n";
	std::cout << "    --blocksize <num>" << "    Pixel size of a cell. Default = 5.\n";
	std::cout << "    --bkgcolor <color>" << "   Color name for the background. Default GREEN.\n";
	std::cout << "    --alivecolor <color>" << " Color name for representing alive cells. Default RED.\n";
	std::cout << "    --outfile <filename>" << " Write the text representation of the simulation to the given filename.\n";
	std::cout << "\n\nAvailable colors are:\n";
	std::cout << "    BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n";
	std::cout << "    GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n";
	std::cout << "    WHITE YELLOW\n";
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
