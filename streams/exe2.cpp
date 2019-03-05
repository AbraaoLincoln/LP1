#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<int> num;
    std::string arq;
    int n{0};

    std::cout << "Digite o nome do arquivo a ser lido: " << std::endl;
    std::cin >> arq;
    std::ifstream input(arq.c_str());

    while( input >> n )
    {
        num.push_back(n);           
    }
    std::ofstream rev("reverse.txt");
    for(int i{num.size() - 1} ; i >= 0 ; i-- )
    {
        rev << num[i] << "\n";
    }

    if( !input.eof() )
    {
        std::cout << "Erro na leitura do arquivo!!!" << std::endl;
    }
    return 0;
}