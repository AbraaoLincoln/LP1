#include <iostream>
#include <algorithm>  
#include <iterator>
#include "int_ranges.h"

const int * min( const int* first, const int* last )
    {
        // TODO: place your code solution here!
        const int *smalest{first};

        while(first != last)
        {
            if(*first < *smalest)
            {
                smalest = first;
            }
            first++;
        }

        return smalest;
        
    }

    int * copy( const int * first_, const int *last_, int *d_first_ )
    {
        // TODO: place your code solution here!
        //value_type *d_last;
        while(first_ != last_)
        {
            *d_first_ = *first_;
            first_++;
            d_first_++;
        }
        return (int*)d_first_;
    }

    void reverse( int *first, int*last )
    {
        // TODO: place your code solution here!
        int size = (last - first)-1;
        int *new_last{first + size}, *new_first{first};
        while(new_first < new_last)
        {
            std::swap(*new_first, *new_last);
            new_first++;
            size--;
            new_last = first + size;
        }

    }

    // TODO: Place the rest of the implementation here.

    void scalar_multiplication( int * first , int * last , int scalar )
    {
        while(first != last)
        {
            *first *= scalar;
            first++;
        }
    }

    int dot_product ( const int * a_first , const int * a_last , const int * b_first )
    {
        int pro_vet{0};
        while (a_first != a_last)
        {
            pro_vet += *a_first * *b_first;
            a_first++;
            b_first++;
        }
         return pro_vet;
    }

    int* compact(int *first, int *last)
    {
        int value{0}, value_ne{0};
        int *first_in{first};

        while(first != last)
        {
            if(*first > 0)
            {
                value = *first;
                while(first_in != last)
                {
                    if(*first_in < 1)
                    {
                        value_ne = *first_in;
                        *first_in = value;
                        first_in++;
                        break;
                    }
                    first_in++;
                }
                *first = value_ne;
            }
            first++;
        }

        return first_in;
    }

    int * unique ( int * first , int * last )
    {
        int size = (last - first)-1, value{0};
        int *first_local{first}, *first1{first}, *x;
        last = first1 + size; 

       while(first != last)
       {
           value = *first;
           first_local++;
           for(auto i{first_local}; i < last;i++){
               if(*i == value)
               {
                   for(auto j{i}; j < last;j++)
                   {
                       x = j + 1;
                       std::swap(*j, *x);
                   }
                   size--;
                   last = first1 + size;
               }
           }
           first++;
           first_local = first;
       }

        return first;
    }

    int* sort_marbles( int * first , int * last )
    {
        while(first != last)
        {
            if(*first == 1)
            {
                for(auto i{first}; i < last; ++i)
                {
                    if(*i == 0)
                    {
                        std::swap(*i, *first);
                        break;
                    }
                }
            }
            first++;

        }
        return first;
    }

    void partition( int * first , int * last , int * pivot)
    {
        auto n = *pivot;
        int *iterator;
        while(first != last)
        {
            if(*first >= n)
            {
                for(auto i{first}; i < last; ++i)
                {
                    if(*i < n)
                    {
                        std::swap(*i, *first);
                        iterator = first;
                        break;
                    }
                }

            }
            first++;
        }
        iterator++;

        while(iterator != last)
        {
            if(*iterator > n)
            {
                for(auto i{iterator}; i < last; ++i)
                {
                    if(*i == n)
                    {
                        std::swap(*i, *iterator);
                        break;
                    }
                }
            }
            iterator++;
        }
    }

    void rotate( int * first , int * n_first , int * last )
    {
        auto qtd{n_first - first}, local_last{(last - first)-1};
        //std::cout << qtd << *first << *n_first << "\n";
        //std::cout << qtd << local_last << "\n";
        int *local_first{first}, *aux;

        for(auto i{0}; i < qtd;i++)
        {
            for(auto j{0}; j < local_last;j++)
            {
                aux = local_first + 1;
                std::cout << *local_first << *aux << "\n";
                std::swap(*local_first, *aux);
                local_first++;
            }
            local_first = first;
        }
    }