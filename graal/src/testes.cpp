#include <iostream>
#include <iterator>
#include <iomanip>
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

int main(void)
{
    //Testes min.
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    std::cout << "Teste funcao min:" << std::endl;
    int A_int[]{1,2,3,4,5};
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
    std::cout << std::setw(20) << std::setfill('=') << "\n";
    return 0;
}