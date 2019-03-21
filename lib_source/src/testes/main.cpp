#include <iostream>
#include <algorithm>  
#include <iterator>
#include "int_ranges.h"

int main(void)
{
    /*
    const int *teste;
    int A [] = {1, 2, -3, -4, 5, -6}; //teste min ; esperado = -6
    teste = min(&A[0], &A[6]);
    std::cout << *teste << "\n"; //ok
    */
    /*
    int A[] = {1, 2, 3, 4, 5}; // teste reverse
    reverse(&A[0], &A[4]); //ok
    for(auto c : A)
    {
        std::cout << c << " ";
    }
    
    int A[] = {1, 2, 3, 4, 5}; // teste reverse
    reverse(std::begin(A), std::end(A)); //ok
    for(auto c : A)
    {
        std::cout << c << " ";
    }
    */
    /*
    int Vet[] = {1, 2, -3, -4, 5, -6}; // teste multiplicao escalar ; passado 3, esperado { 3 , 6 , -9 , -12 , 15 , -18 }
    scalar_multiplication(&Vet[0], &Vet[6], 3);
    for(auto c : Vet)
    {
        std::cout << c << " ";
    }
    */
    /*
    int Vet[] = {1 , 3 , -5 , 4 , -2 , -1 }; // teste produto escalar, amdos os vetores estao em Vet, esperado 3
    int n{0};
    n = dot_product(&Vet[0], &Vet[3], &Vet[3]);
    std::cout << n << "\n";
    */
   /*
    int *teste;
    int Vet[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7}; // teste compact
    teste = compact(&Vet[0], &Vet[10]);
    for(auto c : Vet)
    {
        std::cout << c << " ";
    }
    std::cout << *teste <<std::endl;
    */
   /*
    int *teste;
    int A[] = { 1, 2, 3, 4, 5}, A_copy[] = {0, 0, 0, 0, 0}; // teste reverse
    teste = copy(&A[0], &A[6], &A_copy[0]); //ok
    for(auto c : A_copy)
    {
        std::cout << c << " ";
    }
    std::cout << *teste <<std::endl;
    */
   /*
    int A[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5}; // teste unique
    //int A[] = {1,2,1,3,2};
    auto teste = unique(std::begin(A), std::end(A)); //ok
    for(auto i : A)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    */
   /*
    int A[] = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    auto teste = sort_marbles(std::begin(A), std::end(A)); //ok
    for(auto c : A)
    {
        std::cout << c << " ";
    }
    std::cout << "\n";
    */
    int A[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
    partition(std::begin(A), std::end(A), std::begin(A)+1);
    for(auto c : A)
    {
        std::cout << c  << " ";
    }
    std::cout << "\n";
    return 0;
}