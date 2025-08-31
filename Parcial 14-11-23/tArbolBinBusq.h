#ifndef TARBOLBINBUSQ_H_INCLUDED
#define TARBOLBINBUSQ_H_INCLUDED
#include "tNodoArbol.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*));
void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,unsigned n,void* params,void (*accion)(void*, unsigned, void*));
unsigned alturaArbolBin(tArbolBinBusq* p);
tNodoArbol** mayorNodoArbolBin(const tArbolBinBusq* p);
tNodoArbol** menorNodoArbolBin(const tArbolBinBusq* p);
int eliminarRaizArbolBinBusq(tArbolBinBusq* p);
void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*, unsigned, void*));
tNodoArbol** buscarNodoArbolBinBusq(const tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*));
void vaciarArbolBinBusq(tArbolBinBusq* p);

#endif // TARBOLBINBUSQ_H_INCLUDED
