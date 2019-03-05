#include <iostream>
#include <sstream>

int getInteger(std::string msg_);

int main(void)
{
    auto n = getInteger("Forneca um inteiro:");
}

int getInteger(std::string msg_)
{
    int num;
    std::string str;
    do
    {
        std::cout << msg_ << std::endl;
        getline(std::cin, str);
        std::istringstream input(str);
        input >> num >> std::ws;

        if(input.fail() or !input.eof())
        {
            std::cout << "Erro!!!" << std::endl;
        }else
        {
            return num;
        }
        
    } while (true);
    
}