#include "../include/graal.h"
#include <iostream>
#include <cstring>

namespace graal{
    //Funcao swap, troca elementos de posicao na memoria.
        //x, ponterio para o primeiro elemento da troca.
        //y, ponteiro para o segundo elemento da troca.
        //size, tamanho em bytes dos elementos
        //nao tem retorno.
    void swap(void *x, void *y, size_t size)
    {
        byte *px = (byte *)x;
        byte *py = (byte *)y;
        byte aux[size];

        std::memcpy(aux, px, size);
        std::memcpy(px, py, size);
        std::memcpy(py, aux, size);
    }
    
    //Funcao min, retorna a posicao do menor elemento do intervalo
        //first, ponteiro para o primeiro elemento do intervalor.
        //last, ponteiro para o ultimo elemento mais um.
        //size, tamanho do tipo dos dados que estao no intervalo.
        //cmp, funcao de comparacao.
        //return, ponteiro para a posicao do menor elemento do intevalor.
    const void* min( const void *first , const void *last , size_t size , Compare cmp ){
        byte *pf = (byte *)first;
        byte *menor = (byte *)first;

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

    //Funcao reverse, inverte os elementos do intervalo.
        //first, ponteiro para o primeiro elemento do intervalo.
        //last, ponteiro para o ultimo elemento mais um.
        //size, tamanho do tipo dos dados que estao no intervalo.
        //return, nao tem retorno.
    void reverse(void *first, void *last, size_t size)
    {
        byte *pf = (byte *)first;
        byte *pff = (byte *)first;
        byte *pl = (byte *)last;
        int qtd{((pl - pf) / size) - 1};

        while(pf < pl)
        {
            pl = pff + (qtd * size);
            swap(pf, pl, size);
            pf += size;
            qtd--;
        }
    }

    //Funcao copy, copia todos os elemetos de um intervalo para outro intervalor.
        //first, ponteiro para o primeiro elemento do intervalo.
        //last, ponteiro para o ultimo elemento mais um.
        //d_first, ponterio para a primira posicao para onde a copia vai ser feita.
        //size, tamanho do tipo dos dados que estao no intervalo.
        //return, ponterio para a ultima posicao mais um do novo intervalo.
    void* copy(void *first, void *last, void *d_first,size_t size)
    {
        byte *pf = (byte *)first;
        byte *p_df = (byte *)d_first;

        while(pf != last)
        {
            std::memcpy(p_df, pf, size);
            pf += size;
            p_df += size;
        }

        return pf;
    }
}

