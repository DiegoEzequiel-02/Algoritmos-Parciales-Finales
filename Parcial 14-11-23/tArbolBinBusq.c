#include "tArbolBinBusq.h"

void crearArbolBinBusq(tArbolBinBusq* p){
    *p = NULL;
}

int insertarArbolRecBinBusq(tArbolBinBusq* p, const void* d, unsigned tam, int (*cmp)(const void*, const void*)){
    if(*p){
        int rc = cmp(d, (*p)->info);
        if(rc < 0)
            return insertarArbolRecBinBusq(&(*p)->izq,d,tam,cmp);
        else if(rc > 0)
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

void recorrerEnOrdenRecArbolBinBusq(tArbolBinBusq* p,unsigned n,void* params,void (*accion)(void*, unsigned, void*)){
    if(*p){
        recorrerEnOrdenRecArbolBinBusq(&(*p)->izq,n+1,params,accion);
        accion((*p)->info,(*p)->tamInfo,params);
        recorrerEnOrdenRecArbolBinBusq(&(*p)->der,n+1,params,accion);
    }
}

unsigned alturaArbolBin(tArbolBinBusq* p){
    if(!*p)
        return 0;

    int hi,hd;
    hi = alturaArbolBin(&(*p)->izq);
    hd = alturaArbolBin(&(*p)->der);
    return (hi > hd ? hi : hd)+1;
}

tNodoArbol** mayorNodoArbolBin(const tArbolBinBusq* p){
    if(!*p)
        return NULL;

    while((*p)->der)
        p = &(*p)->der;

    return (tNodoArbol**)p;
}

tNodoArbol** menorNodoArbolBin(const tArbolBinBusq* p){
    if(!*p)
        return NULL;

    while((*p)->izq)
        p = &(*p)->izq;

    return (tNodoArbol**)p;
}

int eliminarRaizArbolBinBusq(tArbolBinBusq* p){
    tNodoArbol** remp, *elim;

    if(!*p)
        return 0;

    free((*p)->info);
    if(!(*p)->izq && !(*p)->der){
        free(*p);
        *p = NULL;
        return 1;
    }

    remp = alturaArbolBin(&(*p)->izq) > alturaArbolBin(&(*p)->der) ? mayorNodoArbolBin(&(*p)->izq) : menorNodoArbolBin(&(*p)->der);

    elim = *remp;
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    *remp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}

void recorrerEnOrdenArbolBinBusq(tArbolBinBusq* p, void* params, void (*accion)(void*, unsigned, void*)){
    recorrerEnOrdenRecArbolBinBusq(p,0,params,accion);
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

void vaciarArbolBinBusq(tArbolBinBusq* p){
    if(!*p)
        return;

    vaciarArbolBinBusq(&(*p)->izq);
    vaciarArbolBinBusq(&(*p)->der);

    free((*p)->info);
    free(*p);
    *p = NULL;
}
