#ifndef TARBOLBINBUSQ_H_INCLUDED
#define TARBOLBINBUSQ_H_INCLUDED
#include "tNodo.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*));
unsigned alturaArbolBin(tArbolBinBusq* p);
tNodoArbol** mayorNodoArbolBinBusq (tArbolBinBusq* p);
tNodoArbol** menorNodoArbolBinBusq (tArbolBinBusq* p);
int eliminarRaizArbolBinBusq(tArbolBinBusq* p);
void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,unsigned n,void* params,void (*accion)(void*));
void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*));
tNodoArbol** buscarNodoArbolBinBusq(tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*));
void vaciarArbolBinBusq(tArbolBinBusq* p);

#endif // TARBOLBINBUSQ_H_INCLUDED
