#ifndef TARBOLBINBUSQ_H_INCLUDED
#define TARBOLBINBUSQ_H_INCLUDED
#include "tNodo.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*));
tNodoArbol** buscarNodoArbolBinBusq(const tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*));
void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,void (*accion)(const void*));
void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void (*accion)(const void*));

#endif // TARBOLBINBUSQ_H_INCLUDED
