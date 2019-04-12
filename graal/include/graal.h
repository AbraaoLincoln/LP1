#ifndef GRAAL_H
#define GRAAL_H

#include <cstring>
using byte = unsigned char;
using Compare = bool (*)(void *a, void *b);
using Predicate = bool (*)(void *a);
using Equal = bool (*)(const void *a, void *b);

namespace graal{

    void swap(void *x, void *y, size_t size);

    const void * min( const void *first , const void *last , size_t size , Compare cmp );  

    void reverse(void *first, void *last, size_t size);
    
    void* copy(void *first, void *last, void *d_first,size_t size);

    void * clone ( const void * first , const void * last , size_t size );

    const void * find_if ( const void * first , const void * last , size_t size , Predicate p );

    const void *find ( const void * first , const void * last , size_t size , const void * value , Equal eq );

    bool all_of ( const void * first , const void * last , size_t size , Predicate p );

    bool any_of ( const void * first , const void * last , size_t size , Predicate p );
    
    bool none_of ( const void * first , const void * last , size_t size , Predicate p );

    bool equal(const void *first, const void *last, const void *first2, size_t size, Equal eq);

    bool equal(const void *first, const void *last, const void *first2, const void *last2, size_t size, Equal eq);

    void* unique( void *first , void *last , size_t size , Equal eq );


}


#endif