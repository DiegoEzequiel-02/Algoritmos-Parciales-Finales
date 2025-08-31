#ifndef TARBOLBINBUSQ_H_INCLUDED
#define TARBOLBINBUSQ_H_INCLUDED
#include "tNodo.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarRecArbolBinBusq(tArbolBinBusq* p, void* d, unsigned tam, int (*cmp)(const void*, const void*));
tNodoArbol** buscarNodoNoClaveArbolBinBusq(tArbolBinBusq* p, void* d,int (*cmp)(const void*, const void*));
void recorrerPreOrdenRecArbolBinBusq(tArbolBinBusq* p, unsigned n,void* params, void(*accion)(void*, unsigned, unsigned, void*));
void recorrerPreOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void(*accion)(void*, unsigned, unsigned, void*));
void vaciarArbolBinBusq(tArbolBinBusq* p);
#endif // TARBOLBINBUSQ_H_INCLUDED
