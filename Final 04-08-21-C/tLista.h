#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED
#include "tNodo.h"


void crearLista(tLista* p);
int insertarMejoresNLista(tLista* p, const void* d, unsigned cantBytes,int (*cmp)(const void*, const void*), int n);
void mapLista(tLista* p, void(*accion)(const void*));
void vaciarLista(tLista* p);

#endif // TLISTA_H_INCLUDED
