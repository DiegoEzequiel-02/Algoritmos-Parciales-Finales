#include "tNodoArbol.h"

void crearArbolBinBusq(tArbolBinBusq* p){
    *p = NULL;
}

int insertarRecArbolBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*)){
    if(*p){
        int rc = cmp(d,(*p)->info);
        if(rc < 0)
            return insertarRecArbolBinBusq(&(*p)->izq,d,tam,cmp);
        else if (rc > 0)
            return insertarRecArbolBinBusq(&(*p)->der,d,tam,cmp);
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

void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*,void*)){
    if(*p){
        recorrerEnOrdenRecArbolBinBusq(&(*p)->izq,params,accion);
        accion((*p)->info,params);
        recorrerEnOrdenRecArbolBinBusq(&(*p)->der,params,accion);
    }
}

void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*,void*)){
    recorrerEnOrdenRecArbolBinBusq(p,params,accion);
}

void recorrerEnOrdenRecParaMateriasArbolBinBusq(tArbolBinBusq* p,tArbolBinBusq* pAux, void* params, void (*accion)(void*,void*, void*)){
    if(*p){
        recorrerEnOrdenRecParaMateriasArbolBinBusq(&(*p)->izq,pAux,params,accion);
        accion((*p)->info,pAux,params);
        recorrerEnOrdenRecParaMateriasArbolBinBusq(&(*p)->der,pAux,params,accion);
    }
}

void recorrerEnOrdenParaMateriasArbolBinBusq(tArbolBinBusq* p, tArbolBinBusq* pAux,void* params, void (*accion)(void*,void*,void*)){
    recorrerEnOrdenRecParaMateriasArbolBinBusq(p,pAux,params,accion);
}

tNodoArbol** buscarNodoArbolBinBusq(tArbolBinBusq* p, const void* d, int (*cmp)(const void*, const void*)){
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

void vaciarArbolBinBusq(tArbolBinBusq* p){
    if(!*p)
        return;

    vaciarArbolBinBusq(&(*p)->izq);
    vaciarArbolBinBusq(&(*p)->der);

    free((*p)->info);
    free(*p);
    *p = NULL;
}
