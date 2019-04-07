#ifndef GRAAL_H
#define GRAAL_H

#include <cstring>
using byte = unsigned char;
using Compare = bool (*)(void *a, void *b);

namespace graal{

    void swap(void *x, void *y, size_t size);

    const void * min( const void *first , const void *last , size_t size , Compare cmp );  

    void reverse(void *first, void *last, size_t size);
      
}


#endif