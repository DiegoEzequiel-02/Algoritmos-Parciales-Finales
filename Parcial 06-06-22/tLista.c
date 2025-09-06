#include "tLista.h"

void crearLista(tLista* p){
    *p = NULL;
}

int insertarOrdenado(tLista* p, const void* d, unsigned cantBytes, int (*cmp)(const void*, const void*)){
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }

    while(*p && cmp(d,(*p)->info)>0)
        p = &(*p)->sig;

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

tNodo** buscarNivelEnLista(tLista* p, const void* d, int (*cmp)(const void*, const void*)){
    int rc;
    while(*p && (rc = cmp(d,(*p)->info))){
        p = &(*p)->sig;
    }

    if(!*p)
        return NULL;

    return (tNodo**)p;
}

void vaciarLista(tLista* p){
    while(*p){
        tNodo* aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
