#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

void read_labels( std::vector<std::string>  & rotulos, std::string arq);
void read_values(std::vector<std::string> & values, std::string arq);
void print_head(std::vector<std::string>  & rotulos, std::vector<std::string> & value);

int main(int argc, char* argv[])
{
    std::vector<std::string> rotulos;
    std::vector<std::string> value;

    read_labels(rotulos, argv[1]);
    read_values(value, argv[2]);
    print_head(rotulos, value);
}

void read_labels( std::vector<std::string>  & rotulos, std::string arq)
{
    std::ifstream rots(arq.c_str());
    std::string rot;

    while(!rots.eof())
    {
        getline(rots, rot);
        rotulos.push_back(rot);
    }

    if( rots.fail() and !rots.eof())
    {
        std::cout << "Erro la leitura do arquivo: " << arq << std::endl;
    }
}

void read_values(std::vector<std::string> & values, std::string arq)
{
    std::ifstream vls(arq.c_str());
    std::string vl;

    while(vls >> vl)
    {
        values.push_back(vl);
    }

    if( vls.fail() and !vls.eof())
    {
        std::cout << "Erro la leitura do arquivo: " << arq << std::endl;
    }
}

void print_head(std::vector<std::string>  & rotulos, std::vector<std::string> & value)
{
    std::ostringstream line, head;

    for(int i{0}; i < rotulos.size(); i++)
    {
        line << "+" << std::setw(rotulos[i].size() + 3) << std::setfill('-');
        head << "| " << rotulos[i] << " ";
    }
    line << "+";
    head << "|";

    std::cout << line.str() << std::endl;
    std::cout << head.str() << std::endl;
    std::cout << line.str() << std::endl;

    for(int i{0}; i < value.size();)
    {
        for(int j{0}; j < rotulos.size(); j++)
        {
            std::cout << "|" << std::setw((rotulos[j].size() + 1) - value[i].size()) << std::setfill(' ');
            std::cout << value[i] << " ";
            i++;
        }

        std::cout << "|" << std::endl;   
    }
}