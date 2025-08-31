#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED
#include "tNodo.h"

void crearLista(t_lista* p);
int insertarOrdenadoTopN(t_lista* p, const void* d, unsigned cantBytes, int (*cmp)(const void*, const void*), int n);
void vaciarLista(t_lista* p);

#endif // TLISTA_H_INCLUDED
