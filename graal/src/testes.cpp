#include <iostream>
#include <iterator>
#include <iomanip>
#include <assert.h>
#include "../include/graal.h"

void print_array(void *first, void *last, size_t sz)
{
    byte *pf = (byte *)first;
    size_t n{sz-1};
    
    while(pf != last)
    {
        std::cout << *pf << " ";
        pf += sz;
    }
    std::cout << "\n";
}

bool cmp_int(void *a, void *b)
{
    auto *pa = (int *)a;
    auto *pb = (int *)b;
    return *pa < *pb;
}

bool cmp_float(void *a, void *b)
{
    auto *pa = (float *)a;
    auto *pb = (float *)b;
    return *pa < *pb;
}
bool p_int(void *a)
{
    int *pa = (int *)a;
    return *pa < 6;
}

bool p_float(void *a)
{
    float *pa = (float *)a;
    return *pa < 100;
}

bool p_char(void *a)
{
    char *pa = (char *)a;
    return *pa < 'f';
}

bool eq_int(const void *a, void *b)
{
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa == *pb;
}

bool eq_float(const void *a, void *b)
{
    float *pa = (float *)a;
    float *pb = (float *)b;
    return *pa == *pb;
}

bool eq_char(const void *a, void *b)
{
    char *pa = (char *)a;
    char *pb = (char *)b;
    return *pa == *pb;
}

int main(void)
{
    //Testes min.
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    std::cout << "Teste funcao min:" << std::endl;
    int A_int[]{1,2,3,4,5};
    char A_char[]{'a','b','c','d'};
    //print_array(std::begin(A_int), std::end(A_int), sizeof(int));
    auto r1 = (int *) graal::min(std::begin(A_int), std::end(A_int), sizeof(int), cmp_int);
    std::cout << *r1 << std::endl;
    float A_float[]{1.1,-2.3,3,1.0,-10};
    auto r2 = (float *) graal::min(std::begin(A_float), std::end(A_float), sizeof(float), cmp_float);
    std::cout << *r2 << std::endl;
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    //Teste swap.
    std::cout << "Teste swap:" << std::endl;
    int a{1}, b{2};
    std::cout << "Antes: " << a << " , " << b << std::endl;
    graal::swap(&a, &b, sizeof(int));
    std::cout << "Depois: " << a << " , " << b << std::endl;
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    //Testes reverse.
        //teste com int
        std::cout << "Teste1 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_int), std::end(A_int), sizeof(int));
        std::cout << "\nDepois: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "Teste2 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_int)+1, std::begin(A_int)+4, sizeof(int));
        std::cout << "\nDepois: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        //teste com float
        std::cout << "Teste3 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_float), std::end(A_float), sizeof(float));
        std::cout << "\nDepois: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "Teste4 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_float)+1, std::begin(A_float)+4, sizeof(float));
        std::cout << "\nDepois: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        //teste com char
        std::cout << "Teste5 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_char), std::end(A_char), sizeof(char));
        std::cout << "\nDepois: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "Teste6 reverse:" << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        graal::reverse(std::begin(A_char)+1, std::begin(A_char)+3, sizeof(char));
        std::cout << "\nDepois: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    //teste copy
        //teste com int
        std::cout << "Teste copy com int: " << std::endl;
        int A_copy_int[5];
        std::cout << "Antes: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto it = graal::copy(std::begin(A_int), std::end(A_int), std::begin(A_copy_int), sizeof(int));
        std::cout << "Depois: ";
        for(auto c : A_copy_int)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        //teste com float
        //teste com char
    std::cout << std::setw(20) << std::setfill('=') << "\n";    
    //testes clone
    //std::cout << "Teste clone" << std::endl;
        //teste com int       
        std::cout << "Teste clone com int: " << std::endl;
        std::cout << "Antes: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto clone = (int*) graal::clone(std::begin(A_int), std::end(A_int), sizeof(int));
        std::cout << "Depois: ";
        for(auto i{clone}; *i != *(std::end(A_int)-1);i++)
        {
            std::cout << *i << " ";
        }
        delete[] clone;
        std::cout << "\n";
        std::cout << std::setw(20) << std::setfill('=') << "\n"; 
    //teste find_if
        //teste para int
        std::cout << "Teste find_if com int: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto find_0 = (int*) graal::find_if(std::begin(A_int), std::end(A_int), sizeof(int), p_int);
        std::cout << "Valores menor que 3 em A: " << *find_0 << std::endl;
        //teste para float
        std::cout << "Teste find_if com float: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto find_1 = (float*) graal::find_if(std::begin(A_float), std::end(A_float), sizeof(float), p_float);
        std::cout << "Valores maior que 1.9 em A: " << *find_1 << std::endl;
        //teste para char
        std::cout << "Teste find_if com char: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto find_2 = (char*) graal::find_if(std::begin(A_char), std::end(A_char), sizeof(char), p_char);
        std::cout << "Valores maior que c em A: " << *find_2 << std::endl;
        std::cout << std::setw(20) << std::setfill('=') << "\n";
    //teste find
        //teste para int
        std::cout << "Teste find com int: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_int)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto value_i = 2;
        auto find0 = (int*) graal::find(std::begin(A_int), std::end(A_int), sizeof(int), &value_i, eq_int);
        std::cout << "Valores iguais que 2 em A: " << *find0 << std::endl;
        assert(value_i == *find0);
        //teste para float
        std::cout << "Teste find com float: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_float)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        float value_f{1.1};
        auto find1 = (float*) graal::find(std::begin(A_float), std::end(A_float), sizeof(float), &value_f , eq_float);
        std::cout << "Valores iguais a 1.1 em A: " << *find1 << std::endl;
        assert(value_f == *find1);
        //teste com char
        std::cout << "Teste find com char: " << std::endl;
        std::cout << "A: ";
        for(auto c : A_char)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
        auto value_c{'a'};
        auto find2 = (char*) graal::find(std::begin(A_char), std::end(A_char), sizeof(char), &value_c, eq_char);
        std::cout << "Valores igual a a em A: " << *find2 << std::endl;
        assert(value_c == *find2);
        std::cout << std::setw(20) << std::setfill('=') << "\n";
    //testes all_of, any_of, none_of
        //teste all_of int
        auto all1 = graal::all_of(std::begin(A_int), std::end(A_int), sizeof(int), p_int);
        assert(all1==true);
        //teste all_of float
        auto all2 = graal::all_of(std::begin(A_float), std::end(A_float), sizeof(float), p_float);
        assert(all2==true);
        //teste all_of char
        auto all3 = graal::all_of(std::begin(A_char), std::end(A_char), sizeof(char), p_char);
        assert(all3==true);
    //teste any_of
        //teste para int
        auto any1 = graal::any_of(std::begin(A_int), std::end(A_int), sizeof(int), p_int);
        assert(any1==true);
        //teste para float
        auto any2 = graal::any_of(std::begin(A_float), std::end(A_float), sizeof(float), p_float);
        assert(any2==true);
        //teste para char
        auto any3 = graal::any_of(std::begin(A_char), std::end(A_char), sizeof(char), p_char);
        assert(any3==true);
    //teste none_of
        //teste para int
        auto none1 = graal::none_of(std::begin(A_int), std::end(A_int), sizeof(int), p_int);
        assert(none1==false);
        //teste para float
        auto none2 = graal::none_of(std::begin(A_float), std::end(A_float), sizeof(float), p_float);
        assert(none2==false);
        //teste para char
        auto none3 = graal::none_of(std::begin(A_char), std::end(A_char), sizeof(char), p_char);
        assert(none3==false);
    return 0;
}