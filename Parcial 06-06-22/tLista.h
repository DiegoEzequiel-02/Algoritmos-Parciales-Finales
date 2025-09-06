#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED
#include "tNodo.h"

void crearLista(tLista* p);
int insertarOrdenado(tLista* p, const void* d, unsigned cantBytes, int (*cmp)(const void*, const void*));
tNodo** buscarNivelEnLista(tLista* p, const void* d, int (*cmp)(const void*, const void*));
void vaciarLista(tLista* p);

#endif // TLISTA_H_INCLUDED
