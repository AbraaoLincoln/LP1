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

        return p_df;
    }

    //Funcao clone, cria um clone do intervalo passado
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //return, ponteiro para o inicio do clone
    void * clone ( const void * first , const void * last , size_t size )
    {
        byte *pf = (byte *)first;
        byte *pl = (byte *)last;
        int qtd{pl - pf};
        byte *pc;
        pc = new byte [(qtd*size)];
        byte *pr{pc};

        while(pf != last)
        {
            std::memcpy(pc, pf, size);
            pc += size;
            pf += size;
        }

        return pr;
    }

    //Funcao find_if, encontar o elemento que satisfa a condicao
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //return, ponteiro para o o primeiro elemento para o qual a funcao p retorne true e last se nenhum elemento satisfazer a condicao.
    const void * find_if ( const void * first , const void * last , size_t size , Predicate p )
    {
        byte *pf = (byte *)first;

        while(pf != last)
        {
            if(p(pf))
            {
                return pf;
            }
            pf += size;
        }

        return last;
    }

    //Funcao find, encontra o elemento que é igual ao valorpassado.
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //value, valor que sera procurado no intervalo.
        //eq, funcao de comparacao.
        //return, ponteiro para o elemento que e igual ao valor passado, se nao encontrar retorna last.
    const void *find ( const void * first , const void * last , size_t size , const void * value , Equal eq )
    {
        byte *pf = (byte *)first;

        while(pf != last)
        {
            //std::cout << (float)*pf << std::endl;
            if(eq(value, pf))
            {
                return pf;
            }
            pf += size;
        }

        return last;
    }
    //funcao all_of
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //return, true se todos os elementos retornar verdadeiro para p
    bool all_of ( const void * first , const void * last , size_t size , Predicate p )
    {
        byte *pf = (byte *)first;

        while(pf != last)
        {
            if(p(pf))
            {
                pf += size;
            }else
            {
                return false;
            }
            
        }

        return true;
    }

    //funcao any_of
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //return, true se pelo menos um elemento retornar verdadeiro para p
    bool any_of ( const void * first , const void * last , size_t size , Predicate p )
    {
        byte *pf = (byte *)first;

        while(pf != last)
        {
            if(p(pf))
            {
                return true;
            }else
            {
                pf += size;
            }
            
        }

        return false;
    }
    
    //funcao none_of
        //first, ponteiro para a primaira posicao do intervalo
        //last, ponteiro para a ultima posica mais um.
        //size, tamanho em bytes do tipo de dados do intervalo
        //return, true se nenhum dos elementoe retornar verdadeiro para p
    bool none_of ( const void * first , const void * last , size_t size , Predicate p )
    {
        byte *pf = (byte *)first;

        while(pf != last)
        {
            if(!p(pf))
            {
                pf += size;
            }else
            {
                return false;
            }
            
        }

        return true;
    }

    //Funcao equal
        //first, ponteiro para o prumeiro elemento do primero intervalo
        //last, ponteiro para o ultimo elemento mais um do primeiro intervalo
        //first2, ponteiro para o primeiro elemento do segundo intervalo
        //return, true se os intervalo sao iguais.
    bool equal(const void *first, const void *last, const void *first2, size_t size, Equal eq)
    {
        byte *pf = (byte *)first;
        byte *pf2 = (byte *)first2;

        while(pf != last)
        {
            if(!eq(pf, pf2))
            {
                return false;
            }
            pf += size;
            pf2 += size;
        }

        return true;
    }

    //Funcao equal
        //first, ponteiro para o prumeiro elemento do primero intervalo
        //last, ponteiro para o ultimo elemento mais um do primeiro intervalo
        //first2, ponteiro para o primeiro elemento do segundo intervalo
        //last2, ponteiro para o ultimo elemento mais um do segundo intervalo
        //return, true se os intervalo sao iguais, false caso contrario.
    bool equal(const void *first, const void *last, const void *first2, const void *last2, size_t size, Equal eq)
    {
        byte *pf = (byte *)first;
        byte *pf2 = (byte *)first2;

        while(pf != last)
        {
            if(!eq(pf, pf2))
            {
                return false;
            }
            pf += size;
            pf2 += size;
        }

        return true;
    }

    //Funcao unique
        //first, ponteiro para o primeiro elemento do intervalo
        //last, ponteiro para o ultimo elemento mais do intervalo
        //size, tamnho em bytes dos dados do intervalo
        //eq, funcao de comparacao
        //return, ponterio para o ultimo elemento mais do intervalo com elementos unicos
    void* unique( void *first , void *last , size_t size , Equal eq )
    {
        byte *pf = (byte *)first;
        byte *pl = (byte *)last;
        byte *aux, *pff{pf};
        unsigned qtd{(pl-pf)-size};
        pl = pff + qtd;

        for(auto i{pf}; i != pl;)
        {
            for(auto j{i + size}; j < pl;)
            {
                if(eq(i, j))
                {   
                    aux = j;
                    while(aux != pl)
                    {
                        swap(aux, aux+size, size);
                        aux += size;
                    }
                    qtd -= size;
                    pl = pff + qtd;
                }
                j += size;
            }
            i += size;
        }

        return pl;
    }
}

