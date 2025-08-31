#include "tArbolBinBusq.h"

void crearArbolBinBusq(tArbolBinBusq* p){
    *p = NULL;
}

int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*)){
    if(*p){
        int rc = cmp(d,(*p)->info);
        if(rc < 0)
            return insertarArbolRecBinBusq(&(*p)->izq,d,tam,cmp);
        else if (rc > 0)
            return insertarArbolRecBinBusq(&(*p)->der,d,tam,cmp);
        else
            return 1;
    }
    tNodoArbol* nue = (tNodoArbol*)malloc(sizeof(tNodoArbol));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info){
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,tam);
    nue->der = nue->izq = NULL;
    nue->tamInfo = tam;
    *p = nue;
    return 1;
}

tNodoArbol** buscarNodoArbolBinBusq(const tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*)){
    int rc;
    while(*p && (rc = cmp(d,(*p)->info))){
        if(rc < 0)
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    if(!*p)
        return NULL;

    return (tNodoArbol**)p;
}

void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,void (*accion)(const void*)){
    if(*p){
        recorrerEnOrdenRecArbolBinBusq(&(*p)->izq,accion);
        accion((*p)->info);
        recorrerEnOrdenRecArbolBinBusq(&(*p)->der,accion);
    }
}

void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void (*accion)(const void*)){
    recorrerEnOrdenRecArbolBinBusq(p,accion);
}
