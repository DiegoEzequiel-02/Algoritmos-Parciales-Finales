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

    while(*p && cmp(d,(*p)->info)>0){
        p = &(*p)->sig;
    }

    memcpy(nue->info,d,cantBytes);
    nue->sig = *p;
    nue->tamInfo = cantBytes;
    *p = nue;
    return 1;
}

void mapLista(tLista* p, void (*accion)(const void*)){
    tNodo* aux = *p;
    while(aux){
        accion(aux->info);
        aux = aux->sig;
    }
}

int eliminarUltimosNdeLaLista(tLista* p, int n){
    int i;
    if (!*p || n <= 0)
        return 0;

    tNodo **pp = p;
    tNodo *pn = *p;

    for (i = 0; i < n; i++){
        if (!pn)
            return 0;
        pn = pn->sig;
    }

    while (pn)
    {
        pp = &(*pp)->sig;
        pn = pn->sig;
    }

    tNodo *elim = *pp;
    while (elim)
    {
        tNodo *sig = elim->sig;
        free(elim->info);
        free(elim);
        elim = sig;
    }
    *pp = NULL;

    return 1;
}

void vaciarLista(tLista* p){
    while(*p){
        tNodo* aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
