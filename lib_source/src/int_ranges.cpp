#include <iostream>
#include <algorithm>  
#include <iterator>
#include "../include/int_ranges.h"

namespace ir {
    void negate( value_type * first, value_type * last )
    {
        while( first != last )
            *first++ *= -1;
    }

    const value_type * min( const value_type* first, const value_type* last )
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

    value_type * copy( const value_type * first_, const value_type *last_, value_type *d_first_ )
    {
        // TODO: place your code solution here!
        //value_type *d_last;
        while(first_ != last_)
        {
            *d_first_ = *first_;
            first_++;
            d_first_++;
        }
        return (int*)first_;
    }

    void reverse( value_type *first, value_type*last )
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

    value_type * rotate( value_type *first, value_type *n_first, value_type *last )
    {
        // TODO: place your code solution here!
        return nullptr;
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
        int size = (last - first)-1, value{0}, aux{0};
        int *first_local{first}, *last_local{first + size}, *first1{first};

        while(first != last_local)
        {
            value = *first;
            first_local++;

            for(auto i{first_local}; i < last_local;i++)
            {
                if(*i == value)
                {
                    std::swap(*i, *last_local);
                    //aux = *last_local;
                    //*last_local = *i;
                    //*i = aux;
                    size--;
                    last_local = first1 + size;
                }
            }
            first++;
            first_local = first;
        }
        return first;
    }

}
