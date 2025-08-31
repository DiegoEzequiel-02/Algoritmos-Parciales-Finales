#ifndef TNODOARBOL_H_INCLUDED
#define TNODOARBOL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MIN(x,y)((x<y) ? (x) : (y))

typedef struct sNodoArbol{
    unsigned tamInfo;
    void* info;
    struct sNodoArbol* der, *izq;
}tNodoArbol;

typedef tNodoArbol* tArbolBinBusq;

#endif // TNODOARBOL_H_INCLUDED
