#include "tLista.h"

void crearLista(tLista* p){
    *p = NULL;
}

int agregarAlFinal(tLista* p, const void* d, unsigned cantBytes){
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }

    while(*p)
        p = &(*p)->sig;

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *p = nue;
    return 1;
}

int sacarDelFrente(tLista* p, void* d, unsigned cantBytes){
    if(!*p)
        return 0;

    tNodo* aux = *p;
    *p = aux->sig;

    memcpy(d,aux->info,MIN(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);
    return 1;
}

int listaVacia(tLista* p){
    return *p == NULL;
}
