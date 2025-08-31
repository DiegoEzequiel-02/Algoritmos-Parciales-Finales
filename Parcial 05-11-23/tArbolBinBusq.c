#include "tArbolBinBusq.h"

void crearArbolBinBusq(tArbolBinBusq* p){
    *p = NULL;
}

int insertarRecArbolBinBusq(tArbolBinBusq* p, void* d, unsigned tam, int (*cmp)(const void*, const void*)){
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

tNodoArbol** buscarNodoNoClaveArbolBinBusq(tArbolBinBusq* p, void* d,int (*cmp)(const void*, const void*)){
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

void recorrerPreOrdenRecArbolBinBusq(tArbolBinBusq* p, unsigned n,void* params, void(*accion)(void*, unsigned, unsigned, void*)){
    if(!*p)
        return;

    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->izq,n+1,params,accion);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->der,n+1,params,accion);
}

void recorrerPreOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void(*accion)(void*, unsigned, unsigned, void*)){
    recorrerPreOrdenRecArbolBinBusq(p,0,params,accion);
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
