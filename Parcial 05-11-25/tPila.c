#include "tPila.h"

void crearPila(tPila* p){
    *p = NULL;
}

int apilar(tPila* p, void* d, unsigned cantBytes){
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
    *p = nue;
    nue->tamInfo = cantBytes;
    return 1;
}

int desapilar(tPila* p, void* d, unsigned cantBytes){
    tNodo* nue = *p;
    if(nue == NULL)
        return 0;

    *p = nue->sig;
    memcpy(d,nue->info,MIN(cantBytes,nue->tamInfo));

    free(nue->info);
    free(nue);
    return 1;
}

int pilaVacia(tPila* p){
    return *p == NULL;
}

int verTope(tPila* p, void* d, unsigned cantBytes){
    if(!*p)
        return 0;

    memcpy(d,(*p)->info,MIN(cantBytes,(*p)->tamInfo));
    return 1;
}
