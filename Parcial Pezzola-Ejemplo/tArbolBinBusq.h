#include "tNodoArbol.h"

void crearArbolBinBusq(tArbolBinBusq* p);
int insertarRecArbolBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*));
void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*,void*));
void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*,void*));
void recorrerEnOrdenRecParaMateriasArbolBinBusq(tArbolBinBusq* p,tArbolBinBusq* pAux, void* params, void (*accion)(void*,void*, void*));
void recorrerEnOrdenParaMateriasArbolBinBusq(tArbolBinBusq* p, tArbolBinBusq* pAux,void* params, void (*accion)(void*,void*,void*));
tNodoArbol** buscarNodoArbolBinBusq(tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*));

void vaciarArbolBinBusq(tArbolBinBusq* p);

