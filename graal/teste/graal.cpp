#include "../include/graal.h"
#include <cstring>

namespace graal{
    
    //Funcao min, retorna a posicao do menor elemento do intervalo
        //first, ponteiro para o primeiro elemento do intervalor.
        //last, ponteiro para o ultimo elemento mais um.
        //size, tamanho do tipo dos dados que estao no intervalo.
        //cmp, funcao de comparacao.
        //return, ponteiro para a posicao do menor elemento do intevalor.
    const void* min( const void *first , const void *last , size_t size , Compare cmp ){
        byte *pf = (byte *)first;
        byte *pl = (byte *)last;
        byte *menor;

        while(pf != last)
        {
            if(cmp(pf, menor))
            {
                menor = pf;
            }
            pf += size;
        }

        return menor;
    }
}

