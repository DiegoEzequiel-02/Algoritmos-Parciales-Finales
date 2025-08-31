#ifndef TARBOLBINBUSQ_H_INCLUDED
#define TARBOLBINBUSQ_H_INCLUDED
#include "tNodo.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*));
tNodoArbol** buscarNodoArbolBinBusq(tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*));
void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,void* params,void (*accion)(void*, void*));
void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void(*accion)(void*, void*));
void vaciarArbolBinBusq(tArbolBinBusq* p);
int eliminarRaizArbolBinBusq(tArbolBinBusq* p);
tNodoArbol** menorNodoArbolBin(tArbolBinBusq* p);
tNodoArbol** menorNodoArbolBin(tArbolBinBusq* p);
unsigned alturaArbolBin(tArbolBinBusq* p);

#endif // TARBOLBINBUSQ_H_INCLUDED
