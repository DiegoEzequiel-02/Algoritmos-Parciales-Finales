#include "tPila.h"

void crearPila(tPila* p){
    *p = NULL;
}

int apilar(tPila* p, const void* d, unsigned cantBytes){
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->sig = *p;
    nue->tamInfo = cantBytes;
    *p = nue;
    return 1;
}

int desapilar (tPila* p, void* d, unsigned cantBytes){
    if(!*p)
        return;

    tNodo* aux = *p;
    *p = aux->sig;

    memcpy(d,aux->info,MIN(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);
    return 1;
}

int pilaLlena(tPila* p, unsigned cantBytes){
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    void* dato = malloc(cantBytes);

    free(nue);
    free(dato);

    return nue == NULL || dato == NULL;
}

int pilaVacia(tPila* p){
    return *p == NULL;
}

int vaciarPila(tPila *p){
    while(*p){
        tNodo* aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
