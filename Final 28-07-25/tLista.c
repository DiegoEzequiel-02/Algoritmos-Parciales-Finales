#include "tLista.h"

void crearLista(t_lista* p){
    *p = NULL;
}

int insertarOrdenadoTopN(t_lista* p, const void* d, unsigned cantBytes, int (*cmp)(const void*, const void*), int n){
    int cont = 0;
    t_lista* q = p;
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    while(*q && cmp(d,(*q)->info)<0){
        cont++;
        q = &(*q)->sig;
    }
    nue->sig = *q;
    *q = nue;
    cont++;

    while(*q && cont < n){
        cont++;
        q = &(*q)->sig;
    }

    if(*q){
        tNodo* aux = (*q)->sig;
        (*q)->sig = NULL;
        vaciarLista(&aux);
    }

    return 1;
}

void vaciarLista(t_lista* p){
    while(*p){
        tNodo* aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
