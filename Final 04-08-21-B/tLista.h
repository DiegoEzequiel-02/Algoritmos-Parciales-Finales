#ifndef TLISTA_H_INCLUDED
#define TLISTA_H_INCLUDED
#include "tNodo.h"

void crearLista(tLista* p);
void mapLista(tLista* p, void (*accion)(const void*));
int eliminarUltimosNdeLaLista(tLista* p, int n);
int insertarOrdenado(tLista* p, const void* d, unsigned cantBytes, int (*cmp)(const void*, const void*));
void vaciarLista(tLista* p);

#endif // TLISTA_H_INCLUDED
