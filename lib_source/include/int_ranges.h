#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
    using value_type = int;

    /// Negate all integer values in [first;last).
    void negate( value_type * first, value_type * last );

    /// Returns a pointer to the first occurrency of the smallest element the range.
    const value_type * min( const value_type *, const value_type * );

    /*!
     * \brief Copy the content of the range `[first;last)` to another range beginning at `d_first`.
     * \return An iterator point to the element past the last element copied from the source range.
     */
    value_type * copy( const value_type * , const value_type *, value_type* );


    /// Reverse the order of the elements in range `[first;last)`.
    void reverse( value_type *first, value_type*last );

    // TODO: Add the rest of the function prototypes here
    
    /// Multiplica todos os elementos do intervalo pelo scalar.
    void scalar_multiplication( int * first , int * last , int scalar );
	
    /// Multiplica os elementos que estao na mesma posição de dois intervalos.
    int dot_product ( const int * a_first , const int * a_last , const int * b_first );
    
    ///Move para o inicio do intervalor os valores que são positivos e não nulos.
    int* compact(int *first, int *last);

    ///Elimina as repetições do intervalo.
    int * unique ( int * first , int * last );
    
    ///Move todoas as peças pretas para o inicil do intervalo.
    int* sort_marbles( int * first , int * last );

    ///
    void partition( int * first , int * last , int * pivot);

    ///
    void rotate( int * first , int * n_first , int * last );
}
#endif
