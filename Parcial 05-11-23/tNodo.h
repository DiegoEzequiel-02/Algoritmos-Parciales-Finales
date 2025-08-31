#ifndef TNODO_H_INCLUDED
#define TNODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y)((x<y) ? (x):(y))

typedef struct sNodoArbol{
    unsigned tamInfo;
    void* info;
    struct sNodo* izq,*der;
}tNodoArbol;

typedef tNodoArbol* tArbolBinBusq;


#endif // TNODO_H_INCLUDED
