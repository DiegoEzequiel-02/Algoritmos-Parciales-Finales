#ifndef TNODO_H_INCLUDED
#define TNODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y)((x<y) ? (x):(y))

typedef struct sNodo{
    unsigned tamInfo;
    void* info;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;
#endif // TNODO_H_INCLUDED
