#include <iostream>
#include <iterator>
#include <iomanip>
#include <assert.h>
#include "../include/graal.h"

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

bool cmp_char(void *a, void *b)
{
    auto *pa = (char *)a;
    auto *pb = (char *)b;
    return *pa < *pb;
}

bool p_int(void *a)
{
    int *pa = (int *)a;
    return *pa < 7;
}

bool p_float(void *a)
{
    float *pa = (float *)a;
    return *pa < 7;
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
        assert(it==std::end(A_copy_int));
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
    //teste equal
        //teste equal para int
        //para true
        int A1_equal[]{1,2,3,4}, A2_equal[]{1,2,3,4};
        auto rst_equal = graal::equal(std::begin(A1_equal), std::end(A1_equal), std::begin(A2_equal), sizeof(int), eq_int);
        assert(rst_equal==true);
        rst_equal = graal::equal(std::begin(A1_equal), std::end(A1_equal), std::begin(A2_equal), std::end(A2_equal),sizeof(int), eq_int);
        assert(rst_equal==true);
        //para false
        A1_equal[2] = 5;
        rst_equal = graal::equal(std::begin(A1_equal), std::end(A1_equal), std::begin(A2_equal), sizeof(int), eq_int);
        assert(rst_equal==false);
        rst_equal = graal::equal(std::begin(A1_equal), std::end(A1_equal), std::begin(A2_equal), std::end(A2_equal),sizeof(int), eq_int);
        assert(rst_equal==false);
        //teste para float
        //teste para true
        float A3_equal[]{1.7,2.5,3.4,4.3}, A4_equal[]{1.7,2.5,3.4,4.3};
        rst_equal = graal::equal(std::begin(A3_equal), std::end(A3_equal), std::begin(A4_equal), sizeof(float), eq_float);
        assert(rst_equal==true);
        rst_equal = graal::equal(std::begin(A3_equal), std::end(A3_equal), std::begin(A4_equal), std::end(A4_equal),sizeof(float), eq_float);
        assert(rst_equal==true);
        //teste para false
        A3_equal[3] = 2.4142;
        rst_equal = graal::equal(std::begin(A3_equal), std::end(A3_equal), std::begin(A4_equal), sizeof(float), eq_float);
        assert(rst_equal==false);
        rst_equal = graal::equal(std::begin(A3_equal), std::end(A3_equal), std::begin(A4_equal), std::end(A4_equal),sizeof(float), eq_float);
        assert(rst_equal==false);
        //teste para char
        //teste para true
        char A5_equal[]{'a','b','c','d'}, A6_equal[]{'a','b','c','d'};
        rst_equal = graal::equal(std::begin(A5_equal), std::end(A5_equal), std::begin(A6_equal), sizeof(char), eq_char);
        assert(rst_equal==true);
        rst_equal = graal::equal(std::begin(A5_equal), std::end(A5_equal), std::begin(A6_equal), std::end(A6_equal),sizeof(char), eq_char);
        assert(rst_equal==true);
        //teste para false
        A5_equal[1] = 'z';
        rst_equal = graal::equal(std::begin(A5_equal), std::end(A5_equal), std::begin(A6_equal), sizeof(char), eq_char);
        assert(rst_equal==false);
        rst_equal = graal::equal(std::begin(A5_equal), std::end(A5_equal), std::begin(A6_equal), std::end(A6_equal),sizeof(char), eq_char);
        assert(rst_equal==false);
    //teste para unique
        //teste para int
        int A_unique[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};
        int A_unique_exp[]{1,2,3,4,5};
        auto rst_unique = (int*) graal::unique(std::begin(A_unique), std::end(A_unique), sizeof(int), eq_int);
        auto a_{std::begin(A_unique_exp)};
        /*
        for(auto c : A_unique)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl; 
        */
        for(auto i{std::begin(A_unique)}; i != rst_unique; i++)
        {
            assert(*i == *a_);
            a_++;
        }
        //teste para float
        float A_uniquef[] = {1.3, 2.7, 1.3, 2.7, 3.4, 3.4, 1.3, 2.7, 4.2, 5.8, 3.4, 4.2, 5.8};
        float A_unique_expf[]{1.3,2.7,3.4,4.2,5.8};
        auto rst_uniquef = (float*) graal::unique(std::begin(A_uniquef), std::end(A_uniquef), sizeof(float), eq_float);
        auto a_f{std::begin(A_unique_expf)};
        for(auto i{std::begin(A_uniquef)}; i != rst_uniquef; i++)
        {
            assert(*i == *a_f);
            a_f++;
        }
        //teste para char
        char A_uniquec[] = {'a', 'b', 'a', 'b', 'c', 'c', 'a', 'b', 'd', 'e', 'c', 'd', 'e'};
        char A_unique_expc[]{'a','b','c','d','e'};
        auto rst_uniquec = (char*) graal::unique(std::begin(A_uniquec), std::end(A_uniquec), sizeof(char), eq_char);
        auto a_c{std::begin(A_unique_expc)};
        for(auto i{std::begin(A_uniquec)}; i != rst_uniquec; i++)
        {
            assert(*i == *a_c);
            a_c++;
        }
    //teste paratition
    std::cout << "Teste pattition" << std::endl;
        //teste para int
        int A1_partition[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
        //int A1_partition_exp[]{-5, -2, };
        auto rst_partititon = (int*) graal::partition(std::begin(A1_partition), std::end(A1_partition), sizeof(int), p_int);
        for(auto c : A1_partition)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        //teste para float
        float A2_partition[] = {-5.1, 7, 10.7, 7, 8.3, 9.6, 1.1, 7, -2.3, 3.5};
        //int A1_partition_exp[]{-5, -2, };
        auto rst_partititonf = (float*) graal::partition(std::begin(A2_partition), std::end(A2_partition), sizeof(float), p_float);
        for(auto c : A2_partition)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        assert(rst_partititonf==(std::begin(A2_partition)+4));
        //teste para char
        char A3_partition[] = {'e', 'f', 'm', 'f', 'o', 'g', 'a', 'f', 'd', 'c'};
        //int A1_partition_exp[]{-5, -2, };
        auto rst_partititonc = (char*) graal::partition(std::begin(A3_partition), std::end(A3_partition), sizeof(char), p_char);
        for(auto c : A3_partition)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        assert(rst_partititonc==(std::begin(A3_partition)+4));
        std::cout << std::setw(20) << std::setfill('=') << "\n";
    //teste qsort
        //teste para int
        int A1_sort[]{2,4,3,1,5};
        graal::qsort(std::begin(A1_sort), std::end(A1_sort), sizeof(int), cmp_int);
        for(auto c : A1_sort)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        //teste para float
        graal::qsort(std::begin(A2_partition), std::end(A2_partition), sizeof(float), cmp_float);
        for(auto c : A2_partition)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        //teste para char
        graal::qsort(std::begin(A3_partition), std::end(A3_partition), sizeof(char), cmp_char);
        for(auto c : A3_partition)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << std::setw(20) << std::setfill('=') << "\n";
    return 0;
}